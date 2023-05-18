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

#endif // DLL Export Import

// Types
typedef struct rccsv rccsv;

// Todo : Create macro for mapping to struct
#define RCCSV_PARSE

// Main Function Definition
#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

    extern DLL_API rccsv *DLL_API_EXPORT rccsv_open(const char *const filepath);
    extern DLL_API rccsv *DLL_API_EXPORT rccsv_new();
    extern DLL_API char *DLL_API_EXPORT rccsv_headers(rccsv *fd);
    extern DLL_API char *DLL_API_EXPORT rccsv_header(rccsv *fd, const unsigned int col);
    extern DLL_API char *DLL_API_EXPORT rccsv_data(rccsv *fd, const unsigned int row);
    extern DLL_API char *DLL_API_EXPORT rccsv_data_get(rccsv *fd, const unsigned int row, unsigned int col);
    extern DLL_API char *DLL_API_EXPORT rccsv_data_push(rccsv *fd, char *chunk);
    extern DLL_API char *DLL_API_EXPORT rccsv_data_pop(rccsv *fd);
    extern DLL_API char *DLL_API_EXPORT rccsv_save(const rccsv *const fd, const char *const filepath);
    extern DLL_API char *DLL_API_EXPORT rccsv_free(rccsv *fd);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // UNKNOWNRORI_C_RCCSV_H