#ifndef COMPLEX_H
#define COMPLEX_H
#include "Logger.h"

class Complex{
public:
    Complex(double m_real = 0, double m_imaginary = 0);
    
    Logger log {"Complex"};
    
    void printExpNumber();

    void printTrigNumber();

    void toPower(int n);

    void complexSquare(double n);

    friend Complex operator+(const Complex &n1, const Complex &n2);
    friend Complex operator-(const Complex &n1, const Complex &n2);
    friend Complex operator*(const Complex &n1, const Complex &n2);
    friend Complex operator/(const Complex &n1, const Complex &n2);

    friend std::ostream& operator<<(std::ostream &out, const Complex &cNum);
    friend std::istream& operator>>(std::istream &in, Complex &cNum);
    
    friend bool operator==(const Complex &n1, const Complex &n2);
    friend bool operator!=(const Complex &n1, const Complex &n2);

private:
    double real, imaginary;
};

Complex operator+(const Complex &n1, const Complex &n2);
Complex operator-(const Complex &n1, const Complex &n2);
Complex operator*(const Complex &n1, const Complex &n2);
Complex operator/(const Complex &n1, const Complex &n2);

std::istream& operator>>(std::istream &in, Complex &cNum);
std::ostream& operator<<(std::ostream &out, const Complex &cNum);

bool operator==(const Complex &n1, const Complex &n2);
bool operator!=(const Complex &n1, const Complex &n2);
#endif