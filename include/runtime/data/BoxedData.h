#ifndef RT_BOXED_DATA_H
#define RT_BOXED_DATA_H

#include <stdint.h>

#include "runtime/data/Data.h"

/**
 * The BoxedData acts like a list of 1 element.
 * This is used to store a rt_Data_t in the heap.
 * This is useful when a pointer to rt_Data_t is required.
 * rt_Data_t is a stack based type i.e. its members are reference
 * counted but the struct itself is not. So, we cannot maintain a
 * pointer to an rt_Data_t outside its scope, which means struct
 * type members inside rt_Data_t like struct rt_DataLambda_t or
 * struct rt_DataProc_t cannot have a struct rt_Data_t but needs
 * to have a pointer of rt_Data_t in them.
 * This has created problems in context of procs and lambdas coz
 * the rt_Data_t context pointer ends up referring to a stack object
 * which has already been cleared.
 * This however only happens if the context data was never stored using
 * the rt_VarTable_create or rt_VarTable_modf. This is because the
 * variable table holds data for the entire scope and can return a
 * rt_Data_t pointer.
 */
struct rt_BoxedData_t {
    int64_t rc;
    rt_Data_t *data;
};

/**
 * Create a BoxedData object from a rt_Data_t object.
 * @param data The rt_Data_t object to be boxed. This creates a copy of the data.
 * @param is_weak If true, the reference count of the object heald by thr rt_Data_t is not incremented. Used for lambda and proc context objects.
 */
rt_BoxedData_t *rt_BoxedData_from(rt_Data_t data, bool is_weak);
void rt_BoxedData_increfc(rt_BoxedData_t *bd);
void rt_BoxedData_decrefc(rt_BoxedData_t *bd);
void rt_BoxedData_destroy(rt_BoxedData_t **ptr);

#endif
