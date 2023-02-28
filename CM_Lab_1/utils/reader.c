//
// Created by user on 25.02.2023.
//

#include "reader.h"

enum READ_STATUS read_matrix(enum READ_TYPE read_type, double a[MAXN][MAXN], double b[MAXN][1], int n) {
    enum READ_STATUS read_status;
    if (read_type == CONSOLE_READ) {
        read_status = console_read(a, b, n);
    }
    if (read_type == FILE_READ) {
        char file_name[MAX_STR];
        printf("Enter file name:");
        scanf("%s", file_name);

        read_status = file_read(file_name, a, b, n);
    }
    return read_status;
}

enum READ_STATUS console_read(double a[MAXN][MAXN], double b[MAXN][1], int n){
    int flag;
    printf("Enter a matrix (A|B). The row of the matrix (A|B) is specified according to the template: ai1 ai2 ... || bi: \n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            flag = scanf("%lf ", &a[i][j]);
            if ( flag == 0 || flag == EOF) return INCORRECT_FORMAT;
        }
        flag = scanf("|| %lf", &b[i][0]);
        if ( flag == 0 || flag == EOF) return INCORRECT_FORMAT;
    }
    return READ_CORRECT;
}

enum READ_STATUS file_read(char* file_name, double a[MAXN][MAXN], double b[MAXN][1], int n){
    FILE *file = fopen(file_name, "r");

    if (!file){
        return OPEN_FILE_ERROR;
    }

    int flag;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            flag = fscanf(file,"%lf ", &a[i][j]);
            if ( flag == 0 || flag == EOF){
                fclose(file);
                return INCORRECT_FORMAT;
            }
        }
        flag = fscanf(file,"|| %lf", &b[i][0]);
        if ( flag == 0 || flag == EOF){
            fclose(file);
            return INCORRECT_FORMAT;
        }
    }

    fclose(file);
}