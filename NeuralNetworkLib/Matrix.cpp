#include "Matrix.h"
#include <iostream>
using namespace std;

void Matrix::activationFunction(void AF(double*)) {
    void (*fcn)(double*) { AF };
    for (int i = 0; i < size; i++) {
        fcn(&matrix[i]);
    }
}

double Matrix::getValueAt(int y, int x) const{
    if (x >= width || x < 0 || y < 0 || y >= length) {
        cout << "getValueAt: Out of range. Your matrix is " << width << " * " << length << "\n";
        exit(3);
    }
    return *(matrix + x + y * width);
}

double* Matrix::getRow(int row) const {
    if (row >= length || row < 0){
        cout << "getRow: Out of range. Your matrix is " << width << " * " << length << "\n";
        exit(3);
    }
    double* a = new double[width];
    for (int i = 0; i < width; i++) {
        a[i] = matrix[i + row * width];
    }
    return a;
}

double* Matrix::getColumn(int column) const {
    if (column >= width || column < 0) {
        cout << "getRow: Out of range. Your matrix is " << width << " * " << length << "\n";
        exit(3);
    }
    double* a = new double[length];
    for (int i = 0; i < length; i++) {
        a[i] = matrix[i * width + column];
    }
    return a;
}

void Matrix::setValueAt(int y, int x, double a) {
    if (x >= width || x < 0 || y < 0 || y >= length) {
        cout << "setValueAt: Out of range. Your matrix is " << length << " * " << width << "\n";
        exit(3);
    }

    *(matrix + x + y * width) = a;
}

void Matrix::transpose() {
    double* a = new double[size];
    for (int i = 0; i < width; i++)
        for (int j = 0; j < length; j++)
            a[i + j * width] = matrix[i * length + j];
    int tmp = width;
    width = length;
    length = tmp;
    delete matrix;
    matrix = a;
}

void Matrix::print() {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) cout << getValueAt(i, j) << " ";
        cout << "\n";
    }

}