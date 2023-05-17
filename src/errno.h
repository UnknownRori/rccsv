/**
 * @file errno.h
 * @author UnknownRori (68576836+UnknownRori@users.noreply.github.com)
 * @brief Helper about errno
 * @version 0.1
 * @date 2023-05-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#ifndef UNKNOWNRORI_ERRNO_H
#define UNKNOWNRORI_ERRNO_H

#include <errno.h>

#define OPERATION_NOT_PERMITTED_ERR 1
#define NO_SUCH_FILE_OR_DIR_ERR 2
#define NO_SUCH_PROCESS_ERR 3
#define INTERRUPTED_SYSCALL_ERR 4
#define IO_ERR 5
#define NO_SUCH_DEVICE_OR_ADDRESS_ERR 6
#define ARGS_TOO_LONG_ERR 7
#define EXEC_FORMAT_ERR 8
#define BAD_FILE_NUM_ERR 9
#define NO_CHILD_PROCCESS_ERR 10

#endif