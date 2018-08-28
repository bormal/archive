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

//__PRETTY_FUNCTION__ prints full function signature with class name

// All this variables are gcc special variables now, not preprocessor macros any more.

// Read more
// https://stackoverflow.com/questions/2518969/gcc-unicode-and-function
