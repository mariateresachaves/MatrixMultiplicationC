//
//  randMatrix.c
//  MatrixMultiplication
//
//  Created by Maria Teresa Chaves on 09/02/2018.
//  Copyright © 2018 Maria Teresa Chaves. All rights reserved.
//

#include "randMatrix.h"

void randMatrix(int **matrix, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            matrix[i][j] = rand() % 100 + 1; //random number between 1 and 100
        }
    }
}
