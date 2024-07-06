#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdbool.h>

#define VERSION "1.6 Beta"
#define AUTHORS "Aviruk Basak"
#define GLOBAL_BYTES_BUFFER_LEN (128)

extern const char *global_currfile;
extern bool global_lex_dbg;

extern int global_rng_state_seed;

#endif
