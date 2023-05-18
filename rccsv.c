/**
 * @file rccsv.c
 * @author UnknownRori (68576836+UnknownRori@users.noreply.github.com)
 * @brief Main implementation of rccsv library
 * @version 0.1
 * @date 2023-05-14
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdlib.h>

#include "./include/UnknownRori/rccsv.h"
#include "./src/rccsv_internal.h"
#include "./rccsv_config.h"

#include "./src/FILE.h"
#include "./src/macro.h"
#include "./src/errno.h"

extern DLL_API rccsv *DLL_API_EXPORT rccsv_open(const char *const filepath)
{
    FILE *fd = nullptr;

    if (fopen_s(&fd, filepath, "r") == NO_SUCH_FILE_OR_DIR_ERR)
        return nullptr;

    rccsv *tmp;
    if ((tmp = rccsv_new()) == nullptr)
        return nullptr;

    tmp->m_fd = fd;
    // tmp->m_header = readline(fd, RCCSV_BUFFER_SIZE);

    return tmp;
}

extern DLL_API rccsv *DLL_API_EXPORT rccsv_new()
{
    rccsv *tmp = make(rccsv, 1);

    if (tmp == nullptr)
        return nullptr;

    return tmp;
}

extern DLL_API char *DLL_API_EXPORT rccsv_headers(rccsv *)
{
    return nullptr;
}

extern DLL_API char *DLL_API_EXPORT rccsv_header(rccsv *, const unsigned int)
{
    return nullptr;
}

extern DLL_API char *DLL_API_EXPORT rccsv_data(rccsv *, const unsigned int)
{
    return nullptr;
}

extern DLL_API char *DLL_API_EXPORT rccsv_data_get(rccsv *, const unsigned int, unsigned int)
{
    return nullptr;
}

extern DLL_API char *DLL_API_EXPORT rccsv_data_push(rccsv *, char *)
{
    return nullptr;
}

extern DLL_API char *DLL_API_EXPORT rccsv_data_pop(rccsv *)
{
    return nullptr;
}

extern DLL_API char *DLL_API_EXPORT rccsv_save(const rccsv *const fd, const char *const filepath)
{
    return nullptr;
}

extern DLL_API char *DLL_API_EXPORT rccsv_free(rccsv *)
{
    return nullptr;
}