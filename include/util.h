#ifndef UTIL_H
#define UTIL_H

#include <stdint.h>

/** Returns a random number between 0 and RAND_MAX. */
int util_rand();

uint64_t util_gettime_ms();
void util_sleep_ms(int milliseconds);
int util_system(const char *command, char **outbuff, char **errbuff);
char *util_sjoin(const char *fmt, ...) __attribute__((format(printf, 1, 2)));
char *util_dirname(const char *path);

#endif
