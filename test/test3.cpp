#include <iostream>
#include <cmath>
using namespace std;

long double fact(int x){
    int f = 1;
    if (x == 1){
        return 1;
    } else if (x == 2){
        return 2;
    } else {
        for (int i = 2; i <= x; i++){
            f *= i;
        }
        return f;
    }
}

int main(){
    long double S = 0, i = 1, x, m, t, d;

    cin >> m;
    //!WHILE 
    while (i <= 2*m){
        x = -(m + 28) / i;
        t = pow(x, 2) + 2 / i;
        d = fact(2*i - 1);
        S += log(t / d);
        i++;
    }

    cout << S << endl;
    S = 0;
    i = 1;
    //!DO WHILE
    do {
        x = -(m + 28) / i;
        t = pow(x, 2) + 2 / i;
        d = fact(2*i - 1);
        S += log(t / d);
        i++;
    } while (i <= 2*m);

    cout << S << endl;
    S = 0;
    //!FOR
    for (i = 1; i <= 2*m; i++){
        x = -(m + 28) / i;
        t = pow(x, 2) + 2 / i;
        d = fact(2*i - 1);
        S += log(t / d);
        // cout << x << "  " << log(t/d) << "   " << S << endl;
    }

    cout << S;
}