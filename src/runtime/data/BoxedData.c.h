#ifndef RT_BOXED_DATA_C_H
#define RT_BOXED_DATA_C_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

/* -----------------------------------------------------------------------
            rt_BoxedData_t         rt_Data_t               rt_DataMap_t
        
                                 /------------
           /---------------      |           |           /--------------
 O-------->|  3  |  data  |----->|  in heap  |---------->|  2  |  ...  |
           ---------------/      |           |           --------------/
                 ^   ^           ------------/                  ^
                 |   |                                          |
 O---------------/   |           /-------------                 |
                     |           |            |                 |
 O-------------------/           |  in stack  |-----------------/
                                 |            |
                                 -------------/
 ---------------------------------------------------------------------- */

#include "runtime/data/Data.h"
#include "runtime/data/BoxedData.h"
#include "runtime/VarTable.h"

rt_BoxedData_t *rt_BoxedData_from(rt_Data_t data)
{
    rt_BoxedData_t *bd = (rt_BoxedData_t*) malloc(sizeof(rt_BoxedData_t));
    /* Allocate rt_Data_t in the heap */
    bd->data = (rt_Data_t*) malloc(sizeof(rt_Data_t));
    *bd->data = rt_Data_null();
    bd->rc = 0;

    /* explicitly set lvalue coz modf sets it to false */
    bd->data->lvalue = true;

    /* Assign data from stack rt_Data_t to the one in heap. rt_VarTable_modf
       takes care of reference count of the members of the stack rt_Data_t */
    rt_VarTable_modf(bd->data, data, false, false);

    return bd;
}

void rt_BoxedData_increfc(rt_BoxedData_t *bd)
{
    if (!bd) return;
    ++bd->rc;
}

void rt_BoxedData_decrefc(rt_BoxedData_t *bd)
{
    if (!bd) return;
    --bd->rc;
    if (bd->rc < 0) bd->rc = 0;
}

void rt_BoxedData_destroy(rt_BoxedData_t **ptr)
{
    if (!ptr || !*ptr) return;
    rt_BoxedData_t *bd = *ptr;
    rt_BoxedData_decrefc(bd);
    if (bd->rc > 0) {
        return;
    }

    /* explicitly set lvalue coz modf sets it to false */
    bd->data->lvalue = true;

    /* Set data to null with rt_VarTable_modf, which effective clears the
       contents (members and their reference counts) */
    rt_VarTable_modf(bd->data, rt_Data_null(), false, false);

    free(bd->data);
    bd->data = NULL;
    free(bd);
    *ptr = NULL;
}

#else
    #warning re-inclusion of module 'runtime/data/BoxedData.c.h'
#endif
