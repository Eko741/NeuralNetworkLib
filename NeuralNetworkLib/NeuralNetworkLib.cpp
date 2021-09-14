// NeuralNetworkLib.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>;

class Matrix {
private:
    double* matrix;
    int length;
    int width;
    int  size;

public:
    
    
    Matrix(int sizeY, int sizeX) {
        width = sizeX;
        length = sizeY;
        size = sizeX * sizeY;
        matrix = new double[size];
      
    }

    ~Matrix() {
        delete[] matrix;
    }
    
    double getValueAt(int y, int x) {
        if (x >= width || x < 0 || y < 0 || y >= length ) {
            std::cout << "getValueAt: Out of range. Your matrix is " << width << " * " << length << "\n";
            exit (3);
        }
        return *(matrix + x + y * width);
    }

    double* getRow(int row) {
        if (row >= length || row < 0){
            std::cout << "getRow: Out of range. Your matrix is " << width << " * " << length << "\n";
            exit(3);
        }
        double* a = new double[width];
        for (int i = 0; i < width; i++) {
            a[i] = matrix[i + row * width];
         }
        return a;
    }

    double* getColumn(int column) {
        if (column >= width || column < 0) {
            std::cout << "getRow: Out of range. Your matrix is " << width << " * " << length << "\n";
            exit(3);
        }
        double* a = new double[length];
        for (int i = 0; i < length; i++) {
            a[i] = matrix[i * width + column];
        }
        return a;
    }


    void setValueAt(int y, int x, double a) {
        if (x >= width || x < 0 || y < 0 || y >= length) {
            std::cout << "setValueAt: Out of range. Your matrix is " << length << " * " << width << "\n";
            exit(3);
        }

        *(matrix + x + y * width) = a;
    }



    void transpose() {
        double *a = new double[size];
        for (int i = 0; i < width; i++)
            for (int j = 0; j < length; j++)
                a[i + j * width] = matrix[i * length + j];
        int tmp = width;
        width = length;
        length = tmp;
        delete matrix;
        matrix = a;
        a = nullptr;
    }

    void print() {
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < width; j++) std::cout << getValueAt(i, j) << " ";
            std::cout << "\n";
        }

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
};


class MatrixMaths {
public:
    Matrix* matrixMultiplication(Matrix *a, Matrix *b) {
        if ((a->getWidth() != b->getLength())) {
            std::cout << "MatrixMultiplication: Matrises don't match. Matrix a is " << a->getLength() << " * " << a->getWidth() << ", matrix b is " << b->getLength() << " * " << b->getWidth() << "\n";
            exit(3);
        }
        Matrix *c = new Matrix(a->getLength(), b->getWidth());
        for (int i = 0; i < c->getLength(); i++) {
            for (int j = 0; j < c->getWidth(); j++) {
                c->setValueAt(i, j, dotProduct(a->getRow(i), b->getColumn(j), a->getWidth()));
            }
        }
        return c;
    }

    double dotProduct(double *a, double *b, int size) {
        double sum = 0;
        for (int i = 0; i < size; i++) {
            sum += a[i] * b[i];
        }
        return sum;
    }

    void addRowVector(Matrix *a, Matrix *b) {
        if (a->getWidth() != b->getWidth()) {
            std::cout << "AddRowVector: Matrix and vector don't match. Matrix is " << a->getLength() << " * " << a->getWidth() << ", vector is " << b->getWidth() << " long" << "\n";
            exit(3);
        }

        if (b->getLength() != 1) {
            std::cout << "AddRowVector: b is not a vector" "\n";
            exit(3);
        }

        for (int i = 0; i < a->getLength(); i++) {
            for (int j = 0; j < b->getWidth(); j++) {
                a->setValueAt(i, j, a->getValueAt(i, j) + b->getValueAt(0, j));
            }
        }

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
            b->setValueAt(i, j, i + j * i);

    

    Matrix* d = new Matrix(1, 2);
    d->setValueAt(0, 0, 1);
    d->setValueAt(0, 1, 4);
    std::cout << sizeof(d) << "\n";
    //std::cout << *(&d + 1) - d << "\n";
    Matrix* c = m.matrixMultiplication(a, b);
    c->print();
    std::cout << "\n";
    m.addRowVector(c, d);
    c->print();
    std::cout << "\n";
    
    
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
