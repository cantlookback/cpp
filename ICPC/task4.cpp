#include <iostream>
#include <ctime>
using namespace std;

int main(){
    srand(time(0));
    int N, T, C;
    int cash, startCash;

    cin >> N >> T >> C;
    startCash = N * C;

    for (int i = 0; i < T; i++){
        if (C == 1){
            C++;
        } else {
            if ((rand() % 1) == 1){
                
                C++;
                N++;
            } else {
                cout << "s";
                C--;
                N--;
            }
        }
        cash = N * C;
    }

    cout << cash - startCash;

    return 0;
}