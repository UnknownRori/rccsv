/**
 * @file FILE.h
 * @author UnknownRori (68576836+UnknownRori@users.noreply.github.com)
 * @brief Helper for manipulating FILE IO
 * @version 0.1
 * @date 2023-05-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#ifndef UNKNOWNRORI_FILE_H
#define UNKNOWNRORI_FILE_H

#include <stdio.h>
#include "./types.h"

char *readline(FILE *fp, usize buffer_max);

#endif // UNKNOWNRORI_FILE_H