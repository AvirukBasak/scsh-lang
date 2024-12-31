#ifndef RT_OP_DOT_C_H
#define RT_OP_DOT_C_H

#include "runtime/data/BoxedData.h"
#include "runtime/data/Data.h"
#include "runtime/data/DataMap.h"
#include "runtime/io.h"
#include "runtime/operators.h"
#include "runtime/VarTable.h"

void rt_op_dot(const rt_Data_t *lhs, const rt_Data_t *rhs)
{
    if (lhs->type != rt_DATA_TYPE_MAP)
        rt_throw("cannot apply membership on type '%s'", rt_Data_typename(*lhs));
    switch (lhs->type) {
        case rt_DATA_TYPE_MAP: {
            if (!rhs)
                rt_throw("invalid member name");
            char *key = rt_Data_tostr(*rhs);
            rt_Data_t *ref = rt_DataMap_getref(lhs->data.mp, key);
            if (ref && ref->type == rt_DATA_TYPE_PROC) {
                /* The lhs is boxed and copied to heap before setting context object.
                   This is done coz lhs may not be a ref to a map or list and may infact
                   be ref to a popped call stack frame. To do so, original context is
                   destroyed first. */
                rt_BoxedData_destroy(&ref->data.proc.context);
                ref->data.proc.context = rt_BoxedData_from(*lhs);
                rt_BoxedData_increfc(ref->data.proc.context);
            } else if (ref && ref->type == rt_DATA_TYPE_LAMBDA) {
                /* The lhs is boxed and copied to heap before setting context object.
                   This is done coz lhs may not be a ref to a map or list and may infact
                   be ref to a popped call stack frame. To do so, original context is
                   destroyed first. */
                rt_BoxedData_destroy(&ref->data.lambda.context);
                ref->data.lambda.context = rt_BoxedData_from(*lhs);
                rt_BoxedData_increfc(ref->data.lambda.context);
            }
            rt_VarTable_acc_setadr(ref);
            free(key);
            break;
        }
        case rt_DATA_TYPE_BUL:
        case rt_DATA_TYPE_CHR:
        case rt_DATA_TYPE_I64:
        case rt_DATA_TYPE_F64:
        case rt_DATA_TYPE_INTERP_STR:
        case rt_DATA_TYPE_ANY:
        case rt_DATA_TYPE_STR:
        case rt_DATA_TYPE_LST:
        case rt_DATA_TYPE_PROC:
        case rt_DATA_TYPE_LAMBDA:
        case rt_DATA_TYPE_LIBHANDLE:
            rt_throw("cannot apply membership on type '%s'", rt_Data_typename(*lhs));
    }
}

#else
    #warning re-inclusion of module 'runtime/operators/dot.c.h'
#endif
