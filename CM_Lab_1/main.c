#include <stdio.h>
#include "options.h" //Параметры системы

#include "utils/reader.h"
#include "methods/gauss_method.h"

void print_welcome(){
    printf("Hello! This program solves a system of linear algebraic equations using the Gaussian method.\nThe row of the matrix A|B is specified according to the template: ai1 ai2 ... || bi\n");
}

int main() {
    print_welcome();

    int n;
    printf("Enter matrix's size:");
    scanf("%d", &n);

    double a[MAXN][MAXN];
    double b[MAXN][1];

    enum READ_TYPE read_type = UNDEFINED;
    while (read_type != CONSOLE_READ && read_type != FILE_READ){
        printf("Enter number of read type (1 - console, 2 - file):");
        scanf("%d", &read_type);
    }
    enum READ_STATUS read_status = read_matrix(read_type, a, b, n);
    switch (read_status) {
        case OPEN_FILE_ERROR:
            printf("ERROR: Couldn't open file\n");
            return 1;

        case INCORRECT_FORMAT:
            printf("ERROR: Incorrect format of matrix\n");
            return 1;

        case READ_CORRECT:
            printf("\nEntered matrix (A|B) is:\n");
            print_triangle_matrix(a, b, n);

            double x[MAXN][1];
            enum RESULT_STATUS result_status = gauss(a, b, x, n);
            switch (result_status) {
                case NO_SOLUTION:
                    printf("Determinant = 0; There are no solutions or there are an infinite number of them.\n");
                    return 1;

                case FIND_SOLUTION:
                    printf("Result (x) is:\n");
                    print_vector(x,n);
                    printf("\n");

                    double r[MAXN][1];
                    get_discrepancy(a, b, x, r, n);

                    printf("Discrepancy (r) is:\n");
                    print_vector(r,n);
                    printf("\n");
                    return 0;
            }
    }
}
