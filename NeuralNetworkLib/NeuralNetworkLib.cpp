// NeuralNetworkLib.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>;

class Matrix {
public:
    
    
    Matrix(int sizeY, int sizeX) {
        width = sizeX;
        length = sizeY;
        size = sizeX * sizeY;
        matrix = new double[size];
      
    }

    ~Matrix() {
        delete[] matrix;
        delete this;
    }
    
    double getValueAt(int x, int y) {
        if (x >= width || x < 0 || y < 0 || y >= length ) {
            std::cout << "Out of range. Your array is " << width << " * " << length << "\n";
            exit (3);
        }
        return *(matrix + (length*x) + y);
    }

    void setValueAt(int x, int y, double a) {
        if (x >= width || x < 0 || y < 0 || y >= length) {
            std::cout << "Out of range. Your array is " << width << " * " << length << "\n";
            exit(3);
        }

        *(matrix + (length*x) + y) = a;
    }

    void transpose() {

    }

    int getLength() {
        return length;
    }

    int getWidth() {
        return width;
    }

    int getSize() {
        return size;
    }


private:
    double* matrix;
    int length;
    int width;
    int  size;
};


class MatrixMaths {
public:
    Matrix matrixMultiplication(double *a, double *b) {

        //return nullptr;
    }

    void printMatrix(Matrix a) {
        for (int i = 0; i < a.getLength(); i++) {
            for (int j = 0; j < a.getWidth(); j++) std::cout << a.getValueAt(i, j);
        }
        std::cout << "\n";
    }
};

int main() {
    

    MatrixMaths m = MatrixMaths();
   
    Matrix a = Matrix(2, 2);
    a.setValueAt(1, 1, 1.01123123123);
    a.setValueAt(0, 1, 2.2);
    a.setValueAt(1, 0, 3.2);
    a.setValueAt(0, 0, 4.2);
    m.printMatrix(a);
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
