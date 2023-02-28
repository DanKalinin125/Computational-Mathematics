//
// Created by user on 24.02.2023.
//

#ifndef CM_LAB_1_GAUSS_METHOD_H
#define CM_LAB_1_GAUSS_METHOD_H

#include <stdio.h>
#include "../options.h"

#include "../utils/utils.h"

enum RESULT_STATUS{
    FIND_SOLUTION = 0,
    NO_SOLUTION
};

enum RESULT_STATUS gauss(double const a[MAXN][MAXN], double const b[MAXN][1], double x[MAXN][1], int n);
void get_discrepancy(double const a[MAXN][MAXN], double const b[MAXN][1], double const x[MAXN][1], double r[MAXN][1], int n);

#endif //CM_LAB_1_GAUSS_METHOD_H
