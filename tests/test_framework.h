/**
 * @file test_framework.h
 * @author UnknownRori (68576836+UnknownRori@users.noreply.github.com)
 * @brief Header file for managing Unit Test
 * @version 0.1
 * @date 2023-05-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#ifndef UNKNOWNRORI_TEST_FRAMEWORK_H
#define UNKNOWNRORI_TEST_FRAMEWORK_H

#include "./assert.h"

typedef struct test_result
{
    const char *m_name;
    int m_total;
    int m_success;
} test_result;

#define TEST_CASE_REGISTER(_FUNC)                                                                                        \
    {                                                                                                                    \
        test_result _result = test_##_FUNC("test_" #_FUNC);                                                              \
        if (_result.m_total == _result.m_success)                                                                        \
            fprintf(stderr, "\t\e[1;32m[PASS]\e[0m %s [%d/%d]\n\n", _result.m_name, _result.m_total, _result.m_success); \
        else                                                                                                             \
            fprintf(stderr, "\t\e[1;41m[FAIL]\e[0m %s [%d/%d]\n\n", _result.m_name, _result.m_total, _result.m_success); \
    }

#define TEST_CASE(_NAME) test_result test_##_NAME(const char *__TEST_CASE_NAME)

#define TEST_CASE_INIT()                                   \
    test_result _TEST_FRAMEWORK_TEST_RESULT;               \
    _TEST_FRAMEWORK_TEST_RESULT.m_name = __TEST_CASE_NAME; \
    _TEST_FRAMEWORK_TEST_RESULT.m_total = 0;               \
    _TEST_FRAMEWORK_TEST_RESULT.m_success = 0;

#define TEST_CASE_EXPECT(__EXPRESSION, __MSG)           \
    {                                                   \
        _TEST_FRAMEWORK_TEST_RESULT.m_total += 1;       \
        if ((__EXPRESSION))                             \
        {                                               \
            _TEST_FRAMEWORK_TEST_RESULT.m_success += 1; \
            PRINT_PASS(__EXPRESSION, __MSG);            \
        }                                               \
        else                                            \
            PRINT_FAIL(__EXPRESSION, __MSG);            \
    }

#define TEST_CASE_DONE() \
    return _TEST_FRAMEWORK_TEST_RESULT;

#endif // UNKNOWNRORI_TEST_FRAMEWORK_H