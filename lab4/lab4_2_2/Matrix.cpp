#include "Matrix.h"

Matrix::Matrix() : rows(0), cols(0){}

Matrix::Matrix(const int m_rows, const int m_cols) : rows(m_rows), cols(m_cols) {
    matrix = new double* [rows];
    for (int i = 0; i < rows; i++){
        matrix[i] = new double[cols];
    }
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            matrix[i][j] = 0;
        }   
    }
}

Matrix Matrix::M(const int &a, const int &b){
    Matrix m {rows - 1, cols - 1};  
    int di = 0, dj = 0;
    for (int i = 0; i < m.rows; i++){
        if (i == a) di = 1;
        dj = 0; 
        for (int j = 0; j < m.cols; j++){
            if (j == b) dj = 1;
            m.matrix[i][j] = matrix[i + di][j + dj];
        }
    }
    return m;
}

double* Matrix::getPointer(const int &i, const int &j){
    return &matrix[i][j];
}

double& Matrix::getLink(const int &i, const int &j){
    return matrix[i][j];
}

double Matrix::getDeterminant(){
    double d = 0;
    if (rows == cols){
        if (rows == 1){
            return matrix[0][0];
        } else if (rows == 2){
            return matrix[0][0] * matrix[1][1] - (matrix[1][0] * matrix[0][1]);
        } else {
            for (int j = 0; j < rows; j++){
                d += pow(-1, 1+j) * matrix[1][j] * M(1, j).getDeterminant();
            }
            return d;
        }
    } else {
        MathError mE;
        mE.print();
    }
}

Matrix Matrix::Tmatrix(){
    Matrix m {rows, cols};
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            m.matrix[i][j] = matrix[j][i];
        }
    }
    return m;
}

Matrix Matrix::m1power(){
    double d = this->getDeterminant();
    Matrix m{rows, cols};
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            m.matrix[i][j] = pow(-1, i+j)*M(i, j).getDeterminant();
        }
    }
    m = m.Tmatrix();
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            m.matrix[i][j] /= this->getDeterminant();
        }
    }
    return m;
}

Matrix operator+(const Matrix &m1, const Matrix &m2){
    if (!(m1.cols == m2.cols && m1.rows == m2.rows)){
        MathError mE;
        mE.print();
    }
    Matrix m {m1.rows, m1.cols};
    for (int i = 0; i < m1.rows; i++){
        for (int j = 0; j < m1.cols; j++){
            m.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
        }
    }
    return m;
}

Matrix operator-(const Matrix &m1, const Matrix &m2){
    if (!(m1.cols == m2.cols && m1.rows == m2.rows)){
        MathError mE;
        mE.print();
    }
    Matrix m {m1.rows, m1.cols};
    for (int i = 0; i < m1.rows; i++){
        for (int j = 0; j < m1.cols; j++){
            m.matrix[i][j] = m1.matrix[i][j] - m2.matrix[i][j];
        }
    }
    return m;
}

Matrix operator*(const Matrix &m1, const Matrix &m2){
    if (!(m1.cols == m2.rows)){
        MathError mE;
        mE.print();
    }
    Matrix m{m1.rows, m2.cols};
    for (int i = 0; i < m1.rows; i++){
        for (int j = 0; j < m2.cols; j++){
            for (int k = 0; k < m1.cols; k++){
                    m.matrix[i][j] += m1.matrix[i][k] * m2.matrix[k][j];
            }
        }
    }
    return m;
    
}

Matrix operator/(const Matrix &m1, Matrix &m2){
    return m1 * m2.m1power();
}

ostream& operator<<(ostream &out, const Matrix &m){
    for (int i = 0; i < m.rows; i++){
        for (int j = 0; j < m.cols; j++){
            out << m.matrix[i][j] << ' ';
        }
        out << endl;
    }
    return out;
}

istream& operator>>(istream &in, Matrix &m){
    int n;
    for (int i = 0; i < m.rows; i++){
        for (int j = 0; j < m.cols; j++){
            in >> n;
            m.matrix[i][j] = n;
        }
    }
    return in;
}

bool operator==(const Matrix &m1, const Matrix &m2){
        if (!(m1.rows == m2.rows && m1.cols == m2.cols)){
            LogicError lE;
            lE.print();
        }
        for (int i = 0; i < m1.rows; i++){
            for (int j = 0; j < m1.cols; j++){
                if (m1.matrix[i][j] != m2.matrix[i][j]){
                    return 0;
                }
            }
        }
        return 1;
}

bool operator!=(const Matrix &m1, const Matrix &m2){
    if (!(m1.rows == m2.rows && m1.cols == m2.cols)){
        LogicError lE;
        lE.print();
    }
    for (int i = 0; i < m1.rows; i++){
        for (int j = 0; j < m1.cols; j++){
            if (m1.matrix[i][j] == m2.matrix[i][j]){
                return 0;
            }
        }
    }
    return 1;
}
    