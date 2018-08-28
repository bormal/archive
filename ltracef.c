/*----------------------------------------*/
// #define DEBUG
#ifdef DEBUG
#include <stdio.h>
#define LTRACEF(...) \
        do { printf("[%s] %s:%d ", __func__, __FILE__, __LINE__); \
        printf(__VA_ARGS__); printf("\n"); fflush(stdout); } while(false);
#else
#define LTRACEF(...)
#endif
/*----------------------------------------*/
