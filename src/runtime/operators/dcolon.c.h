#ifndef RT_OP_DCOLON_C_H
#define RT_OP_DCOLON_C_H

#include "ast.h"
#include "ast/api.h"
#include "ast/util/ModuleAndProcTable.h"
#include "runtime/data/Data.h"
#include "runtime/data/DataMap.h"
#include "runtime/io.h"
#include "runtime/operators.h"
#include "runtime/VarTable.h"

void rt_op_dcolon(const ast_Expression_t *expr)
{
    if (expr->lhs_type != EXPR_TYPE_IDENTIFIER
        || expr->rhs_type != EXPR_TYPE_IDENTIFIER)
            rt_throw("invalid use of module membership operator");
    /* check if the module exists */
    if (!ast_util_ModuleAndProcTable_hasmodule(expr->lhs.variable))
        rt_throw("undefined module '%s'", expr->lhs.variable);
    /* instead of evaluating the LHS and RHS, directly generate a
       procedure type literal and return it via accumulator */
    rt_VarTable_acc_setval(rt_Data_proc(
        expr->lhs.variable,
        expr->rhs.variable
    ));
}

#else
    #warning re-inclusion of module 'runtime/operators/dcolon.c.h'
#endif
