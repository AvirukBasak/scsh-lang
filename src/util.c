#include <inttypes.h>
#include <time.h>


#ifdef _WIN32
    #include <windows.h>
#elif _POSIX_C_SOURCE >= 199309L
    #include <sys/time.h>
#else
    #include <sys/time.h>
    #include <unistd.h>
#endif


uint64_t util_gettime_ms()
{
#ifdef _WIN32
    FILETIME ft;
    GetSystemTimeAsFileTime(&ft);
    uint64_t time = (((uint64_t)ft.dwHighDateTime << 32) | ft.dwLowDateTime) / 10000;
    return time;
#else
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    uint64_t time_in_mill = (ts.tv_sec * 1000) + (ts.tv_nsec / 1000000);
    return time_in_mill;
#endif
}


void util_sleep_ms(int milliseconds)
{
#ifdef _WIN32
    Sleep(milliseconds);
#elif _POSIX_C_SOURCE >= 199309L
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
#else
    if (milliseconds >= 1000) {
        sleep(milliseconds / 1000);
    }
    usleep((milliseconds % 1000) * 1000);
#endif
}
