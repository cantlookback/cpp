#include "Complex.h"
#include "Logger.h"
#include <iostream>
#include <math.h>
using namespace std;

Complex::Complex(double m_real, double m_imaginary) : real(m_real), imaginary(m_imaginary){}

void Complex::printExpNumber(){
    Logger log {"printExpnumber"};
    double z = sqrt(pow(real, 2) + pow(imaginary, 2));
    double fi = atan(imaginary / real);

    cout << z << "e^" << fi << 'i' << endl;
}

void Complex::printTrigNumber(){
    Logger log {"printTrigNumber"};
    double z = sqrt(pow(real, 2) + pow(imaginary, 2));
    double fi = atan(imaginary / real);
    cout << z << " * (cos" << fi << " + isin" << fi << ')' << endl;
}

void Complex::toPower(int n){
    Logger log {"toPower"};
    double z = sqrt(pow(real, 2) + pow(imaginary, 2));
    double fi = atan(imaginary / real);

    cout << pow(z, n) << " * (cos" << fi * n << " + isin" << fi * n << ')' << endl;
}

void Complex::complexSquare(double n){
    Logger log {"complexSquare"};
    double z = sqrt(pow(real, 2) + pow(imaginary, 2));
    double fi = atan(imaginary / real);

    for (int i = 0; i < n; i++){
        cout << pow(z, 1/n) << " * (cos(" << fi << " + 2πk / " << n << ") + isin(" << fi << " + 2πk / " << n << "))" << endl;
    }
}

Complex operator+(const Complex &n1, const Complex &n2){
        return {n1.real + n2.real, n1.imaginary + n2.imaginary};
    }
Complex operator-(const Complex &n1, const Complex &n2){
        return {n1.real - n2.real, n1.imaginary - n2.imaginary};
    }
Complex operator*(const Complex &n1, const Complex &n2){
        return {n1.real*n2.real - n1.imaginary*n2.imaginary, n1.real*n2.imaginary + n1.imaginary*n2.real};
    }
Complex operator/(const Complex &n1, const Complex &n2){
        return {(n1.real*n2.real - n1.imaginary*(-n2.imaginary)) / (pow(n2.real, 2) + pow(n2.imaginary, 2)),
                (n1.real*(-n2.imaginary) + n1.imaginary*n2.real) / (pow(n2.real, 2) + pow(n2.imaginary, 2))};
    }

istream& operator>>(istream &in, Complex &cNum){
        in >> cNum.real >> cNum.imaginary;
        return in;
    }
ostream& operator<<(ostream &out, const Complex &cNum){
        out << cNum.real << showpos << cNum.imaginary << "i" << noshowpos << endl;
        return out;
    }

bool operator==(const Complex &n1, const Complex &n2){
        return ((n1.real == n2.real) && (n1.imaginary == n2.imaginary));
    }
bool operator!=(const Complex &n1, const Complex &n2){
        return !((n1.real == n2.real) && (n1.imaginary == n2.imaginary));
    }