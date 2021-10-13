// NeuralNetworkLib.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Matrix.h"
#include "MatrixMaths.h"
class ActivationFunctions {
public:
    static void ReLU(double *a ) {
        *a = (*a < 0) ? 0 : *a;
    }

    void GeLU(double *a) {
    
    }
};

int main() {
    
    
    MatrixMaths m = MatrixMaths();
   
    Matrix* a = new  Matrix(4, 6);
    Matrix* b = new Matrix(6, 2);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 6; j++)
            a->setValueAt(i, j, i + j * i);
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 2; j++)
            b->setValueAt(i, j, -(i + j * i));

    

    Matrix* d = new Matrix(1, 2);
    d->setValueAt(0, 0, 140);
    d->setValueAt(0, 1, 200);
    a->print();
    b->print();

    Matrix* c = m.matrixMultiplication(a, b);
    c->print();
    std::cout << "\n";
    m.addRowVector(c, d);
    c->print();
    c->activationFunction(&ActivationFunctions::ReLU);
    std::cout << "\n";
    c->print();
    double e = c->getValueAt(0, 0);
    
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
