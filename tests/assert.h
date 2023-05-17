/**
 * @file macro.h
 * @author UnknownRori (68576836+UnknownRori@users.noreply.github.com)
 * @brief Test Macro
 * @version 0.1
 * @date 2023-05-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#ifndef UNKNOWNRORI_ASSSERT_MACRO_H
#define UNKNOWNRORI_ASSSERT_MACRO_H

#if defined(DEBUG)

#include <stdio.h>
#include <string.h>

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#if defined(COLORED)

#define ASSERT(__EXPRESSION, MSG)                                                                      \
    if (__EXPRESSION)                                                                                  \
    {                                                                                                  \
        printf("\e[1;32m[PASS]\e[0m\t%s:%d : %s\n\t%s\n", __FILENAME__, __LINE__, #__EXPRESSION, MSG); \
    }                                                                                                  \
    else                                                                                               \
    {                                                                                                  \
        printf("\e[1;41m[FAIL]\e[0m\t%s:%d : %s\n\t%s\n", __FILENAME__, __LINE__, #__EXPRESSION, MSG); \
    }

#define LOG(__MSG) fprintf(stderr, "\e[1;33m[LOG ]\e[0m\t\e[1m%s:%d\e[0m : %s\n", __FILENAME__, __LINE__, __MSG);
#define ERR(__MSG) fprintf(stderr, "\e[1;41m[ERR ]\e[0m\t\e[1m%s:%d\e[0m : %s\n", __FILENAME__, __LINE__, __MSG);

#else

#define ASSERT(__EXPRESSION, MSG)                                                         \
    if (__EXPRESSION)                                                                     \
    {                                                                                     \
        printf("[PASS]\t%s:%d : %s\n\t%s\n", __FILENAME__, __LINE__, #__EXPRESSION, MSG); \
    }                                                                                     \
    else                                                                                  \
    {                                                                                     \
        printf("[FAIL]\t%s:%d : %s\n\t%s\n", __FILENAME__, __LINE__, #__EXPRESSION, MSG); \
    }

#define LOG(__MSG) fprintf(stderr, "[LOG]\t%s:%d : %s\n", __FILENAME__, __LINE__, __MSG);
#define ERR(__MSG) fprintf(stderr, "[ERR]\t%s:%d : %s\n", __FILENAME__, __LINE__, __MSG);

#endif

#else

#define ASSERT(__EXPRESSION, MSG)

#endif

#endif
