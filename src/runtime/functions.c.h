#include <inttypes.h>
#include <string.h>

#include "ast.h"
#include "ast/api.h"
#include "io.h"
#include "runtime/data/Data.h"
#include "runtime/eval.h"
#include "runtime/functions.h"
#include "runtime/io.h"

rt_fn_FunctionDescriptor_t rt_fn_FunctionsList_getfn(const char *module, const char *fname)
{
    /* if module matched but procedure didn't match, it should cascade down.
       this is done so that if all matches fail, you can still match the procedures
       that don't have a module name */
    if (!strcmp(module, "dbg")) {
        if (!strcmp(fname, "typename")) return rt_fn_DBG_TYPENAME;
        if (!strcmp(fname, "refcnt"))   return rt_fn_DBG_REFCNT;
        if (!strcmp(fname, "id"))       return rt_fn_DBG_ID;
        if (!strcmp(fname, "callproc")) return rt_fn_DBG_CALLPROC;
    }
    if (!strcmp(module, "io")) {
        if (!strcmp(fname, "print"))    return rt_fn_IO_PRINT;
        if (!strcmp(fname, "input"))    return rt_fn_IO_INPUT;
    }
    if (!strcmp(module, "it")) {
        if (!strcmp(fname, "len"))      return rt_fn_IT_LEN;
    }
    if (!strcmp(module, "str")) {
        if (!strcmp(fname, "equals"))   return rt_fn_STR_EQUALS;
        if (!strcmp(fname, "compare"))  return rt_fn_STR_COMPARE;
        if (!strcmp(fname, "append"))   return rt_fn_STR_APPEND;
        if (!strcmp(fname, "insert"))   return rt_fn_STR_INSERT;
        if (!strcmp(fname, "erase"))    return rt_fn_STR_ERASE;
        if (!strcmp(fname, "concat"))   return rt_fn_STR_CONCAT;
        if (!strcmp(fname, "reverse"))  return rt_fn_STR_REVERSE;
        if (!strcmp(fname, "substr"))   return rt_fn_STR_SUBSTR;
        if (!strcmp(fname, "find"))     return rt_fn_STR_FIND;
        if (!strcmp(fname, "split"))    return rt_fn_STR_SPLIT;
        if (!strcmp(fname, "toi64"))    return rt_fn_STR_TOI64;
        if (!strcmp(fname, "tof64"))    return rt_fn_STR_TOF64;
        if (!strcmp(fname, "sort"))     return rt_fn_STR_SORT;
    }
    if (!strcmp(module, "lst")) {
        if (!strcmp(fname, "equals"))   return rt_fn_LST_EQUALS;
        if (!strcmp(fname, "compare"))  return rt_fn_LST_COMPARE;
        if (!strcmp(fname, "append"))   return rt_fn_LST_APPEND;
        if (!strcmp(fname, "insert"))   return rt_fn_LST_INSERT;
        if (!strcmp(fname, "erase"))    return rt_fn_LST_ERASE;
        if (!strcmp(fname, "concat"))   return rt_fn_LST_CONCAT;
        if (!strcmp(fname, "reverse"))  return rt_fn_LST_REVERSE;
        if (!strcmp(fname, "find"))     return rt_fn_LST_FIND;
        if (!strcmp(fname, "sublist"))  return rt_fn_LST_SUBLIST;
        if (!strcmp(fname, "join"))     return rt_fn_LST_JOIN;
        if (!strcmp(fname, "sort"))     return rt_fn_LST_SORT;
    }

    if (!strcmp(fname, "isnull"))       return rt_fn_ISNULL;
    if (!strcmp(fname, "tostr"))        return rt_fn_TOSTR;
    if (!strcmp(fname, "type"))         return rt_fn_TYPE;

    return rt_fn_UNDEFINED;
}

#include "runtime/functions/module_chr.c.h"
#include "runtime/functions/module_dbg.c.h"
#include "runtime/functions/module_f64.c.h"
#include "runtime/functions/module_i64.c.h"
#include "runtime/functions/module_io.c.h"
#include "runtime/functions/module_it.c.h"
#include "runtime/functions/module_lst.c.h"
#include "runtime/functions/module_map.c.h"
#include "runtime/functions/module_str.c.h"
#include "runtime/functions/nomodule.c.h"

rt_Data_t rt_fn_FunctionsList_call(rt_fn_FunctionDescriptor_t fn)
{
    switch (fn) {
        case rt_fn_ISNULL:        return rt_fn_isnull();
        case rt_fn_TOSTR:         return rt_fn_tostr();
        case rt_fn_TYPE:          return rt_fn_type();

        case rt_fn_DBG_TYPENAME:  return rt_fn_dbg_typename();
        case rt_fn_DBG_REFCNT:    return rt_fn_dbg_refcnt();
        case rt_fn_DBG_ID:        return rt_fn_dbg_id();
        case rt_fn_DBG_CALLPROC:  return rt_fn_dbg_callproc();

        case rt_fn_IO_PRINT:      return rt_fn_io_print();
        case rt_fn_IO_INPUT:      return rt_fn_io_input();

        case rt_fn_IT_LEN:        return rt_fn_it_len();

        case rt_fn_STR_EQUALS:    return rt_fn_str_equals();
        case rt_fn_STR_COMPARE:   return rt_fn_str_compare();
        case rt_fn_STR_APPEND:    return rt_fn_str_append();
        case rt_fn_STR_INSERT:    return rt_fn_str_insert();
        case rt_fn_STR_ERASE:     return rt_fn_str_erase();
        case rt_fn_STR_CONCAT:    return rt_fn_str_concat();
        case rt_fn_STR_REVERSE:   return rt_fn_str_reverse();
        case rt_fn_STR_SUBSTR:    return rt_fn_str_substr();
        case rt_fn_STR_FIND:      return rt_fn_str_find();
        case rt_fn_STR_SPLIT:     return rt_fn_str_split();
        case rt_fn_STR_TOI64:     return rt_fn_str_toi64();
        case rt_fn_STR_TOF64:     return rt_fn_str_tof64();
        case rt_fn_STR_SORT:      return rt_fn_str_sort();

        case rt_fn_LST_EQUALS:    return rt_fn_lst_equals();
        case rt_fn_LST_COMPARE:   return rt_fn_lst_compare();
        case rt_fn_LST_APPEND:    return rt_fn_lst_append();
        case rt_fn_LST_INSERT:    return rt_fn_lst_insert();
        case rt_fn_LST_ERASE:     return rt_fn_lst_erase();
        case rt_fn_LST_CONCAT:    return rt_fn_lst_concat();
        case rt_fn_LST_REVERSE:   return rt_fn_lst_reverse();
        case rt_fn_LST_SUBLIST:   return rt_fn_lst_sublst();
        case rt_fn_LST_FIND:      return rt_fn_lst_find();
        case rt_fn_LST_JOIN:      return rt_fn_lst_join();
        case rt_fn_LST_SORT:      return rt_fn_lst_sort();

        case rt_fn_UNDEFINED:
            io_errndie("rt_fn_FunctionsList_call: undefined procedure for desc: '%d'", fn);
            break;
    }
    return rt_Data_null();
}

const rt_DataList_t *rt_fn_get_valid_args(int64_t min_expected_argc)
{
    rt_Data_t args = *rt_VarTable_getref(RT_VTABLE_ARGSVAR);
    if (args.type != rt_DATA_TYPE_LST)
        io_errndie("rt_fn_get_valid_args: "
                   "received arguments list as type '%s'", rt_Data_typename(args));
    if (rt_DataList_length(args.data.lst) < min_expected_argc)
        rt_throw(
            "expected at least %" PRId64 " arguments, received %" PRId64,
            min_expected_argc, rt_DataList_length(args.data.lst)
        );
    return args.data.lst;
}

rt_Data_t rt_fn_call_handler(
    const rt_Data_t context,
    const char *module_name,
    const char *proc_name,
    rt_DataList_t *args
) {
    const ast_Identifier_t *module = (const ast_Identifier_t*) module_name;
    const ast_Identifier_t *proc = (const ast_Identifier_t*) proc_name;

    /* get code as AST from user defined function */
    const ast_Statements_t *code = ast_util_ModuleAndProcTable_get_code(module, proc);

    /* get a descriptor to in-built function */
    const rt_fn_FunctionDescriptor_t fn = rt_fn_FunctionsList_getfn(
        module_name, proc_name);

    const char *currfile = NULL;

    /* update metadata to new module and function */
    if (code) {
        currfile = ast_util_ModuleAndProcTable_get_filename(module, proc);
    } else if (fn != rt_fn_UNDEFINED) {
        currfile = module_name;
    } else {
        rt_throw("undefined procedure '%s:%s'", module_name, proc_name);
    }

    rt_VarTable_push_proc(module, proc, currfile);

    /* store fn args into agrs location */
    rt_VarTable_create(RT_VTABLE_ARGSVAR, rt_Data_list(args), true, false);
    rt_VarTable_create(RT_VTABLE_CONTEXTVAR, context, true, false);

    if (code) {
        /* call user defined function */
        rt_ControlStatus_t ctrl = rt_eval_Statements(code);
        if (ctrl == rt_CTRL_BREAK)
            rt_throw("unexpected `break` statement outside loop");
        if (ctrl == rt_CTRL_CONTINUE)
            rt_throw("unexpected `continue` statement outside loop");
    } else {
        /* call in-built function */
        rt_VarTable_acc_setval(rt_fn_FunctionsList_call(fn));
    }

    rt_Data_t ret = rt_VarTable_pop_proc();
    return ret;
}
