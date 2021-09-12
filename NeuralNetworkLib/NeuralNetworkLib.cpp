// NeuralNetworkLib.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>;

class Matrix{
public:
    Matrix(int sizeY, int sizeX) {

    }
}


class MatrixMaths {
public:
    double** matrixMultiplication(double *a, double *b) {

        return nullptr;
    }

    void printMatrix(double *a) {
        int arrSizeY = *(&a + 1) - a;
        int arrSizeX = *(&a[0] + 1) - a[0];
        std::cout << arrSizeX << "\n";
        std::cout << arrSizeY << "\n";

        for (int i = 0; i < arrSizeY;) {

        }
    }
};

int main() {
    

    MatrixMaths m = MatrixMaths();
    std::cout << a[1][0] << "\n";
    m.printMatrix(a);
    //m.matrixMultiplication(a, a);
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
