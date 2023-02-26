//
// Created by user on 24.02.2023.
//

#ifndef CM_LAB_1_UTILS_H
#define CM_LAB_1_UTILS_H

#include <stdio.h>
#include <stdlib.h>

#include "../options.h"

double abs_double(double d);

void clone_square_matrix(double const matrix[MAXN][MAXN], double new_matrix[MAXN][MAXN], int n);
void clone_vector(double const matrix[MAXN][1], double new_matrix[MAXN][1], int n);

void print_triangle_matrix(double a[MAXN][MAXN],double b[MAXN][1], int n);
void print_square_matrix(double const matrix[MAXN][MAXN], int n);
void print_vector(double const matrix[MAXN][1], int n);

void create_random_square_matrix(double matrix[MAXN][MAXN], int n);

#endif //CM_LAB_1_UTILS_H
