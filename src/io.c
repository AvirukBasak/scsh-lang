#include <errno.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "errcodes.h"
#include "globals.h"
#include "io.h"

#ifndef IO_GETLINE
#define IO_GETLINE

/** read string contains trailing new line.
    size_t n is the number of bytes allocated.
    return value is the length of string read. */
ssize_t io_getline(char **lineptr, size_t *n, FILE *stream)
{
    /* The original code is public domain -- Will Hartung 4/9/09 */
    /* Modifications, public domain as well, by Antti Haapala, 11/10/17
       - Switched to getc on 5/23/19 */
    size_t pos;
    int c;

    if (lineptr == NULL || stream == NULL || n == NULL) {
        errno = EINVAL;
        return -1;
    }

    c = getc(stream);
    if (c == EOF) {
        return -1;
    }

    if (*lineptr == NULL) {
        *lineptr = malloc(128);
        if (*lineptr == NULL) {
            return -1;
        }
        *n = 128;
    }

    pos = 0;
    while(c != EOF) {
        if (pos + 1 >= *n) {
            size_t new_size = *n + (*n >> 2);
            if (new_size < 128) {
                new_size = 128;
            }
            char *new_ptr = realloc(*lineptr, new_size);
            if (new_ptr == NULL) {
                return -1;
            }
            *n = new_size;
            *lineptr = new_ptr;
        }

        ((unsigned char *)(*lineptr))[pos ++] = c;
        if (c == '\n') {
            break;
        }
        c = getc(stream);
    }

    (*lineptr)[pos] = '\0';
    return pos;
}

#endif

char *io_readfile(FILE *fp)
{
    if (!fp) io_errndie("io_readfile: " ERR_MSG_NULLPTR);
    char buffer[1024] = "";
    size_t buff_used = 0;

    char *strbuf = (char*) malloc(sizeof(char) * 1024);
    if (!strbuf) io_errndie("io_readfile: " ERR_MSG_MALLOCFAIL);
    int idx = 0;
    int cap = 1024;

    /* read file in chunks of 4096 bytes and append to strbuf */
    while ((buff_used = fread(buffer, sizeof(char), 1023, fp)) > 0) {
        /* terminate the string */
        buffer[buff_used] = '\0';
        /* check for errors */
        int error_num = errno;
        if (ferror(fp)) {
            fclose(fp);
            io_errndie("io_readfile: failed to read from file: %s", strerror(error_num));
        }
        /* append to strbuf */
        if (idx + buff_used >= cap) {
            cap = cap * 2 + buff_used;
            strbuf = (char*) realloc(strbuf, sizeof(char) * cap);
            if (!strbuf) io_errndie("io_readfile: " ERR_MSG_REALLOCFAIL);
        }
        memcpy(strbuf + idx, buffer, buff_used);
        idx += buff_used;
    }

    strbuf[idx] = '\0';
    return strbuf;
}

long long io_get_filesize(const char *filepath)
{
    FILE *file = fopen(filepath, "rb");
    if (!file) io_errnexit("io_get_filesize: couldn't read file: '%s'", filepath);
    long long filesz = -1LL;
    if (fseek(file, 0, SEEK_END) != 0)
        io_errnexit("io_get_filesize: error seeking to end of file");
    filesz = ftell(file);
    if (filesz == -1LL)
        io_errnexit("io_get_filesize: error getting the file size");
    if (fseek(file, 0, SEEK_SET) != 0)
        io_errnexit("io_get_filesize: error seeking to the beginning of the file");
    fclose(file);
    return filesz;
}

char **io_read_lines(const char *filepath, size_t *line_cnt)
{
    FILE *f = fopen(filepath, "r");
    if (!f) io_errnexit("io_read_lines: couldn't read file: '%s'", filepath);
    char *line = NULL;
    *line_cnt = 0;
    size_t list_sz = 0,
           line_len = 0;
    char **ret_lines = NULL;
    while (io_getline(&line, &line_len, f) != -1) {
        if (!line) io_errndie("io_read_lines:" ERR_MSG_MALLOCFAIL);
        const size_t line_len = strlen(line);
        if (line[line_len -1] == '\n') line[line_len -1] = '\0';
        if (*line_cnt >= list_sz) {
            ret_lines = (char**) realloc(ret_lines, (list_sz += list_sz *2 +1) * sizeof(char*));
            if (!ret_lines) io_errndie("io_read_lines:" ERR_MSG_REALLOCFAIL);
        }
        ret_lines[(*line_cnt)++] = line;
        line = NULL;
    }
    return ret_lines;
}

char *io_full_escape_string(const char *str)
{
    if (!str) return NULL;
    size_t len = strlen(str);
    char *escaped = (char*) malloc((4 * len +1) * sizeof(char));
    if (!escaped) io_errndie("io_full_escape_string:" ERR_MSG_MALLOCFAIL);
    char *ptr = escaped;
    while (*str != '\0') {
        switch (*str) {
            case '\a': *ptr++ = '\\'; *ptr++ = 'a'; break;
            case '\b': *ptr++ = '\\'; *ptr++ = 'b'; break;
            case '\f': *ptr++ = '\\'; *ptr++ = 'f'; break;
            case '\n': *ptr++ = '\\'; *ptr++ = 'n'; break;
            case '\r': *ptr++ = '\\'; *ptr++ = 'r'; break;
            case '\t': *ptr++ = '\\'; *ptr++ = 't'; break;
            case '\v': *ptr++ = '\\'; *ptr++ = 'v'; break;
            case '\\': *ptr++ = '\\'; *ptr++ = '\\'; break;
            case '\"': *ptr++ = '\\'; *ptr++ = '"'; break;
            default:
                if (*str < 32 || *str > 126) {
                    /* unprintable character, escape using \xXX notation */
                    sprintf(
                        ptr, "\\x%02X",
                        (unsigned char) *str);
                    ptr += 4;
                } else
                    /* copy printable character as is */
                    *ptr++ = *str;
                break;
        }
        ++str;
    }
    *ptr = '\0';
    return escaped;
}

char *io_partial_escape_string(const char *str)
{
    if (!str) return NULL;
    size_t len = strlen(str);
    char *escaped = (char*) malloc((4 * len +1) * sizeof(char));
    if (!escaped) io_errndie("io_partial_escape_string:" ERR_MSG_MALLOCFAIL);
    char *ptr = escaped;
    while (*str != '\0') {
        switch (*str) {
            case '\a': *ptr++ = '\\'; *ptr++ = 'a'; break;
            case '\b': *ptr++ = '\\'; *ptr++ = 'b'; break;
            case '\f': *ptr++ = '\\'; *ptr++ = 'f'; break;
            case '\n': *ptr++ = '\\'; *ptr++ = 'n'; break;
            case '\r': *ptr++ = '\\'; *ptr++ = 'r'; break;
            case '\t': *ptr++ = '\\'; *ptr++ = 't'; break;
            case '\v': *ptr++ = '\\'; *ptr++ = 'v'; break;
            default:
                if (*str < 32 || *str > 126) {
                    /* unprintable character, escape using \xXX notation */
                    sprintf(
                        ptr, "\\x%02X",
                        (unsigned char) *str);
                    ptr += 4;
                } else
                    /* copy printable character as is */
                    *ptr++ = *str;
                break;
        }
        ++str;
    }
    *ptr = '\0';
    return escaped;
}

void io_errnexit(const char *fmt, ...)
{
    fprintf(stderr, "shsc: ");
    fflush(stderr);
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fflush(stderr);
    fprintf(stderr, "\n");
    exit(ERR_DIE);
}

void io_errndie(const char *fmt, ...)
{
    fprintf(stderr, "shsc: ");
    fflush(stderr);
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fflush(stderr);
    fprintf(stderr, "\n");
    abort();
}

void io_print_srcerr(int line_no, int char_no, const char *fmt, ...)
{
    /* fprintf(stderr, "shsc: %s:%d:%d: ", global_currfile, line_no, char_no); */
    fprintf(stderr, "shsc: %s:%d: ", global_currfile, line_no);
    fflush(stderr);
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fflush(stderr);
    fprintf(stderr, "\n");
}
