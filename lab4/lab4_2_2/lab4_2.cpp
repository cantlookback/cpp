#include <iostream>
#include "Matrix.cpp"
using namespace std;

int main(){
    LogicError lE;
    MathError mE;
    Matrix m{3, 3};
    Matrix m2{3,3};

    cin >> m >> m2;

    cout << m + m2;



    return 0;
}