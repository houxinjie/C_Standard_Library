#ifndef _LIMITS
#define _LIMITS
#ifndef _YVALS
#include "yvals.h"
#endif

#define CHAR_BIT 8
#if _CSIGN
#define CHAR_MAX 127
#define CHAR_MIN (-127-_C2)
#else
#define CHAR_MAX 255
#define CHAR_MIN 0
#endif

#if _ILONG
#define INT_MAX 2147483647
#define INT_MIN (-2147483647-_C2)
#define UINT_MAX 4294967295
#else
#define INT_MAX 32767
#define INT_MIN (-32767-_C2)
#define UINT_MAX 65535
#endif

#define LONG_MAX 2147483647
#define LONG_MIN (-2147483647-_C2)

#define MB_LEN_MAX _MBMAX

#define SCHAR_MAX 127
#define SCHAR_MIN (-127-_C2)

#define SHRT_MAX 32767
#define SHRT_MIN (-32767-_C2)

#define UCHAR_MAX 255
#define ULONG_MAX 4294967295
#define USHRT_MAX 65535

#endif
