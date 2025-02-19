#ifndef RT_FN_MODULE_IO_C_H
#define RT_FN_MODULE_IO_C_H

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "errcodes.h"
#include "io.h"
#include "runtime/io.h"
#include "runtime/data/Data.h"
#include "runtime/data/DataStr.h"
#include "runtime/data/DataList.h"
#include "runtime/data/DataLibHandle.h"
#include "runtime/functions.h"
#include "runtime/functions/module_io.h"
#include "runtime/VarTable.h"
#include "util.h"

bool rt_fn_io_input_type_isvalid(enum rt_DataType_t type);
void rt_fn_io_input_bul(bool *val);
void rt_fn_io_input_chr(char *val);
void rt_fn_io_input_i64(int64_t *val);
void rt_fn_io_input_f64(double *val);
int rt_fn_io_input_str(char **val);

rt_Data_t rt_fn_io_print()
{
    const rt_DataList_t *args = rt_fn_get_valid_args(0);
    int bytes = 0;
    for (int i = 0; i < rt_DataList_length(args); ++i) {
        const rt_Data_t data = *rt_DataList_getref(args, i);
        /* if (rt_Data_isnull(data)) continue; */
        /* print a space before data conditions:
            - data is not the first argument
            - data should not be a new line
            - data at i-1 should not be a new line */
        if (i > 0) {
            rt_Data_t before = *rt_DataList_getref(args, i-1);
            if (!(before.type == rt_DATA_TYPE_CHR && before.data.chr == '\n') &&
                !(data.type   == rt_DATA_TYPE_CHR && data.data.chr == '\n')) {
                bytes += printf(" ");
            }
        }

        /* call tostr to convert data to string */
        rt_Data_t str = rt_fn_call_handler(
            rt_Data_null(),
            "", "tostr",
            rt_DataList_from(data)
        );

        /* print the string form of data */
        char *data_str = rt_Data_tostr(str);
        bytes += printf("%s", data_str);

        /* free the string form of data
           note that the returned data is not freed coz
           the accumulator owns it an it'll be freed anyway
           whe the accumulator lets go of it */
        free(data_str);
    }
    return rt_Data_i64(bytes);
}

rt_Data_t rt_fn_io_println()
{
    const rt_DataList_t *args = rt_fn_get_valid_args(0);

    rt_Data_t bytes = rt_fn_call_handler(
        rt_Data_null(),
        "io", "print",
        /* since we are not taking ownership of args, we can
         * explicitly cast it to non-const to avoid compiler warning
         */
        (rt_DataList_t *) args
    );

    return rt_Data_i64(bytes.data.i64 + printf("\n"));
}

rt_Data_t rt_fn_io_input()
{
    const rt_DataList_t *args = rt_fn_get_valid_args(2);
    const rt_Data_t prompt = *rt_DataList_getref(args, 0);
    const rt_Data_t type_ = *rt_DataList_getref(args, 1);
    rt_Data_t ret = rt_Data_null();
    if (type_.type != rt_DATA_TYPE_I64) {
        char *s = rt_Data_tostr(type_);
        rt_throw(
            "invalid type parameter: '%s'\n"
            "valid parameters are bul, chr, i64, f64 or str\n"
            "respective values are %d, %d, %d, %d or %d", s,
            rt_DATA_TYPE_BUL, rt_DATA_TYPE_CHR, rt_DATA_TYPE_I64, rt_DATA_TYPE_F64, rt_DATA_TYPE_STR);
        free(s);
    }
    enum rt_DataType_t type = type_.data.i64;
    if (!rt_fn_io_input_type_isvalid(type_.data.i64))
        rt_throw(
            "invalid type parameter\n"
            "valid parameters are bul, chr, i64, f64 or str\n"
            "respective values are %d, %d, %d, %d or %d",
            rt_DATA_TYPE_BUL, rt_DATA_TYPE_CHR, rt_DATA_TYPE_I64, rt_DATA_TYPE_F64, rt_DATA_TYPE_STR);

    /* call io:print and display prompt */
    rt_fn_call_handler(
        rt_Data_null(),
        "io", "print",
        rt_DataList_from(prompt)
    );

    switch (type) {
        case rt_DATA_TYPE_BUL: {
            bool val = false;
            rt_fn_io_input_bul(&val);
            ret = rt_Data_bul(val);
            break;
        }
        case rt_DATA_TYPE_CHR: {
            char val = '\0';
            rt_fn_io_input_chr(&val);
            ret = rt_Data_chr(val);
            break;
        }
        case rt_DATA_TYPE_I64: {
            int64_t val = 0;
            rt_fn_io_input_i64(&val);
            ret = rt_Data_i64(val);
            break;
        }
        case rt_DATA_TYPE_F64: {
            double val= 0.0;
            rt_fn_io_input_f64(&val);
            ret = rt_Data_f64(val);
            break;
        }
        case rt_DATA_TYPE_STR: {
            char *val = NULL;
            rt_fn_io_input_str(&val);
            ret = rt_Data_str(rt_DataStr_init(val));
            free(val);
            break;
        }
        case rt_DATA_TYPE_INTERP_STR:
        case rt_DATA_TYPE_LST:
        case rt_DATA_TYPE_ANY:
        case rt_DATA_TYPE_MAP:
        case rt_DATA_TYPE_PROC:
        case rt_DATA_TYPE_LAMBDA:
        case rt_DATA_TYPE_LIBHANDLE: rt_throw(
            "invalid type parameter\n"
            "valid parameters are bul, chr, i64, f64 or str\n"
            "respective values are %d, %d, %d, %d or %d",
            rt_DATA_TYPE_BUL, rt_DATA_TYPE_CHR, rt_DATA_TYPE_I64, rt_DATA_TYPE_F64, rt_DATA_TYPE_STR);
        }
    return ret;
}

rt_Data_t rt_fn_io_fexists()
{
    const rt_DataList_t *args = rt_fn_get_valid_args(1);

    const rt_Data_t filename = *rt_DataList_getref(args, 0);
    rt_Data_assert_type(filename, rt_DATA_TYPE_STR, "arg 0");

    char *filename_str = rt_Data_tostr(filename);
    /* get path relative to the current script dir which can be obtained from the top procedure
       in the stack */
    char *currscriptdir = util_dirname((rt_VarTable_top_proc() -1)->filepath);
    char *filepath_str = util_sjoin("%s/%s", currscriptdir, filename_str);
    free(filename_str);
    free(currscriptdir);

    FILE *fp = fopen(filepath_str, "r");
    if (fp) {
        fclose(fp);
        free(filepath_str);
        return rt_Data_bul(true);
    }
    free(filepath_str);
    return rt_Data_bul(false);
}

rt_Data_t rt_fn_io_fread()
{
    const rt_DataList_t *args = rt_fn_get_valid_args(1);

    const rt_Data_t filename = *rt_DataList_getref(args, 0);
    rt_Data_assert_type(filename, rt_DATA_TYPE_STR, "arg 0");

    char *filename_str = rt_Data_tostr(filename);
    /* get path relative to the current script dir which can be obtained from the top -1
       procedure in the stack; top procedure is the current procedure */
    char *currscriptdir = util_dirname((rt_VarTable_top_proc() -1)->filepath);
    char *filepath_str = util_sjoin("%s/%s", currscriptdir, filename_str);
    free(filename_str);
    free(currscriptdir);


    FILE *fp = fopen(filepath_str, "rb");
    if (!fp) rt_throw(
        "failed to open file '%s': %s",
        filepath_str,
        strerror(errno)
    );

    char *buffer = io_readfile(fp);
    rt_DataStr_t *strbuf = rt_DataStr_init(buffer);
    fclose(fp);
    free(filepath_str);
    free(buffer);
    return rt_Data_str(strbuf);
}

rt_Data_t rt_fn_io_fwrite()
{
    const rt_DataList_t *args = rt_fn_get_valid_args(2);

    const rt_Data_t filename = *rt_DataList_getref(args, 0);
    const rt_Data_t data = *rt_DataList_getref(args, 1);
    rt_Data_assert_type(filename, rt_DATA_TYPE_STR, "arg 0");

    char *data_str = rt_Data_tostr(data);
    size_t bytes = strlen(data_str);

    char *filename_str = rt_Data_tostr(filename);
    /* get path relative to the current script dir which can be obtained from the top -1
       procedure in the stack; top procedure is the current procedure */
    char *currscriptdir = util_dirname((rt_VarTable_top_proc() -1)->filepath);
    char *filepath_str = util_sjoin("%s/%s", currscriptdir, filename_str);
    free(filename_str);
    free(currscriptdir);

    FILE *fp = fopen(filepath_str, "wb");
    if (!fp) rt_throw(
        "failed to open file '%s': %s",
        filepath_str,
        strerror(errno)
    );

    bytes = fwrite(data_str, sizeof(char), bytes, fp);
    /* check for errors */
    int error_num = errno;
    if (ferror(fp)) {
        fclose(fp);
        rt_throw("failed to write to file '%s': %s",
            filepath_str, strerror(error_num));
    }

    fclose(fp);
    free(filepath_str);
    free(data_str);
    return rt_Data_i64(bytes);
}

rt_Data_t rt_fn_io_fappend()
{
    const rt_DataList_t *args = rt_fn_get_valid_args(2);

    const rt_Data_t filename = *rt_DataList_getref(args, 0);
    const rt_Data_t data = *rt_DataList_getref(args, 1);
    rt_Data_assert_type(filename, rt_DATA_TYPE_STR, "arg 0");

    char *data_str = rt_Data_tostr(data);
    size_t bytes = strlen(data_str);

    char *filename_str = rt_Data_tostr(filename);
    /* get path relative to the current script dir which can be obtained from the top -1
       procedure in the stack; top procedure is the current procedure */
    char *currscriptdir = util_dirname((rt_VarTable_top_proc() -1)->filepath);
    char *filepath_str = util_sjoin("%s/%s", currscriptdir, filename_str);
    free(filename_str);
    free(currscriptdir);

    FILE *fp = fopen(filepath_str, "ab");
    if (!fp) rt_throw(
        "failed to open file '%s': %s",
        filepath_str,
        strerror(errno)
    );

    bytes = fwrite(data_str, sizeof(char), bytes, fp);
    /* check for errors */
    int error_num = errno;
    if (ferror(fp)) {
        fclose(fp);
        rt_throw("failed to write to file '%s': %s",
            filepath_str, strerror(error_num));
    }

    fclose(fp);
    free(filepath_str);
    free(data_str);
    return rt_Data_i64(bytes);
}

#ifdef _WIN32
    #include <windows.h>
#else
    #include <dlfcn.h>
#endif

rt_Data_t rt_fn_io_libopen()
{
    const rt_DataList_t *args = rt_fn_get_valid_args(1);
    const rt_Data_t libname_arg = *rt_DataList_getref(args, 0);
    rt_Data_assert_type(libname_arg, rt_DATA_TYPE_STR, "arg 0");

    char *filename_str = rt_Data_tostr(libname_arg);
    /* get path relative to the current script dir which can be obtained from the top -1
       procedure in the stack; top procedure is the current procedure */
    char *currscriptdir = util_dirname((rt_VarTable_top_proc() -1)->filepath);
    char *filepath_str = util_sjoin("%s/%s", currscriptdir, filename_str);
    free(filename_str);
    free(currscriptdir);

    rt_DataLibHandle_t *handle = rt_DataLibHandle_init(filepath_str);
    return rt_Data_libhandle(handle);
}

rt_Data_t rt_fn_io_libsym()
{
    // Get the valid arguments. We expect two arguments: handle and symbol name.
    const rt_DataList_t *args = rt_fn_get_valid_args(2);
    const rt_Data_t handle_arg = *rt_DataList_getref(args, 0);
    const rt_Data_t symbolname_arg = *rt_DataList_getref(args, 1);

    // Assert that the arguments are of the correct type.
    rt_Data_assert_type(handle_arg, rt_DATA_TYPE_LIBHANDLE, "arg 0");
    rt_Data_assert_type(symbolname_arg, rt_DATA_TYPE_STR, "arg 1");

    // Convert the symbol name to a C string.
    char *symbolname = rt_Data_tostr(symbolname_arg);

    const rt_Data_t lambda = rt_Data_lambda_native(
        handle_arg.data.libhandle,
        symbolname_arg.data.str,
        rt_DataLibHandle_lookup(handle_arg.data.libhandle, symbolname)
    );

    free(symbolname);
    return lambda;
}

bool rt_fn_io_input_type_isvalid(enum rt_DataType_t type)
{
    switch (type) {
        case rt_DATA_TYPE_BUL:
        case rt_DATA_TYPE_CHR:
        case rt_DATA_TYPE_I64:
        case rt_DATA_TYPE_F64:
        case rt_DATA_TYPE_STR:
            return true;
        case rt_DATA_TYPE_INTERP_STR:
        case rt_DATA_TYPE_LST:
        case rt_DATA_TYPE_ANY:
        case rt_DATA_TYPE_MAP:
        case rt_DATA_TYPE_PROC:
        case rt_DATA_TYPE_LAMBDA:
        case rt_DATA_TYPE_LIBHANDLE:
            return false;
    }
    return false;
}

void rt_fn_io_input_bul(bool *val)
{
    if (!val) io_errndie("rt_fn_io_input_bul:" ERR_MSG_NULLPTR);
    char *str;
    int len = rt_fn_io_input_str(&str);
    if (!strncmp("1", str, len)) *val = true;
    else if (!strncmp("0", str, len)) *val = false;
    else if (!strncmp("true", str, len)) *val = true;
    else if (!strncmp("false", str, len)) *val = false;
    else rt_throw("invalid input for type bul: '%s'", str);
    free(str);
}

void rt_fn_io_input_chr(char *val)
{
    if (!val) io_errndie("rt_fn_io_input_chr:" ERR_MSG_NULLPTR);
    char *str;
    int len = rt_fn_io_input_str(&str);
    if (len == 1) *val = str[0];
    else if (len == 0) *val = 0;
    else rt_throw("invalid input for type chr: '%s'", str);
    free(str);
}

void rt_fn_io_input_i64(int64_t *val)
{
    if (!val) io_errndie("rt_fn_io_input_i64:" ERR_MSG_NULLPTR);
    char *str;
    rt_fn_io_input_str(&str);
    char *endptr;
    errno = 0;
    *val = (int64_t) strtoll(str, &endptr, 10);
    if (errno || *endptr != '\0')
        rt_throw("invalid input for type i64: '%s'", str);
    free(str);
}

void rt_fn_io_input_f64(double *val)
{
    if (!val) io_errndie("rt_fn_io_input_f64:" ERR_MSG_NULLPTR);
    char *str;
    rt_fn_io_input_str(&str);
    char *endptr;
    errno = 0;
    *val = (double) strtod(str, &endptr);
    if (errno || *endptr != '\0')
        rt_throw("invalid input for type f64: '%s'", str);
    free(str);
}

int rt_fn_io_input_str(char **val)
{
    if (!val) io_errndie("rt_fn_io_input_str:" ERR_MSG_NULLPTR);
    *val = NULL;
    size_t bufsize = 0;
    int len = io_getline(val, &bufsize, stdin);
    /* remove the newline from result */
    if (len < 0) {
        fprintf(stderr, "%c", '\n');
        rt_throw("unknown error occurred");
    }
    (*val)[len-1] = 0; len--;
    return len;
}

#else
    #warning re-inclusion of module 'functions/module_io.c.h'
#endif
