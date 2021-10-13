#include "MatrixMaths.h" 
#include <iostream>
using namespace std;
Matrix* MatrixMaths::matrixMultiplication(Matrix* a, Matrix* b) {
    if ((a->getWidth() != b->getLength())) {
        cout << "MatrixMultiplication: Matrises don't match. Matrix a is " << a->getLength() << " * " << a->getWidth() << ", matrix b is " << b->getLength() << " * " << b->getWidth() << "\n";
        exit(3);
    }
    Matrix* c = new Matrix(a->getLength(), b->getWidth());
    for (int i = 0; i < c->getLength(); i++) {
        for (int j = 0; j < c->getWidth(); j++) {
             c->setValueAt(i, j, dotProduct(a->getRow(i), b->getColumn(j), a->getWidth()));
        }
	}
    return c;
}

double MatrixMaths::dotProduct(double* a, double* b, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += a[i] * b[i];
    }
    return sum;
}

void MatrixMaths::addRowVector(Matrix* a, Matrix* b) {
    if (a->getWidth() != b->getWidth()) {
        cout << "AddRowVector: Matrix and vector don't match. Matrix is " << a->getLength() << " * " << a->getWidth() << ", vector is " << b->getWidth() << " long" << "\n";
        exit(3);
    }

    if (b->getLength() != 1) {
        cout << "AddRowVector: b is not a vector" "\n";
        exit(3);
    }
    for (int i = 0; i < a->getLength(); i++) {
        for (int j = 0; j < b->getWidth(); j++) {
            a->setValueAt(i, j, a->getValueAt(i, j) + b->getValueAt(0, j));
        }
    }
}