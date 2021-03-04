#ifndef BAN_H
#define BAN_H

#define BAN_FUNCTION(function) the_function_##function##_is_banned

// Use instead: TODO
#undef strcpy
#define strcpy(x, y) BAN_FUNCTION(strcpy)

// Use instead: TODO
#undef strcat
#define strcat(x, y) BAN_FUNCTION(strcat)

// TODO: Elaborate why not good; https://stackoverflow.com/a/2565946
// Use instead: TODO
#undef strncpy
#define strncpy(x, y, z) BAN_FUNCTION(strncpy)

// TODO: Elaborate why not good; https://stackoverflow.com/a/2565946
// Use instead: TODO
#undef strncat
#define strncat(x, y, z) BAN_FUNCTION(strncat)

// https://stackoverflow.com/a/2565736
#undef gets
#define gets(s) BAN_FUNCTION(gets)

// Use instead: fgets
// References:
// - ISO 9899:2011 K.3.5.4.1
// - https://stackoverflow.com/a/46563868
#undef gets_s
#define gets_s(b, s) BAN_FUNCTION(gets_s)

// TODO: printf, sprintf, scanf

// Use instead: void *memset(void *ptr, int value, size_t num)
#undef bzero
#define bzero(s, n) BAN_FUNCTION(bzero) // Use memset instead

// Reason:
// - No error handling
// - UB when error occurs
// Use instead: strtol
// References:
// - MISRA-C:2012 rule 21.7
// - https://stackoverflow.com/a/46563868
#undef atoi
#define atoi(s) BAN_FUNCTION(atoi)

#ifdef HAVE_VARIADIC_MACROS
    #define sprintf(...) BAN_FUNCTION(sprintf)
    #define vsprintf(...) BAN_FUNCTION(vsprintf)
#else
    // If the compiler doesn't know variadic macros (for some magical reason), we at least want to define something like the above
    // This way, we at least get an error
    #define sprintf(x, y, z) BAN_FUNCTION(sprintf)
    #define vsprintf(x, y, z) BAN_FUNCTION(vsprintf)
#endif

#if _MSC_VER && !__INTEL_COMPILER
    // Disallow some C functions specific to MSVC

    // @see gets_s
    #undef _getws_s
    #define _getws_s(b, n) BAN_FUNCTION(_getws_s)

    #ifdef HAVE_VARIADIC_MACROS
        // TODO: Elaborate why not good; https://news.ycombinator.com/item?id=17249324
        // Use instead: TODO
        #undef _snprintf
        #define _snprintf(...) BAN_FUNCTION(_snprintf)
    #else
        // TODO: Elaborate why not good
        // Use instead: TODO
        #undef _snprintf
        #define _snprintf(x, y, z) BAN_FUNCTION(_snprintf)
    #endif

#endif

#endif
