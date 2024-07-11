#ifndef RT_DATA_LIST_C_H
#define RT_DATA_LIST_C_H

#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "io.h"
#include "errcodes.h"
#include "runtime/data/Data.h"
#include "runtime/data/DataList.h"
#include "runtime/data/DataStr.h"
#include "runtime/data/GarbageColl.h"
#include "runtime/io.h"

#define RT_DATALIST_DEFAULT_MATLEN      (16)
#define RT_DATALIST_GETREF(lst_, idx_)  ((lst_)->list[(idx_) / (lst_)->matlen][(idx_) % (lst_)->matlen])

rt_DataList_t *rt_DataList_init()
{
    rt_DataList_t *lst = (rt_DataList_t*) malloc(sizeof(rt_DataList_t));
    if (!lst) io_errndie("rt_DataList_init:" ERR_MSG_MALLOCFAIL);
    lst->list = NULL;
    lst->length = 0;
    lst->rowcnt = 0;
    lst->matlen = RT_DATALIST_DEFAULT_MATLEN;
    /* rc is kept at 0 unless the runtime assigns
       a variable to the data */
    lst->rc = 0;
    return lst;
}

rt_DataList_t *rt_DataList_init_matlen(int64_t matlen)
{
    rt_DataList_t *lst = rt_DataList_init();
    lst->matlen = matlen;
    return lst;
}

rt_DataList_t *rt_DataList_clone(const rt_DataList_t *lst)
{
    rt_DataList_t *lst2 = rt_DataList_init();
    for (int64_t i = 0; i < lst->length; i++)
        rt_DataList_append(lst2, RT_DATALIST_GETREF(lst, i));
    return lst2;
}

int64_t rt_DataList_length(const rt_DataList_t *lst)
{
    return lst->length;
}

int64_t rt_DataList_capacity(const rt_DataList_t *lst)
{
    if (!lst->length) return 0;
    return lst->matlen * lst->rowcnt;
}

void rt_DataList_increfc(rt_DataList_t *lst)
{
    ++lst->rc;
}

void rt_DataList_decrefc(rt_DataList_t *lst)
{
    --lst->rc;
    if (lst->rc < 0) lst->rc = 0;
}

void rt_DataList_destroy_circular(rt_DataList_t **ptr, bool flag)
{
    if (!ptr || !*ptr) return;
    rt_DataList_t *lst = *ptr;
    /* ref counting */
    rt_DataList_decrefc(lst);
    if (lst->rc > 0) {
        /* if rc > 0, check if the data has only cyclic references
           if so, set rc to 0 to free the data */
        if (flag && rt_data_GC_has_only_cyclic_refcnt(rt_Data_list(lst))) {
            rt_data_GC_break_cycle(rt_Data_list(lst), rt_Data_list(lst));
            lst->rc = 0;
        }
        else return;
    }
    /* free if rc 0 */
    for (int64_t i = 0; i < lst->length; i++)
        rt_Data_destroy_circular(&RT_DATALIST_GETREF(lst, i), flag);

    for (int64_t i = 0; i < lst->rowcnt; i++)
        if (lst->list) free(lst->list[i]);
    free(lst->list);

    free(lst);
    *ptr = NULL;
}

void rt_DataList_destroy(rt_DataList_t **ptr)
{
    rt_DataList_destroy_circular(ptr, false);
}

bool rt_DataList_isequal(const rt_DataList_t *lst1, const rt_DataList_t *lst2)
{
    if (lst1->length != lst2->length) return false;
    for (int64_t i = 0; i < lst1->length; i++) {
        if (!rt_Data_isequal(RT_DATALIST_GETREF(lst1, i), RT_DATALIST_GETREF(lst2, i)))
            return false;
    }
    return true;
}

int64_t rt_DataList_compare(const rt_DataList_t *lst1, const rt_DataList_t *lst2)
{
    if (lst1->length != lst2->length)
        return lst1->length - lst2->length;
    for (int64_t i = 0; i < lst1->length; i++) {
        int64_t cmp = rt_Data_compare(RT_DATALIST_GETREF(lst1, i), RT_DATALIST_GETREF(lst2, i));
        if (cmp != 0) return cmp;
    }
    return 0;
}

void rt_DataList_append(rt_DataList_t *lst, rt_Data_t var)
{
    rt_Data_increfc(&var);
    if (lst->length >= rt_DataList_capacity(lst)) {
        rt_Data_t *newrow = (rt_Data_t*) malloc(lst->matlen * sizeof(rt_Data_t));
        if (!newrow) io_errndie("rt_DataList_append:" ERR_MSG_MALLOCFAIL);
        lst->list = (rt_Data_t**) realloc(lst->list, (lst->rowcnt + 1) * sizeof(rt_Data_t*));
        if (!lst->list) io_errndie("rt_DataList_append:" ERR_MSG_REALLOCFAIL);
        lst->list[lst->rowcnt] = newrow;
        ++lst->rowcnt;
    }
    ++lst->length;
    RT_DATALIST_GETREF(lst, lst->length -1) = (rt_Data_t) {
        .type = var.type,
        .data = var.data,
        .is_const = false,
        .is_weak = false,
    };
}

void rt_DataList_concat(rt_DataList_t *lst, const rt_DataList_t *lst2)
{
    for (int64_t i = 0; i < lst2->length; i++)
        rt_DataList_append(lst, RT_DATALIST_GETREF(lst2, i));
}

void rt_DataList_insert(rt_DataList_t *lst, int64_t idx, rt_Data_t var)
{
    if (!(idx >= 0 && idx < lst->length))
        rt_throw("list out of bounds for index '%" PRId64 "'", idx);
    rt_Data_increfc(&var);
    if (lst->length >= rt_DataList_capacity(lst)) {
        rt_Data_t *newrow = (rt_Data_t*) malloc(lst->matlen * sizeof(rt_Data_t));
        if (!newrow) io_errndie("rt_DataList_insert:" ERR_MSG_MALLOCFAIL);
        lst->list = (rt_Data_t**) realloc(lst->list, (lst->rowcnt + 1) * sizeof(rt_Data_t*));
        if (!lst->list) io_errndie("rt_DataList_insert:" ERR_MSG_REALLOCFAIL);
        lst->list[lst->rowcnt] = newrow;
        ++lst->rowcnt;
    }
    for (int64_t i = lst->length; i > idx; i--)
        RT_DATALIST_GETREF(lst, i) = RT_DATALIST_GETREF(lst, i-1);
    RT_DATALIST_GETREF(lst, idx) = (rt_Data_t) {
        .type = var.type,
        .data = var.data,
        .is_const = false,
        .is_weak = false,
    };
    ++lst->length;
}

void rt_DataList_erase(rt_DataList_t *lst, int64_t idx, int64_t len)
{
    if (!(idx >= 0 && idx < lst->length))
        rt_throw("list out of bounds for index '%" PRId64 "'", idx);
    if (len < 0) len = 0;
    if (idx + len > lst->length) len = lst->length - idx;
    for (int64_t i = idx; i < idx + len; i++)
        rt_Data_destroy(&RT_DATALIST_GETREF(lst, i));
    for (int64_t i = idx + len; i < lst->length; i++)
        RT_DATALIST_GETREF(lst, i - len) = RT_DATALIST_GETREF(lst, i);
    lst->length -= len;
}

void rt_DataList_reverse(rt_DataList_t *lst)
{
    for (int64_t i = 0; i < lst->length / 2; i++) {
        rt_Data_t tmp = RT_DATALIST_GETREF(lst, i);
        RT_DATALIST_GETREF(lst, i) = RT_DATALIST_GETREF(lst, lst->length - i - 1);
        RT_DATALIST_GETREF(lst, lst->length - i - 1) = tmp;
    }
}

int64_t rt_DataList_find(const rt_DataList_t *lst, rt_Data_t var)
{
    for (int64_t i = 0; i < lst->length; i++) {
        if (rt_Data_isequal(RT_DATALIST_GETREF(lst, i), var))
            return i;
    }
    return -1;
}

rt_DataList_t *rt_DataList_sublist(const rt_DataList_t *lst, int64_t idx, int64_t len)
{
    if (!(idx >= 0 && idx < lst->length))
        rt_throw("list out of bounds for index '%" PRId64 "'", idx);
    if (len < 0) len = 0;
    if (idx + len > lst->length) len = lst->length - idx;
    rt_DataList_t *sublist = rt_DataList_init();
    for (int64_t i = idx; i < idx + len; i++)
        rt_DataList_append(sublist, RT_DATALIST_GETREF(lst, i));
    return sublist;
}

rt_DataStr_t *rt_DataList_join(const rt_DataList_t *lst, const rt_DataStr_t *sep)
{
    /* for each element, convert using rt_Data_tostr and create a new string object
       along with the seperator */
    rt_DataStr_t *str = rt_DataStr_init("");
    for (int64_t i = 0; i < lst->length; i++) {
        char *lst_el = rt_Data_tostr(RT_DATALIST_GETREF(lst, i));
        rt_DataStr_t *str2 = rt_DataStr_init(lst_el);
        rt_DataStr_concat(str, str2);
        rt_DataStr_destroy(&str2);
        free(lst_el);
        lst_el = NULL;
        if (i < lst->length - 1)
            rt_DataStr_concat(str, sep);
    }
    return str;
}

rt_DataList_t *rt_DataList_sort(rt_DataList_t *lst)
{
    /* implement insertion sort algorithm inplace, use rt_Data_compare */
    for (int64_t i = 1; i < lst->length; i++) {
        rt_Data_t key = RT_DATALIST_GETREF(lst, i);
        int64_t j = i - 1;
        while (j >= 0 && rt_Data_compare(RT_DATALIST_GETREF(lst, j), key) > 0) {
            RT_DATALIST_GETREF(lst, j+1) = RT_DATALIST_GETREF(lst, j);
            j--;
        }
        RT_DATALIST_GETREF(lst, j+1) = key;
    }
    return lst;
}

rt_Data_t *rt_DataList_getref_errnull(const rt_DataList_t *lst, int64_t idx)
{
    if (idx >= 0 && idx < lst->length) {
        return &RT_DATALIST_GETREF(lst, idx);
    }
    return NULL;
}

rt_Data_t *rt_DataList_getref(const rt_DataList_t *lst, int64_t idx)
{
    rt_Data_t *data = rt_DataList_getref_errnull(lst, idx);
    if (!data) rt_throw("list out of bounds for index '%" PRId64 "'", idx);
    return data;
}

void rt_DataList_del_index(rt_DataList_t *lst, int64_t idx)
{
    if (idx >= 0 && idx < lst->length) {
        rt_Data_destroy(&RT_DATALIST_GETREF(lst, idx));
        for (int64_t i = idx + 1; i < lst->length; i++)
            RT_DATALIST_GETREF(lst, i-1) = RT_DATALIST_GETREF(lst, i);
        --lst->length;
    } else rt_throw("list out of bounds for index '%" PRId64 "'", idx);
}

void rt_DataList_del_val(rt_DataList_t *lst, rt_Data_t var)
{
    for (int64_t i = 0; i < lst->length; i++) {
        if (memcmp(&RT_DATALIST_GETREF(lst, i), &var, sizeof(rt_Data_t)) == 0) {
            rt_DataList_del_index(lst, i);
            --i;
        }
    }
}

char *rt_DataList_tostr(const rt_DataList_t *lst)
{
    size_t size = 3;
    char *str = (char*) malloc(size * sizeof(char));
    if (!str) io_errndie("rt_DataList_tostr:" ERR_MSG_MALLOCFAIL);
    int p = 0;
    sprintf(&str[p++], "[");
    for (int64_t i = 0; i < lst->length; ++i) {
        const rt_Data_t data_val = RT_DATALIST_GETREF(lst, i);
        char *lst_el = rt_Data_tostr(data_val);
        char *lst_el_escaped = io_partial_escape_string(lst_el);
        free(lst_el);
        lst_el = NULL;

        char *delim = "";
        if (RT_DATALIST_GETREF(lst, i).type == rt_DATA_TYPE_CHR) delim = "'";
        else if (data_val.type == rt_DATA_TYPE_STR
              || data_val.type == rt_DATA_TYPE_INTERP_STR) delim = "\"";

        /** size values:  "   <delim>               %s               <delim>     \x00 */
        const size_t sz = strlen(delim) + strlen(lst_el_escaped) + strlen(delim) + 1;
        str = (char*) realloc(str, (size += sz) * sizeof(char));
        if (!str) io_errndie("rt_DataList_tostr:" ERR_MSG_REALLOCFAIL);

        sprintf(&str[p], "%s%s%s", delim, lst_el_escaped, delim);

        free(lst_el_escaped);
        lst_el_escaped = NULL;
        p += sz -1;
        if (i < lst->length - 1) {
            str = (char*) realloc(str, (size += 2) * sizeof(char));
            if (!str) io_errndie("rt_DataList_tostr:" ERR_MSG_REALLOCFAIL);
            sprintf(&str[p], ", ");
            p += 2;
        }
    }
    sprintf(&str[p++], "]");
    return str;
}

#else
    #warning re-inclusion of module 'runtime/data/DataList.c.h'
#endif
