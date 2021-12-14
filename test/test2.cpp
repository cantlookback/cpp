#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int i, m, j;
    float x,sum,S,S1,S2,fac;
    cout << ("Ввод m=");
    cin >> m;
    i = 1;
    sum = 0;
    while(i <= 2*m) {
        x = -(m + 28.)/i;
        fac = 1;
        for (j = 1; j <= (2*i - 1); j++) {
            fac = fac * j;
        }
        sum += log((pow(x, 2) + (2.0 / i)) / fac);
        i++;
    }
    S = sum;
    cout << " Для цикла WHILE результат = " << S << endl;
    i = 1;
    sum = 0;
    do {
        x = -(m + 28.) / i;
        fac = 1;
        for (j = 1; j <= (2*i - 1); j++) {
            fac = fac * j;
        }
        sum += log((pow(x, 2)+(2.0 / i))/fac);
        i++;
    } while(i <= 2*m);
    S1 = sum;
    cout << " Для цикла DO..WHILE результат = " << S1 << endl;
    sum = 0;
    for(i = 1; i <= 2*m; i++){
        x = -(m + 28.) / i;
        fac = 1;
        for (j = 1; j <= (2*i - 1); j++) {
            fac = fac * j;
        }
        sum += log((pow(x,2) + (2.0 / i)) / fac);
    }
    S2 = sum;
    cout << " Для цикла FOR результат = " << S2 << endl;
    return 0;
}