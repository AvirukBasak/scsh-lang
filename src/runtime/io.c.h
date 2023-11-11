#ifndef RT_IO_C_H
#define RT_IO_C_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "ast/api.h"
#include "errcodes.h"
#include "runtime.h"
#include "runtime/io.h"
#include "runtime/VarTable.h"

#define RT_IO_TRACE_LIMIT         (100)
#define RT_IO_THROW_PRINT_FN      "%s:%s"
#define RT_IO_THROW_DONT_PRINT_FN ""

void rt_throw(const char *fmt, ...)
{
    fprintf(stderr, "shsc: " RT_IO_THROW_DONT_PRINT_FN "%s:%d: ",
        /* rt_VarTable_top_proc()->module_name, */
        /* rt_VarTable_top_proc()->proc_name, */
        rt_VarTable_top_proc()->filepath,
        rt_VarTable_top_proc()->current_line);
    fflush(stderr);
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fflush(stderr);
    fprintf(stderr, "\n");

    /* print stack trace */
    int trace_lim_i = 0;
    while (rt_VarTable_top_proc() && trace_lim_i++ < RT_IO_TRACE_LIMIT) {
        fprintf(stderr, "    at " RT_IO_THROW_PRINT_FN " (%s:%d)\n",
            rt_VarTable_top_proc()->module_name,
            rt_VarTable_top_proc()->proc_name,
            rt_VarTable_top_proc()->filepath,
            rt_VarTable_top_proc()->current_line
        );
        rt_VarTable_pop_proc();
    }
    if (trace_lim_i >= RT_IO_TRACE_LIMIT) {
        fprintf(stderr, "    ...\n");
    }
    fflush(stderr);

#ifdef DEBUG
    abort();
#else
    exit(ERR_RUNTIME);
#endif
}

#else
    #warning re-inclusion of module 'runtime/io.c.h'
#endif
