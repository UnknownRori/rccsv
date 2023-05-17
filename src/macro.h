/**
 * @file macro.h
 * @author UnknownRori (68576836+UnknownRori@users.noreply.github.com)
 * @brief A collection of helper macro
 * @version 0.1
 * @date 2023-05-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#ifndef UNKNOWNRORI_MACRO_H
#define UNKNOWNRORI_MACRO_H

#define make(_TYPE, _AMOUNT) (_TYPE *)calloc(_AMOUNT, sizeof(_TYPE));
#define drop(_PTR) \
    free(_PTR);    \
    _PTR = NULL;

#endif
