/**
 * @file FILE.c
 * @author UnknownRori (68576836+UnknownRori@users.noreply.github.com)
 * @brief Implementation of FILE.h Helper
 * @version 0.1
 * @date 2023-05-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../rccsv_config.h"
#include "./macro.h"
#include "./FILE.h"

#define FILE_BUFFER RCCSV_BUFFER_SIZE

// Todo : Implement for wide character version

typedef enum get_line_status
{
    NOT_FINISHED = -1,
    DONE = 0
} get_line_status;

get_line_status static inline __getline__(FILE *fp, char *buffer, size_t max);

/**
 * Read the entire line of the file descriptor and it will automatically allocated memory for it
 * It uses [`FILE_BUFFER`] to set the buffer size
 *
 * @param FILE
 * @return char
 */
char *readline(FILE *fp)
{
    char buffer[FILE_BUFFER];

    // It won't properly copy entire line, since it's will stop if it get too full
    // but it should work for now
    // Todo : Properly copy the entire line without caring the max buffer size
    __getline__(fp, buffer, FILE_BUFFER);

    size_t len = strnlen(buffer, FILE_BUFFER);

    char *str = make(char, len + 1);
    str[len++] = '\0';
    strncpy(str, buffer, len);

    return str;
}

/**
 * Read entire line on file descriptor, it uses external buffer and max buffer size to limit the reading
 * It will return [`get_line_status`] to make the caller know if the [`__getline__`] actually get the entire line.
 *
 * @param FILE*
 * @param char*
 * @param size_t*
 * @return get_line_status
 */
get_line_status static inline __getline__(FILE *fp, char *buffer, size_t max)
{
    int temp = 0;
    size_t index = 0;

    while ((temp = fgetc(fp)) != EOF)
    {
        if (temp == '\n' || temp == '\r')
        {
            buffer[index++] = '\0';
            break;
        }

        buffer[index] = (char)temp;
        index++;

        if (index >= max)
            return NOT_FINISHED;
    }

    return DONE;
}