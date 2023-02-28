//
// Created by user on 24.02.2023.
//

#include "utils.h"

double abs_double(double d){
    if (d > 0){
        return d;
    }
    else{
        return -d;
    }
}

void clone_square_matrix(double const matrix[MAXN][MAXN], double new_matrix[MAXN][MAXN], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            new_matrix[i][j] = matrix[i][j];
        }
    }
}

void clone_vector(double const matrix[MAXN][1], double new_matrix[MAXN][1], int n){
    for (int i = 0; i < n; i++){
        new_matrix[i][0] = matrix[i][0];
    }
}

void print_square_matrix(double const matrix[MAXN][MAXN], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

//Выводит треугольный вид матрицы
void print_triangle_matrix(double a[MAXN][MAXN],double b[MAXN][1], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%.2f ", a[i][j]);
        }
        printf("|| %.2f \n", b[i][0]);
    }
    printf("\n");
}

void print_vector(double const matrix[MAXN][1], int n){
    printf("[");
    for (int i = 0; i < n; i++){
        printf("%.6f ", matrix[i][0]);
    }
    printf("]\n");
}

void create_random_square_matrix(double matrix[MAXN][MAXN], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            matrix[i][j] = (double) (rand()%100)/10; //Рандомное дробное число от 0 до 10
        }
    }
}





