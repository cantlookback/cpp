#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <cmath>
#include "IError.h"
using namespace std;
class Matrix{
public:
    Matrix();
    Matrix(const int m_cols, const int m_rows);

    
    double& getLink(const int &i, const int &j);
    double* getPointer(const int &i, const int &j);
    Matrix m1power();

    friend Matrix operator+(const Matrix &m1, const Matrix &m2);
    friend Matrix operator-(const Matrix &m1, const Matrix &m2);
    friend Matrix operator*(const Matrix &m1, const Matrix &m2);
    friend Matrix operator/(const Matrix &m1, const Matrix &m2);
    friend ostream& operator<<(ostream &out, const Matrix &m);
    friend istream& operator>>(istream &in, Matrix &m1);
    friend bool operator==(const Matrix &m1, const Matrix &m2);
    friend bool operator!=(const Matrix &m1, const Matrix &m2);
private:
    Matrix Tmatrix();
    double getDeterminant();
    Matrix M(const int &i, const int &j);
    double** matrix;
    int cols, rows;
};
#endif