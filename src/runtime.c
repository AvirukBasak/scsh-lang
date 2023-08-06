#include <inttypes.h>
#include <stdbool.h>

#include "ast/api.h"
#include "runtime.h"
#include "runtime/data.h"
#include "runtime/data/list.h"
#include "runtime/data/string.h"
#include "runtime/io.h"
#include "runtime/util/evalstack.h"

#include "runtime/data.c.h"
#include "runtime/io.c.h"
#include "runtime/util/evalstack.c.h"
#include "runtime/vartable.c.h"

const char *rt_currfile = NULL;
int rt_currline = 0;

void RT_AST_eval(const AST_Statements_t *code);
RT_Data_t RT_Expression_eval(void);

void rt_exec(void)
{
    const AST_Identifier_t module = { .identifier_name = "main" };
    const AST_Identifier_t proc = { .identifier_name = "main" };
    const AST_Statements_t *code = AST_ProcedureMap_get_code(&module, &proc);
    rt_currfile = AST_ProcedureMap_get_filename(&module, &proc);
    RT_AST_eval(code);
}

void RT_AST_eval(const AST_Statements_t *code)
{
    /* push first statements */
    RT_EvalStack_push((const RT_StackEntry_t) {
        .entry.node.code = code,
        .type = STACKENTRY_ASTNODE_TYPE_STATEMENTS
    });
    while (!RT_EvalStack_isempty()) {
        RT_StackEntry_t pop = RT_EvalStack_pop();
        switch (pop.type) {
            case STACKENTRY_ASTNODE_TYPE_STATEMENTS: {
                const AST_Statements_t *st = pop.entry.node.code;
                if (!st) break;
                /* push next entry to eval */
                RT_EvalStack_push((const RT_StackEntry_t) {
                    .entry.node.statement = st->statement,
                    .type = STACKENTRY_ASTNODE_TYPE_STATEMENT
                });
                /* push next entry */
                RT_EvalStack_push((const RT_StackEntry_t) {
                    .entry.node.code = st->statements,
                    .type = STACKENTRY_ASTNODE_TYPE_STATEMENTS
                });
                break;
            }
            case STACKENTRY_ASTNODE_TYPE_STATEMENT: {
                const AST_Statement_t *st = pop.entry.node.statement;
                if (!st) break;
                rt_currline = st->line_no;
                switch (st->type) {
                    case STATEMENT_TYPE_EMPTY: break;
                    case STATEMENT_TYPE_RETURN: {
                        RT_EvalStack_push((const RT_StackEntry_t) {
                            .entry.node.expression = st->statement.expression,
                            .type = STACKENTRY_ASTNODE_TYPE_EXPRESSION
                        });
                        RT_VarTable_update("-", RT_Expression_eval());
                        break;
                    }
                    case STATEMENT_TYPE_ASSIGNMENT: {
                        RT_EvalStack_push((const RT_StackEntry_t) {
                            .entry.node.assignment = st->statement.assignment,
                            .type = STACKENTRY_ASTNODE_TYPE_ASSIGNMENT
                        });
                        break;
                    }
                    case STATEMENT_TYPE_COMPOUND: {
                        const AST_CompoundSt_t *cmpd = st->statement.compound_statement;
                        RT_VarTable_push_scope();
                        RT_EvalStack_push((const RT_StackEntry_t) {
                            .entry.node.code = NULL,
                            .type = STACKENTRY_TYPE_PROC_POP
                        });
                        switch (cmpd->type) {
                            case COMPOUNDST_TYPE_IF: {
                                RT_EvalStack_push((const RT_StackEntry_t) {
                                    .entry.node.if_block = cmpd->compound_statement.if_block,
                                    .type = STACKENTRY_ASTNODE_TYPE_IF_BLOCK
                                });
                                break;
                            }
                            case COMPOUNDST_TYPE_WHILE: {
                                RT_EvalStack_push((const RT_StackEntry_t) {
                                    .entry.node.while_block = cmpd->compound_statement.while_block,
                                    .type = STACKENTRY_ASTNODE_TYPE_WHILE_BLOCK
                                });
                                break;
                            }
                            case COMPOUNDST_TYPE_FOR: {
                                RT_EvalStack_push((const RT_StackEntry_t) {
                                    .entry.state.lp.for_block = cmpd->compound_statement.for_block,
                                    .entry.state.lp.i = 0,
                                    .entry.state.lp.is_running = false,
                                    .type = STACKENTRY_ASTNODE_TYPE_FOR_BLOCK
                                });
                                break;
                            }
                            case COMPOUNDST_TYPE_BLOCK: {
                                const AST_Statements_t *st = cmpd->compound_statement.block->statements;
                                RT_EvalStack_push((const RT_StackEntry_t) {
                                    .entry.node.code = st,
                                    .type = STACKENTRY_ASTNODE_TYPE_STATEMENTS
                                });
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
            case STACKENTRY_ASTNODE_TYPE_ASSIGNMENT: {
                switch (pop.entry.node.assignment->type) {
                    case ASSIGNMENT_TYPE_TOVOID: {
                        RT_EvalStack_push((const RT_StackEntry_t) {
                            .entry.node.expression = pop.entry.node.assignment->rhs,
                            .type = STACKENTRY_ASTNODE_TYPE_EXPRESSION
                        });
                        RT_VarTable_update("-", RT_Expression_eval());
                        break;
                    }
                    case ASSIGNMENT_TYPE_CREATE: {
                        const char *idf = pop.entry.node.assignment->lhs->identifier_name;
                        RT_EvalStack_push((const RT_StackEntry_t) {
                            .entry.node.expression = pop.entry.node.assignment->rhs,
                            .type = STACKENTRY_ASTNODE_TYPE_EXPRESSION
                        });
                        RT_VarTable_create(idf, RT_Expression_eval());
                        break;
                    }
                }
                break;
            }
            case STACKENTRY_ASTNODE_TYPE_IF_BLOCK: {
                RT_EvalStack_push((const RT_StackEntry_t) {
                    .entry.node.expression = pop.entry.node.if_block->condition,
                    .type = STACKENTRY_ASTNODE_TYPE_EXPRESSION
                });
                bool cond =  RT_Data_tobool(RT_Expression_eval());
                if (cond) {
                    RT_EvalStack_push((const RT_StackEntry_t) {
                        .entry.node.code = pop.entry.node.if_block->if_st,
                        .type = STACKENTRY_ASTNODE_TYPE_STATEMENTS
                    });
                    break;
                } else {
                    RT_EvalStack_push((const RT_StackEntry_t) {
                        .entry.node.else_block = pop.entry.node.if_block->else_block,
                        .type = STACKENTRY_ASTNODE_TYPE_ELSE_BLOCK
                    });
                    break;
                }
                break;
            }
            case STACKENTRY_ASTNODE_TYPE_ELSE_BLOCK: {
                /* takes care of [ else nwp statements end ] */
                if (!pop.entry.node.else_block->condition && !pop.entry.node.else_block->else_block) {
                    RT_EvalStack_push((const RT_StackEntry_t) {
                        .entry.node.code = pop.entry.node.else_block->else_if_st,
                        .type = STACKENTRY_ASTNODE_TYPE_STATEMENTS
                    });
                    break;
                }
                /* takes care of [ else if condition then nwp statements ] */
                RT_EvalStack_push((const RT_StackEntry_t) {
                    .entry.node.expression = pop.entry.node.else_block->condition,
                    .type = STACKENTRY_ASTNODE_TYPE_EXPRESSION
                });
                bool cond = RT_Data_tobool(RT_Expression_eval());
                if (cond) {
                    /* if condition true, execute statements and don't go
                       any further down the else if ladder */
                    RT_EvalStack_push((const RT_StackEntry_t) {
                        .entry.node.code = pop.entry.node.else_block->else_if_st,
                        .type = STACKENTRY_ASTNODE_TYPE_STATEMENTS
                    });
                    break;
                } else {
                    /* if condition failed and no more else if blocks,
                       just break out and do nothing */
                    if (!pop.entry.node.else_block->else_block) break;
                    RT_EvalStack_push((const RT_StackEntry_t) {
                        .entry.node.else_block = pop.entry.node.else_block->else_block,
                        .type = STACKENTRY_ASTNODE_TYPE_ELSE_BLOCK
                    });
                    break;
                }
                break;
            }
            case STACKENTRY_ASTNODE_TYPE_WHILE_BLOCK: {
                RT_EvalStack_push((const RT_StackEntry_t) {
                    .entry.node.expression = pop.entry.node.while_block->condition,
                    .type = STACKENTRY_ASTNODE_TYPE_EXPRESSION
                });
                bool cond = RT_Data_tobool(RT_Expression_eval());
                /* if condition is true, don't let the while be removed from stack
                   i.e. push it back into the stack coz it was popped earlier */
                if (cond) RT_EvalStack_push(pop);
                RT_EvalStack_push((const RT_StackEntry_t) {
                    .entry.node.code = pop.entry.node.while_block->statements,
                    .type = STACKENTRY_ASTNODE_TYPE_STATEMENTS
                });
                break;
            }
            case STACKENTRY_ASTNODE_TYPE_FOR_BLOCK: {
                switch (pop.entry.node.for_block->type) {
                    case FORBLOCK_TYPE_RANGE: {
                        /* if loop not running, start it and eval range */
                        if (!pop.entry.state.lp.is_running) {
                            /* calculate start, end and by */
                            RT_EvalStack_push((const RT_StackEntry_t) {
                                .entry.node.expression = pop.entry.node.for_block->iterable.range.start,
                                .type = STACKENTRY_ASTNODE_TYPE_EXPRESSION
                            });
                            RT_Data_t start = RT_Expression_eval();
                            if (start.type != RT_DATA_TYPE_I64)
                                rt_throw("for loop range start should be an i64");
                            RT_EvalStack_push((const RT_StackEntry_t) {
                                .entry.node.expression = pop.entry.node.for_block->iterable.range.end,
                                .type = STACKENTRY_ASTNODE_TYPE_EXPRESSION
                            });
                            RT_Data_t end = RT_Expression_eval();
                            if (end.type != RT_DATA_TYPE_I64)
                                rt_throw("for loop range end should be an i64");
                            RT_Data_t by = RT_Data_null();
                            if (pop.entry.node.for_block->iterable.range.by) {
                                RT_EvalStack_push((const RT_StackEntry_t) {
                                    .entry.node.expression = pop.entry.node.for_block->iterable.range.by,
                                    .type = STACKENTRY_ASTNODE_TYPE_EXPRESSION
                                });
                                by = RT_Expression_eval();
                                if (by.type != RT_DATA_TYPE_I64)
                                    rt_throw("for loop by value should be an i64");
                            }
                            const int64_t start_i = start.data.i64;
                            const int64_t end_i = end.data.i64;
                            const int64_t by_i = RT_Data_isnull(by) ?
                                (start_i <= end_i ? +1 : -1) : by.data.i64;
                            if (!by_i) rt_throw("for loop by value cannot be 0");
                            if ( (start_i < end_i && by_i < 0) || (start_i > end_i && by_i > 0) )
                                rt_throw("possible infinite for loop for by value '%" PRId64 "'", by_i);
                            /* add loop info to for loop stack entry */
                            pop.entry.state.lp.it.range.start = start_i;
                            pop.entry.state.lp.it.range.end = end_i;
                            pop.entry.state.lp.it.range.by = by_i;
                            /* set i to start of range */
                            pop.entry.state.lp.i = start_i;
                            /* start loop */
                            pop.entry.state.lp.is_running = true;
                        }
                        else pop.entry.state.lp.i += pop.entry.state.lp.it.range.by;
                        if ( (pop.entry.state.lp.it.range.by > 0 && pop.entry.state.lp.i >= pop.entry.state.lp.it.range.end)
                          || (pop.entry.state.lp.it.range.by < 0 && pop.entry.state.lp.i <= pop.entry.state.lp.it.range.end) ) {
                            pop.entry.state.lp.is_running = false;
                            break;
                        }
                        /* break, i.e. don't push new loop state */
                        if (!pop.entry.state.lp.is_running) break;
                        RT_VarTable_create(pop.entry.node.for_block->iter->identifier_name,
                            RT_Data_i64(pop.entry.state.lp.i));
                        /* push newly modified loop state */
                        RT_EvalStack_push(pop);
                        RT_EvalStack_push((const RT_StackEntry_t) {
                            .entry.node.code = pop.entry.node.for_block->statements,
                            .type = STACKENTRY_ASTNODE_TYPE_STATEMENTS
                        });
                        break;
                    }
                    case FORBLOCK_TYPE_LIST: {
                        /* if loop not running, start it and eval list */
                        if (!pop.entry.state.lp.is_running) {
                            /* convert expression to a data list */
                            RT_EvalStack_push((const RT_StackEntry_t) {
                                .entry.node.expression = pop.entry.node.for_block->iterable.lst,
                                .type = STACKENTRY_ASTNODE_TYPE_EXPRESSION
                            });
                            RT_Data_t data = RT_Expression_eval();
                            switch (data.type) {
                                case RT_DATA_TYPE_LST:
                                    pop.entry.state.lp.it.iter.type = RT_DATA_TYPE_LST;
                                    pop.entry.state.lp.it.iter.lst = data.data.lst;
                                    break;
                                case RT_DATA_TYPE_STR:
                                    pop.entry.state.lp.it.iter.type = RT_DATA_TYPE_STR;
                                    pop.entry.state.lp.it.iter.str = data.data.str;
                                    break;
                                default:
                                    rt_throw("unsupported data type in iterator type for loop");
                            }
                            pop.entry.state.lp.i = 0;
                            pop.entry.state.lp.is_running = true;
                        }
                        else pop.entry.state.lp.i += 1;
                        /* calc lis length */
                        int64_t length = 0;
                        switch (pop.entry.state.lp.it.iter.type) {
                            case RT_DATA_TYPE_LST:
                                length = RT_DataList_length(pop.entry.state.lp.it.iter.lst);
                                break;
                            case RT_DATA_TYPE_STR:
                                length = RT_DataStr_length(pop.entry.state.lp.it.iter.str);
                                break;
                            default:
                                rt_throw("unsupported data type in iterator type for loop");
                        }
                        /* stop loop */
                        if (pop.entry.state.lp.i >= length) {
                            /* destroy list if rc is 0 */
                            switch (pop.entry.state.lp.it.iter.type) {
                                case RT_DATA_TYPE_LST:
                                    if (pop.entry.state.lp.it.iter.lst->rc == 0)
                                        RT_DataList_destroy(&pop.entry.state.lp.it.iter.lst);
                                    break;
                                case RT_DATA_TYPE_STR:
                                    if (pop.entry.state.lp.it.iter.str->rc == 0)
                                        RT_DataStr_destroy(&pop.entry.state.lp.it.iter.str);
                                    break;
                                default:
                                    rt_throw("unsupported data type in iterator type for loop");
                            }
                            pop.entry.state.lp.is_running = false;
                            break;
                        }
                        /* break, i.e. don't push new loop state */
                        if (!pop.entry.state.lp.is_running) break;
                        /* store current iteration element in loop variable */
                        switch (pop.entry.state.lp.it.iter.type) {
                            case RT_DATA_TYPE_LST: RT_VarTable_create(pop.entry.node.for_block->iter->identifier_name,
                                    RT_DataList_get(pop.entry.state.lp.it.iter.lst, pop.entry.state.lp.i)
                                );
                                break;
                            case RT_DATA_TYPE_STR: RT_VarTable_create(pop.entry.node.for_block->iter->identifier_name,
                                    RT_Data_chr(RT_DataStr_get(pop.entry.state.lp.it.iter.str, pop.entry.state.lp.i))
                                );
                                break;
                            default:
                                rt_throw("unsupported data type in iterator type for loop");
                        }
                        /* push newly modified loop state */
                        RT_EvalStack_push(pop);
                        RT_EvalStack_push((const RT_StackEntry_t) {
                            .entry.node.code = pop.entry.node.for_block->statements,
                            .type = STACKENTRY_ASTNODE_TYPE_STATEMENTS
                        });
                        break;
                    }
                }
                break;
            }
            case STACKENTRY_ASTNODE_TYPE_EXPRESSION: {
                RT_EvalStack_push((const RT_StackEntry_t) {
                    .entry.node.expression = pop.entry.node.expression,
                    .type = STACKENTRY_ASTNODE_TYPE_EXPRESSION
                });
                RT_Expression_eval();
                break;
            }
            case STACKENTRY_TYPE_SCOPE_POP: {
                RT_VarTable_pop_scope();
                break;
            }
            case STACKENTRY_ASTNODE_TYPE_COMMA_SEP_LIST:
            case STACKENTRY_ASTNODE_TYPE_LITERAL:
            case STACKENTRY_ASTNODE_TYPE_IDENTIFIER:
            case STACKENTRY_STATES_TYPE_LOOP:
            case STACKENTRY_STATES_TYPE_EXPR:
            case STACKENTRY_TYPE_ASTNODE:
            case STACKENTRY_TYPE_STATE:
            case STACKENTRY_TYPE_PROC_POP: break;
        }
    }
}

RT_Data_t RT_Expression_eval(void)
{
    if (RT_EvalStack_isempty()) {
        rt_throw("RT_Expression_eval: stack underflow");
        return RT_Data_null();
    } else if (RT_EvalStack_top().type != STACKENTRY_ASTNODE_TYPE_EXPRESSION) {
        rt_throw("RT_Expression_eval: no expression at stack top");
        return RT_Data_null();
    }
    /* set accumulator to null */
    RT_VarTable_update("-", RT_Data_null());
    /* dfs the expression tree and evaluate */
    while (RT_EvalStack_top().type == STACKENTRY_ASTNODE_TYPE_EXPRESSION) {
        RT_StackEntry_t pop = RT_EvalStack_pop();
        /* pop.entry.state.xp = (union RT_StackEntry_States_t) {
            pop.entry.node.expression->op,
            pop.entry.node.expression->lhs,
            pop.entry.node.expression->rhs,
            pop.entry.node.expression->condition
        };
        switch (expr.op) {
            case LEXTOK_BANG:
            case LEXTOK_LOGICAL_UNEQUAL:
            case LEXTOK_PERCENT:
            case LEXTOK_MODULO_ASSIGN:
            case LEXTOK_AMPERSAND:
            case LEXTOK_LOGICAL_AND:
            case LEXTOK_LOGICAL_AND_ASSIGN:
            case LEXTOK_BITWISE_AND_ASSIGN:
            case LEXTOK_ASTERIX:
            case LEXTOK_EXPONENT:
            case LEXTOK_EXPONENT_ASSIGN:
            case LEXTOK_MULTIPLY_ASSIGN:
            case LEXTOK_PLUS:
            case LEXTOK_INCREMENT:
            case LEXTOK_ADD_ASSIGN:
            case LEXTOK_MINUS:
            case LEXTOK_DECREMENT:
            case LEXTOK_SUBSTRACT_ASSIGN:
            case LEXTOK_DOT:
            case LEXTOK_FSLASH:
            case LEXTOK_FLOOR_DIVIDE:
            case LEXTOK_FLOOR_DIVIDE_ASSIGN:
            case LEXTOK_DIVIDE_ASSIGN:
            case LEXTOK_DCOLON:
            case LEXTOK_LBRACE_ANGULAR:
            case LEXTOK_BITWISE_LSHIFT:
            case LEXTOK_BITWISE_LSHIFT_ASSIGN:
            case LEXTOK_LOGICAL_LESSER_EQUAL:
            case LEXTOK_ASSIGN:
            case LEXTOK_LOGICAL_EQUAL:
            case LEXTOK_RBRACE_ANGULAR:
            case LEXTOK_LOGICAL_GREATER_EQUAL:
            case LEXTOK_BITWISE_RSHIFT:
            case LEXTOK_BITWISE_RSHIFT_ASSIGN:
            case LEXTOK_ARITH_RSHIFT:
            case LEXTOK_ARITH_RSHIFT_ASSIGN:
            case LEXTOK_CARET:
            case LEXTOK_BITWISE_XOR_ASSIGN:
            case LEXTOK_PIPE:
            case LEXTOK_BITWISE_OR_ASSIGN:
            case LEXTOK_LOGICAL_OR:
            case LEXTOK_LOGICAL_OR_ASSIGN:
            case LEXTOK_TILDE:
            case TOKOP_NOP: {
                switch (expr->lhs_type) {
                    case EXPR_TYPE_LITERAL:
                        return RT_Data_Literal(expr->lhs.literal);
                    case EXPR_TYPE_IDENTIFIER:
                        return RT_VarTable_get(expr->lhs.identifier->identifier_name);
                    default: rt_throw("RT_Expression_eval: invalid `lhs_type` for NOP");
                }
            }
            case TOKOP_FNCALL:
            case TOKOP_INDEXING:
            case TOKOP_TERNARY_COND:
            case TOKOP_FNARGS_INDEXING: break;
        } */
    }
    return RT_VarTable_get("-");
}
