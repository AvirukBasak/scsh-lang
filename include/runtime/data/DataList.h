#ifndef rt_DATA_LIST_H
#define rt_DATA_LIST_H

#include <stddef.h>

#include "runtime/data/Data.h"

struct rt_DataList_t {
    rt_Data_t *var;
    int64_t length;
    size_t capacity;
    int64_t rc;
};

rt_DataList_t *rt_DataList_init();
int64_t rt_DataList_length(const rt_DataList_t *lst);
void rt_DataList_copy(rt_DataList_t *lst);
void rt_DataList_destroy(rt_DataList_t **ptr);
void rt_DataList_append(rt_DataList_t *lst, rt_Data_t var);
/** data should be updated only by calling
    `void rt_VarTable_modf(rt_Data_t *dest, rt_Data_t src)`
    on the returned data pointer, that'll take care of reference counts */
rt_Data_t *rt_DataList_getref(const rt_DataList_t *lst, int64_t idx);
void rt_DataList_del_index(rt_DataList_t *lst, int64_t idx);
void rt_DataList_del_val(rt_DataList_t *lst, rt_Data_t var);
char *rt_DataList_tostr(const rt_DataList_t *lst);

#endif
