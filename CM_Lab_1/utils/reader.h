//
// Created by user on 25.02.2023.
//

#ifndef CM_LAB_1_READER_H
#define CM_LAB_1_READER_H

#include <stdio.h>
#include "../options.h"

enum READ_TYPE{
    UNDEFINED = 0,
    CONSOLE_READ,
    FILE_READ
};

enum READ_STATUS{
    READ_CORRECT = 0,
    OPEN_FILE_ERROR,
    INCORRECT_FORMAT
};

enum READ_STATUS read_matrix(enum READ_TYPE read_type, double a[MAXN][MAXN], double b[MAXN][1], int n);
enum READ_STATUS console_read(double a[MAXN][MAXN], double b[MAXN][1], int n);
enum READ_STATUS file_read(char* file_name, double a[MAXN][MAXN], double b[MAXN][1], int n);

#endif //CM_LAB_1_READER_H
