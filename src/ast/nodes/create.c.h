#ifndef AST_NODES_CREATE_C_H
#define AST_NODES_CREATE_C_H

#include <stdlib.h>
#include "ast/nodes.h"

AST_Statements_t *AST_Statements(AST_Statements_t *statements, AST_Statement_t *statement)
{
    AST_Statements_t *stmts = (AST_Statements_t*) malloc(sizeof(AST_Statements_t));
    stmts->statements = statements;
    stmts->statement = statement;
    return stmts;
}

AST_Statement_t *AST_Statement_empty(int line_no) {
    AST_Statement_t *stmt = (AST_Statement_t*) malloc(sizeof(AST_Statement_t));
    stmt->type = STATEMENT_TYPE_EMPTY;
    stmt->statement.assignment = NULL;
    stmt->line_no = line_no;
    return stmt;
}

AST_Statement_t *AST_Statement_Assignment(AST_Assignment_t *assignment, int line_no)
{
    AST_Statement_t *stmt = (AST_Statement_t*) malloc(sizeof(AST_Statement_t));
    stmt->type = STATEMENT_TYPE_ASSIGNMENT;
    stmt->statement.assignment = assignment;
    stmt->line_no = line_no;
    return stmt;
}

AST_Statement_t *AST_Statement_CompoundSt(AST_CompoundSt_t *compound, int line_no)
{
    AST_Statement_t *stmt = (AST_Statement_t*) malloc(sizeof(AST_Statement_t));
    stmt->type = STATEMENT_TYPE_COMPOUND;
    stmt->statement.compound_statement = compound;
    stmt->line_no = line_no;
    return stmt;
}

AST_Assignment_t *AST_Assignment_create(AST_Identifier_t *identifier, AST_Expression_t *expression)
{
    AST_Assignment_t *assign = (AST_Assignment_t*) malloc(sizeof(AST_Assignment_t));
    assign->lhs = identifier;
    assign->rhs = expression;
    assign->type = ASSIGNMENT_TYPE_CREATE;
    return assign;
}

AST_Assignment_t *AST_Assignment_update(AST_Identifier_t *identifier, AST_Expression_t *expression)
{
    AST_Assignment_t *assign = (AST_Assignment_t*) malloc(sizeof(AST_Assignment_t));
    assign->lhs = identifier;
    assign->rhs = expression;
    assign->type = ASSIGNMENT_TYPE_UPDATE;
    return assign;
}

AST_Assignment_t *AST_Assignment_tovoid(AST_Expression_t *expression)
{
    AST_Assignment_t *assign = (AST_Assignment_t*) malloc(sizeof(AST_Assignment_t));
    assign->lhs = NULL;
    assign->rhs = expression;
    assign->type = ASSIGNMENT_TYPE_TOVOID;
    return assign;
}

AST_CompoundSt_t *AST_CompoundSt_IfBlock(AST_IfBlock_t *block)
{
    AST_CompoundSt_t *compound = (AST_CompoundSt_t*) malloc(sizeof(AST_CompoundSt_t));
    compound->type = COMPOUNDST_TYPE_IF;
    compound->compound_statement.if_block = block;
    return compound;
}

AST_CompoundSt_t *AST_CompoundSt_WhileBlock(AST_WhileBlock_t *block)
{
    AST_CompoundSt_t *compound = (AST_CompoundSt_t*) malloc(sizeof(AST_CompoundSt_t));
    compound->type = COMPOUNDST_TYPE_WHILE;
    compound->compound_statement.while_block = block;
    return compound;
}

AST_CompoundSt_t *AST_CompoundSt_ForBlock(AST_ForBlock_t *block)
{
    AST_CompoundSt_t *compound = (AST_CompoundSt_t*) malloc(sizeof(AST_CompoundSt_t));
    compound->type = COMPOUNDST_TYPE_FOR;
    compound->compound_statement.for_block = block;
    return compound;
}

AST_CompoundSt_t *AST_CompoundSt_Block(AST_Block_t *block)
{
    AST_CompoundSt_t *compound = (AST_CompoundSt_t*) malloc(sizeof(AST_CompoundSt_t));
    compound->type = COMPOUNDST_TYPE_BLOCK;
    compound->compound_statement.block = block;
    return compound;
}

AST_IfBlock_t *AST_IfBlock(AST_Condition_t *condition, AST_Statements_t *if_st, AST_ElseIfBlock_t *else_if_block, AST_Statements_t *else_st)
{
    AST_IfBlock_t *if_block = (AST_IfBlock_t*) malloc(sizeof(AST_IfBlock_t));
    if_block->condition = condition;
    if_block->if_st = if_st;
    if_block->else_if_block = else_if_block;
    if_block->else_st = else_st;
    return if_block;
}

AST_ElseIfBlock_t *AST_ElseIfBlock(AST_ElseIfBlock_t *else_if_block, AST_ElseIfSt_t *else_if_st)
{
    AST_ElseIfBlock_t *block = (AST_ElseIfBlock_t*) malloc(sizeof(AST_ElseIfBlock_t));
    block->else_if_block = else_if_block;
    block->else_if_st = else_if_st;
    return block;
}

AST_ElseIfSt_t *AST_ElseIfSt(AST_Condition_t *condition, AST_Statements_t *statements)
{
    AST_ElseIfSt_t *st = (AST_ElseIfSt_t*) malloc(sizeof(AST_ElseIfSt_t));
    st->condition = condition;
    st->statements = statements;
    return st;
}

AST_WhileBlock_t *AST_WhileBlock(AST_Condition_t *condition, AST_Statements_t *while_st)
{
    AST_WhileBlock_t *while_block = (AST_WhileBlock_t*) malloc(sizeof(AST_WhileBlock_t));
    while_block->condition = condition;
    while_block->statements = while_st;
    return while_block;
}

AST_ForBlock_t *AST_ForBlock(AST_Identifier_t *iter, AST_Operand_t *start, AST_Operand_t *end, AST_Operand_t *by, AST_Statements_t *for_st)
{
    AST_ForBlock_t *for_block = (AST_ForBlock_t*) malloc(sizeof(AST_ForBlock_t));
    for_block->iter = iter;
    for_block->iterable.range.start = start;
    for_block->iterable.range.end = end;
    for_block->iterable.range.by = by;
    for_block->statements = for_st;
    for_block->type = FORBLOCK_TYPE_RANGE;
    return for_block;
}

AST_ForBlock_t *AST_ForBlock_iterate(AST_Identifier_t *iter, AST_Operand_t *oprnd, AST_Statements_t *for_st)
{
    AST_ForBlock_t *for_block = (AST_ForBlock_t*) malloc(sizeof(AST_ForBlock_t));
    for_block->iter = iter;
    for_block->iterable.oprnd = oprnd;
    for_block->statements = for_st;
    for_block->type = FORBLOCK_TYPE_LIST;
    return for_block;
}

AST_Block_t *AST_Block(AST_Statements_t *statements)
{
    AST_Block_t *block = (AST_Block_t*) malloc(sizeof(AST_Block_t));
    block->statements = statements;
    return block;
}

#define AST_EXPRESSION_ISOPERAND(expr_) ({          \
    AST_Expression_t *expr = expr_;                 \
    expr && expr->op == TOKOP_NOP                   \
         && expr->lhs_type == EXPR_TYPE_OPERAND     \
         && expr->rhs_type == EXPR_TYPE_NULL        \
         && expr->condition_type == EXPR_TYPE_NULL; \
})

#define AST_EXPRESSION_ISCOMMALIST(expr_) ({        \
    AST_Expression_t *expr = expr_;                 \
    expr && expr->op == TOKOP_NOP                   \
         && expr->lhs_type == EXPR_TYPE_LIST        \
         && expr->rhs_type == EXPR_TYPE_NULL        \
         && expr->condition_type == EXPR_TYPE_NULL; \
})

AST_Expression_t *AST_Expression(AST_Operator_t op, AST_Expression_t *lhs, AST_Expression_t *rhs, AST_Expression_t *condition)
{
    AST_Expression_t *expression = (AST_Expression_t*) malloc(sizeof(AST_Expression_t));
    expression->op = op;

    if ( AST_EXPRESSION_ISOPERAND(lhs) || AST_EXPRESSION_ISCOMMALIST(lhs) ) {
        expression->lhs_type = lhs->lhs_type;
        expression->lhs = lhs->lhs;
        lhs->lhs.oprnd = NULL;
        lhs->lhs.lst = NULL;
        lhs->lhs_type = EXPR_TYPE_NULL;
        AST_Expression_free(&lhs);
    } else {
        expression->lhs_type = lhs ? EXPR_TYPE_EXPRESSION : EXPR_TYPE_NULL;
        expression->lhs.expr = lhs;
    }

    if ( AST_EXPRESSION_ISOPERAND(rhs) || AST_EXPRESSION_ISCOMMALIST(rhs) ) {
        expression->rhs_type = rhs->lhs_type;
        expression->rhs = rhs->lhs;
        rhs->lhs.oprnd = NULL;
        rhs->lhs.lst = NULL;
        rhs->lhs_type = EXPR_TYPE_NULL;
        AST_Expression_free(&rhs);
    } else {
        expression->rhs_type = rhs ? EXPR_TYPE_EXPRESSION : EXPR_TYPE_NULL;
        expression->rhs.expr = rhs;
    }

    if ( AST_EXPRESSION_ISOPERAND(condition) || AST_EXPRESSION_ISCOMMALIST(condition) ) {
        expression->condition_type = condition->lhs_type;
        expression->condition = condition->lhs;
        condition->lhs.oprnd = NULL;
        condition->lhs.lst = NULL;
        condition->lhs_type = EXPR_TYPE_NULL;
        AST_Expression_free(&condition);
    } else {
        expression->condition_type = condition ? EXPR_TYPE_EXPRESSION : EXPR_TYPE_NULL;
        expression->condition.expr = condition;
    }

    return expression;
}

AST_Expression_t *AST_Expression_Operand(AST_Operand_t *operand)
{
    AST_Expression_t *expression = (AST_Expression_t*) malloc(sizeof(AST_Expression_t));
    expression->op = TOKOP_NOP;
    expression->lhs_type = EXPR_TYPE_OPERAND;
    expression->lhs.oprnd = operand;
    expression->rhs_type = EXPR_TYPE_NULL;
    expression->rhs.expr = NULL;
    expression->condition_type = EXPR_TYPE_NULL;
    expression->condition.expr = NULL;
    return expression;
}

AST_Expression_t *AST_Expression_Identifier(AST_Identifier_t *identifier)
{
    AST_Expression_t *expression = (AST_Expression_t*) malloc(sizeof(AST_Expression_t));
    expression->op = TOKOP_NOP;
    expression->lhs_type = EXPR_TYPE_OPERAND;
    expression->lhs.oprnd = AST_Operand_Identifier(identifier);
    expression->rhs_type = EXPR_TYPE_NULL;
    expression->rhs.expr = NULL;
    expression->condition_type = EXPR_TYPE_NULL;
    expression->condition.expr = NULL;
    return expression;
}

AST_Expression_t *AST_Expression_CommaSepList(AST_CommaSepList_t *comma_list)
{
    AST_Expression_t *expression = (AST_Expression_t*) malloc(sizeof(AST_Expression_t));
    expression->op = TOKOP_NOP;
    expression->lhs_type = EXPR_TYPE_LIST;
    expression->lhs.lst = comma_list;
    expression->rhs_type = EXPR_TYPE_NULL;
    expression->rhs.expr = NULL;
    expression->condition_type = EXPR_TYPE_NULL;
    expression->condition.expr = NULL;
    return expression;
}

AST_CommaSepList_t *AST_CommaSepList(AST_CommaSepList_t *comma_list, AST_Expression_t *expression)
{
    AST_CommaSepList_t *comma_sep_list = (AST_CommaSepList_t*) malloc(sizeof(AST_CommaSepList_t));
    comma_sep_list->comma_list = comma_list;
    comma_sep_list->expression = expression;
    return comma_sep_list;
}

AST_Operand_t *AST_Operand_Literal(AST_Literal_t *literal)
{
    AST_Operand_t *operand = (AST_Operand_t*) malloc(sizeof(AST_Operand_t));
    operand->type = OPERAND_TYPE_LITERAL;
    operand->operand.literal = literal;
    return operand;
}

AST_Operand_t *AST_Operand_Identifier(AST_Identifier_t *identifier)
{
    AST_Operand_t *operand = (AST_Operand_t*) malloc(sizeof(AST_Operand_t));
    operand->type = OPERAND_TYPE_IDENTIFIER;
    operand->operand.variable = identifier;
    return operand;
}

AST_Literal_t *AST_Literal_bul(bool literal)
{
    AST_Literal_t *ast_literal = (AST_Literal_t*) malloc(sizeof(AST_Literal_t));
    ast_literal->type = DATA_TYPE_BUL;
    ast_literal->data.bul = literal;
    return ast_literal;
}

AST_Literal_t *AST_Literal_chr(char literal)
{
    AST_Literal_t *ast_literal = (AST_Literal_t*) malloc(sizeof(AST_Literal_t));
    ast_literal->type = DATA_TYPE_CHR;
    ast_literal->data.chr = literal;
    return ast_literal;
}

AST_Literal_t *AST_Literal_f64(double literal)
{
    AST_Literal_t *ast_literal = (AST_Literal_t*) malloc(sizeof(AST_Literal_t));
    ast_literal->type = DATA_TYPE_F64;
    ast_literal->data.f64 = literal;
    return ast_literal;
}

AST_Literal_t *AST_Literal_i64(int64_t literal)
{
    AST_Literal_t *ast_literal = (AST_Literal_t*) malloc(sizeof(AST_Literal_t));
    ast_literal->type = DATA_TYPE_I64;
    ast_literal->data.i64 = literal;
    return ast_literal;
}

AST_Literal_t *AST_Literal_str(char *literal)
{
    AST_Literal_t *ast_literal = (AST_Literal_t*) malloc(sizeof(AST_Literal_t));
    ast_literal->type = DATA_TYPE_STR;
    ast_literal->data.str = literal;
    return ast_literal;
}

AST_Literal_t *AST_Literal_interp_str(char *literal)
{
    AST_Literal_t *ast_literal = (AST_Literal_t*) malloc(sizeof(AST_Literal_t));
    ast_literal->type = DATA_TYPE_INTERP_STR;
    ast_literal->data.str = literal;
    return ast_literal;
}

AST_Literal_t *AST_Literal_lst(AST_CommaSepList_t *literal)
{
    AST_Literal_t *ast_literal = (AST_Literal_t*) malloc(sizeof(AST_Literal_t));
    ast_literal->type = DATA_TYPE_LST;
    ast_literal->data.lst = literal;
    return ast_literal;
}

AST_Identifier_t *AST_Identifier(char *identifier_name)
{
    AST_Identifier_t *identifier = (AST_Identifier_t*) malloc(sizeof(AST_Identifier_t));
    identifier->identifier_name = identifier_name;
    return identifier;
}

#else
    #warning re-inclusion of module 'ast/nodes/create.c.h'
#endif
