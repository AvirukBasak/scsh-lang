#ifndef RT_VARTABLE_H
#define RT_VARTABLE_H

#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "ast.h"
#include "runtime/data/Data.h"

#define _RT_VTABLE_TMPVAR_CNT               (32)
#define RT_VTABLE_ARGSVAR                   "args"
#define RT_VTABLE_CONTEXTVAR                "this"
#define RT_VTABLE_CALLSTACK_LIMIT           (1000)
#define RT_VTABLE_ACC                       (rt_VarTable_acc_get()->adr ? rt_VarTable_acc_get()->adr : &rt_VarTable_acc_get()->val)
#define RT_VTABLE_LITERAL_RANDOMKEY_LEN     (12)
#define RT_VTABLE_LITERAL_RANDOMKEY_PREFIX  ('#')


typedef rt_DataMap_t *rt_VarTable_Scope_t;
typedef struct rt_VarTable_proc_t rt_VarTable_proc_t;
typedef struct rt_VarTable_t rt_VarTable_t;
typedef struct rt_VarTable_Acc_t rt_VarTable_Acc_t;


/** the VarTable is basically the call stack */
struct rt_VarTable_t {
    rt_VarTable_proc_t *procs;
    int64_t curr_proc_ptr;
    size_t capacity;
};

/** the scopes stack of a procedure */
struct rt_VarTable_proc_t {
    rt_VarTable_Scope_t *scopes;
    int64_t curr_scope_ptr;
    size_t capacity;
    /* info for stack trace */
    const ast_Identifier_t *module_name;
    const ast_Identifier_t *proc_name;
    const char *filepath;
    int current_line;
};

/** accumulator stores procedure return values
    and also the address from which the value was obtained
    if the value is temporary (no place in variable), it's set
    to .adr = NULL */
struct rt_VarTable_Acc_t{
    rt_Data_t val;
    rt_Data_t *adr;
};

/* few globally defined variables */
extern
rt_Data_t rt_VarTable_rsv_lf,
/* list of globally defined typename variables */
          rt_VarTable_typeid_bul,
          rt_VarTable_typeid_chr,
          rt_VarTable_typeid_i64,
          rt_VarTable_typeid_f64,
          rt_VarTable_typeid_str,
          rt_VarTable_typeid_lst,
          rt_VarTable_typeid_any,
          rt_VarTable_typeid_map,
          rt_VarTable_typeid_proc,
          rt_VarTable_typeid_lambda,
          rt_VarTable_typeid_libhandle,
          rt_VarTable_rsv_null;

/** create a new variable in the current scope */
void rt_VarTable_create(const char *varname, rt_Data_t value, bool is_const, bool is_weak);

/** register a literal in a seperate global map */
void rt_VarTable_mkliteral(rt_Data_t value);

/** clear the gloabl map from `rt_VarTable_mkliteral` for
    reuse in the next statement */
void rt_VarTable_destroy_litmap();

/** modify data directly by address instead of querying via identifier */
rt_Data_t *rt_VarTable_modf(rt_Data_t *dest, rt_Data_t src, bool is_const, bool is_weak);

rt_Data_t *rt_VarTable_getref_errnull(const char *varname);

/** get the variable from the current scope if it exists, else error.
    other than the accumulator, data should be updated only by calling
    `void rt_VarTable_modf(rt_Data_t *dest, rt_Data_t src)`
    on the returned data pointer, that'll take care of reference counts */
rt_Data_t *rt_VarTable_getref(const char *varname);

/** this is used to get the accumulator data and address */
rt_VarTable_Acc_t *rt_VarTable_acc_get(void);

/** this is used to update the accumulator val, nulls adr */
void rt_VarTable_acc_setval(rt_Data_t val);

/** this is used to update the accumulator adr, nulls val */
void rt_VarTable_acc_setadr(rt_Data_t *adr);

/** push a new function scope into the stack and store the procedure name and return address */
void rt_VarTable_push_proc(const ast_Identifier_t *module_name, const ast_Identifier_t *proc_name, const char *filepath);

/** get the procedure from the top of the stack */
rt_VarTable_proc_t *rt_VarTable_top_proc(void);

/** pop the procedure off the stack, return the return address and clear the scope from memory */
rt_Data_t rt_VarTable_pop_proc(void);

/** push a new local scope into the stack */
void rt_VarTable_push_scope();

/** pop local scope and return result of last expression */
rt_Data_t rt_VarTable_pop_scope(void);

/** clear memory of the VarTable */
void rt_VarTable_destroy();

#endif
