#include <iostream>
#include "Matrix.h"
using namespace std;

int main(){
    LogicError lE;
    MathError mE;
    Matrix m{3, 3};
    Matrix m2{2,3};

    cout << m + m2;



    return 0;
}