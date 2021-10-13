#pragma once
class Matrix {
private:
    double* matrix;
    int length;
    int width;
    int  size;

public:
    Matrix(int sizeY, int sizeX) : width(sizeX), length(sizeY), size(sizeX * sizeY), matrix(new double[sizeX * sizeY]) {}
    ~Matrix() { delete[] matrix; }
    void activationFunction(void AF(double*));
    double getValueAt(int y, int x) const;
    double* getRow(int row) const;
    double* getColumn (int column) const;
    void setValueAt(int y, int x, double a);
    void transpose();
    void print();
    int getLength() const { return length; }
    int getWidth() const { return width; }
    int getSize() const { return size; }
};
