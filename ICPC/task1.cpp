#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    double M, L, R;
    vector<int> N;

    cin >> M >> L;

    for (int i = 0; i < M; i++){
        cin >> R;
        if (double(2 * 3.14 * R) > L){
            N.push_back(-1);
        } else {
            if (double(3 * R * sqrt(3)) < L){
                N.push_back(3);
                continue;
            }
            if (4 * R < L){
                N.push_back(4);
                continue;
            }
        }
    }


    for (auto n : N){
        cout << n << "  ";
    }
    return 0;
}