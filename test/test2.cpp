#include <iostream>
#include <cmath>
#include "../Utilities/utilities.h"
using namespace std;

class Bern{
public:
    Bern(){}
    
    double calculate(int n, int k, double p){
        //! C = n!/(n-k)!*k!
        //! P = C*p^k*q^(n-k)
        C = fact(n) / (fact(n - k) * fact(k));
        P = C * pow(p, k) * pow(1 - p, n - k);
        return P;
    }

private:
    uint32_t C;
    double P;
};






int main(){
    Bern bern;
    int n, k;
    double p;
    bool toggle = 1;
    while (toggle){
        cout << "1 - Use Bernulli\n0 - Exit\n>>>";
        int choose;
        cin >> choose;
        switch (choose) {
            case 1:
                cout << "Enter n, k, p >>";
                cin >> n, k, p;
                cout << bern.calculate(n, k, p) << endl;
            break;
            case 0:
                toggle = 0;
            break;
        }
    }

    return 0;
}