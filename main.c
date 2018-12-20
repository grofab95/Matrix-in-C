#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void refillMatrixWithRandomNumbers(int **matrix, int rows, int columns){
    int range_max = -7;
    int range_min = 7;
    srand(time(NULL));
    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
            matrix[i][j] = (double)rand() / (RAND_MAX + 1) * (range_max - range_min) + range_min;
        }
    }
}

void printMatrix(int **matrix, int rows, int columns){
    printf("\n");
    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
            if(matrix[i][j] < 0){
                printf("[%i]  ", matrix[i][j]);
            } else {
                printf("[ %i]  ", matrix[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void clearSelectedTab(int selectedTab[], int columns){
    for(int i = 1; i <= columns; i++){
        selectedTab[i] = 0;
    }
}

int countSumOfNumbersInSelectedRow(int **matrix, int columns, int selected_row){
    int sum = 0;
    for(int i = 1; i <= columns; i++){
        sum += matrix[selected_row][i];
    }
    return sum;
}

void refillTabWithSumFromNegativeRows(int **matrix, int rows, int columns, int tabWithSum[]){
    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
            tabWithSum[i] = countSumOfNumbersInSelectedRow(matrix, j, i);
        }
    }
}

int checkForNegativeNumbersInSelectedRow(int **matrix, int columns, int selected_row){
    for(int i = 1; i <= columns; i++){
        if(matrix[selected_row][i] < 0){
            return 1;
        }
    }
    return false;
}

void printSumOfNegativeRows(int **matrix, int tabWithSum[], int rows, int columns){
    printf("-- Sumy liczb w wierszach, ktore zawieraja co najmniej jedna liczbe ujemna -- \n");
    for(int i = 1; i <= rows; i++){
            if(checkForNegativeNumbersInSelectedRow(matrix, columns, i)){
                if(tabWithSum[i] < 0){
                    printf("Suma liczb w wierszu[%i]:  %i\n", i, tabWithSum[i]);
                } else {
                    printf("Suma liczb w wierszu[%i]:   %i\n", i, tabWithSum[i]);
                }
            }
    }
}

int main()
{
    int rows, columns;
    printf("Podaj liczbe wierszy: ");
    scanf("%i", &rows);
    printf("Podaj liczbe kolumn: ");
    scanf("%i", &columns);
    int **matrix = (int**) malloc(rows*sizeof(int*));
    for(int i = 1; i <= rows; i++){
        matrix[i] = (int*) malloc(columns*sizeof(int));
    }
    int tabWithSum[rows];
    clearSelectedTab(tabWithSum, columns);
    refillMatrixWithRandomNumbers(matrix, rows, columns);
    printMatrix(matrix, rows, columns);
    refillTabWithSumFromNegativeRows(matrix, rows, columns, tabWithSum);
    printSumOfNegativeRows(matrix, tabWithSum, rows, columns);
    free(matrix);
}


