//
// Created by user on 25.02.2023.
//

#include "gauss_method.h"

//Смена строк
void swap_strings(double a[MAXN][MAXN],double b[MAXN][1], int n, int first_i, int second_i){
    double a_str[MAXN];
    for (int j = 0; j < n; j++){
        a_str[j] = a[first_i][j];
    }

    for (int j = 0; j < n; j++){
        a[first_i][j] = a[second_i][j];
        a[second_i][j] = a_str[j];
    }

    double b_str = b[first_i][0];
    b[first_i][0] = b[second_i][0];
    b[second_i][0] = b_str;
}

//Определитель треугольной матрицы
double get_determinant(double const a[MAXN][MAXN], int n){
    double det = 1;
    for (int i = 0; i < n; i++){
        det *= a[i][i];
    }
    return det;
}

//Прямой ход
void straight_run(double a[MAXN][MAXN], double b[MAXN][1], int n){
    //Цикл по диагонали матрицы
    for (int i = 0; i < n-1; i++){

        //Проверка на (a[i][i] != 0) и смена строк
        int nullColumn = 1; //true (default)
        for (int tmp_i = i; tmp_i < n; tmp_i++){
            if (a[tmp_i][i] != 0){
                nullColumn = 0; //false
                swap_strings(a,b,n,i,tmp_i);
                break;
            }
        }

        //Если столбец не нулевой
        if (!nullColumn){
            for (int k = i+1; k < n; k++){
                double c = a[k][i]/a[i][i];
                a[k][i] = 0;
                for (int j = i+1; j < n; j++){
                    a[k][j] -= c*a[i][j];
                }
                b[k][0] -= c*b[i][0];
            }
        }
    }
}

//Обратный ход
void return_run(double a[MAXN][MAXN], double b[MAXN][1], double x[MAXN][1], int n){
    for (int i = n-1; i > -1; i--){
        double s = 0;
        for (int j = i + 1; j < n; j++){
            s += a[i][j]*x[j][0];
        }
        x[i][0] = (b[i][0] - s)/a[i][i];
    }
}

//Метод Гаусса
enum RESULT_STATUS gauss(double const source_a[MAXN][MAXN], double const source_b[MAXN][1], double x[MAXN][1], int n){
    double a[MAXN][MAXN];
    double b[MAXN][1];

    clone_square_matrix(source_a, a, n);
    clone_vector(source_b, b, n);

    straight_run(a,b,n);
    printf("Triangle matrix (A|B) is:\n");
    print_triangle_matrix(a, b, n); //Вывод треугольной матрицы

    double det = get_determinant(a, n);
    printf("The matrix determinant det(A) = %f\n\n", det);

    if (abs_double(det) < EPS){
        return NO_SOLUTION;
    }
    else{
        return_run(a, b, x, n);
        return FIND_SOLUTION;
    }
}

//Рассчитать вектор невязок
void get_discrepancy(double const a[MAXN][MAXN], double const b[MAXN][1], double const x[MAXN][1], double r[MAXN][1], int n){
    for (int i = 0; i < n; i++){
        double tmp_r = 0;
        for (int j = 0; j < n; j ++){
            tmp_r += a[i][j]*x[j][0];
        }
        r[i][0] = tmp_r - b[i][0];
    }
}