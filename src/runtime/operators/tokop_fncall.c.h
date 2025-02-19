#ifndef RT_OP_TOKOP_FNCALL_C_H
#define RT_OP_TOKOP_FNCALL_C_H

#include "ast.h"
#include "ast/api.h"
#include "io.h"
#include "runtime.h"
#include "runtime/data/Data.h"
#include "runtime/data/BoxedData.h"
#include "runtime/data/DataList.h"
#include "runtime/eval.h"
#include "runtime/functions.h"
#include "runtime/io.h"
#include "runtime/operators.h"
#include "runtime/VarTable.h"

void rt_op_fncall(const rt_Data_t *lhs, const rt_Data_t *rhs) {
    if (lhs->type != rt_DATA_TYPE_PROC && lhs->type != rt_DATA_TYPE_LAMBDA)
        rt_throw("cannot make procedure call to type '%s'", rt_Data_typename(*lhs));
    /** temporary data variable for rhs */
    rt_Data_t rhs_;
    if (!rhs) {
        rhs_ = rt_Data_list(rt_DataList_init());
        rhs = &rhs_;
    }
    rt_Data_assert_type(*rhs, rt_DATA_TYPE_LST, "procedure argument");

    /* context for lambda or procedure */
    rt_Data_t context = rt_Data_null();

    if (lhs->type == rt_DATA_TYPE_LAMBDA && lhs->data.lambda.context) {
        context = *lhs->data.lambda.context->data;
    } else if (lhs->type == rt_DATA_TYPE_PROC && lhs->data.proc.context) {
        context = *lhs->data.proc.context->data;
    }

    /* call the lambda or */
    if (lhs->type == rt_DATA_TYPE_LAMBDA) rt_fn_lambda_call_handler(
        context,
        lhs->data.lambda,
        rhs->data.lst
    );
    /* call the procedure */
    else rt_fn_call_handler(
        context,
        lhs->data.proc.module_name,
        lhs->data.proc.proc_name,
        rhs->data.lst
    );
    /* set no data to accumulator as data is already set by procedure called above
       return early to prevent accumulator being modified by some other code */
    return;
}

#else
    #warning re-inclusion of module 'runtime/operators/tokop_fncall.c.h'
#endif
