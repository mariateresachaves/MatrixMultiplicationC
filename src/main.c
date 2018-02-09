//
//  main.c
//  Learn
//
//  Created by Maria Teresa Chaves on 06/02/2018.
//  Copyright © 2018 Maria Teresa Chaves. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "randMatrix.h"

int main(int argc, const char * argv[]) {
    int n = 700;
    
    // Result matrices inicialization
    int **result1;
    result1 = malloc(n*(sizeof(*result1)));
    for (int i=0; i<n; i++)
        result1[i] = malloc(n*(sizeof(*result1[i])));
    
    int **result2;
    result2 = malloc(n*(sizeof(*result2)));
    for (int i=0; i<n; i++)
        result2[i] = malloc(n*(sizeof(*result2[i])));
    
    // Matrices to operate inicialization
    int **matrix_A;
    matrix_A = malloc(n*(sizeof(*matrix_A)));
    for (int i=0; i<n; i++)
        matrix_A[i] = malloc(n*(sizeof(*matrix_A[i])));
    
    int **matrix_B;
    matrix_B = malloc(n*(sizeof(*matrix_B)));
    for (int i=0; i<n; i++)
        matrix_B[i] = malloc(n*(sizeof(*matrix_B[i])));
    
    // Fill 2 matrices with random values between 1 and 100
    randMatrix(matrix_A, n);
    randMatrix(matrix_B, n);
    
    clock_t begin1 = clock();
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                result1[i][j] += matrix_A[i][k] * matrix_B[k][j];
            }
        }
    }
    
    clock_t end1 = clock();
    
    clock_t begin2 = clock();
    
    for(int i=0; i<n; i++) {
        for(int k=0; k<n; k++) {
            for(int j=0; j<n; j++) {
                result2[i][j] += matrix_A[i][k] * matrix_B[k][j];
            }
        }
    }
    
    clock_t end2 = clock();
    
    printf("--- 1st Time: %f seconds ---\n", (double)(end1 - begin1) / CLOCKS_PER_SEC);
    printf("--- 2nd Time: %f seconds ---\n", (double)(end2 - begin2) / CLOCKS_PER_SEC);
    
    return 0;
}
