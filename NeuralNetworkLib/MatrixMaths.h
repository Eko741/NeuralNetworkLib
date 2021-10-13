#pragma once
#include "Matrix.h"
class MatrixMaths {
public:
    Matrix* matrixMultiplication(Matrix* a, Matrix* b);
    double dotProduct(double* a, double* b, int size);
    void addRowVector(Matrix* a, Matrix* b);
};