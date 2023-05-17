/**
 * @file rccsv_internal.h
 * @author UnknownRori (68576836+UnknownRori@users.noreply.github.com)
 * @brief Internal rccsv header file
 * @version 0.1
 * @date 2023-05-14
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once
#ifndef UNKNOWNRORI_C_RCCSV_INTERN_H
#define UNKNOWNRORI_C_RCCSV_INTERN_H

#include <stdio.h>

typedef struct rccsv
{
    FILE *m_fd;
    char *m_file_path;
    char *m_header;
    char *m_data;
} rccsv;

#endif // UNKNOWNRORI_C_RCCSV_INTERN_H