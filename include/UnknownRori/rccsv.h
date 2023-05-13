/**
 * @file rcsv.h
 * @author UnknownRori (68576836+UnknownRori@users.noreply.github.com)
 * @brief Exposed API for manipulating CSV file in C
 * @version 0.1
 * @date 2023-05-14
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#ifndef UNKNOWNRORI_C_RCCSV_H
#define UNKNOWNRORI_C_RCCSV_H

// DLL Export Import
#if defined(DLL_EXPORT) && defined(_WIN32)

#define DLL_API __declspec(dllexport)
#define DLL_API_EXPORT __cdecl

#elif defined(DLL_IMPORT) && defined(_WIN32)

#define DLL_API __declspec(dllimport)
#define DLL_API_EXPORT __cdecl

#else

#define DLL_API
#define DLL_API_EXPORT

#endif

// Types
typedef struct rccsv rccsv;

// Main Function Definition
#ifdef __cplusplus
extern "C"
{
#endif

    extern DLL_API rccsv DLL_API_EXPORT rccsv_open(const char const *);
    extern DLL_API rccsv DLL_API_EXPORT rccsv_new(const char const *);
    extern DLL_API char *DLL_API_EXPORT rccsv_headers(rccsv *);
    extern DLL_API char *DLL_API_EXPORT rccsv_header(rccsv *, const unsigned int);
    extern DLL_API char *DLL_API_EXPORT rccsv_data(rccsv *, const unsigned int);
    extern DLL_API char *DLL_API_EXPORT rccsv_data_get(rccsv *, const unsigned int, unsigned int);
    extern DLL_API char *DLL_API_EXPORT rccsv_data_push(rccsv *, char *);
    extern DLL_API char *DLL_API_EXPORT rccsv_data_pop(rccsv *);
    extern DLL_API char *DLL_API_EXPORT rccsv_save(const rccsv const *);
    extern DLL_API char *DLL_API_EXPORT rccsv_free(rccsv *);

#ifdef __cplusplus
}
#endif

#endif