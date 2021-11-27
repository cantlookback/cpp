#include <iostream>
#include <string>
#include <vector>
using namespace std;

int isprime(int num){
    if ((num * num) % 24 == 1)
    {
        return true;
    }

 return false;
}

int main(){
    int64_t X, A, B;
    string buf;
    int64_t minAB = LLONG_MAX;
    cin >> X;
    vector<int64_t> v;
        for (int i = 1; i <= 10; i++){
            buf = to_string(i) + to_string(X);
            if (!isprime(stoll(buf))){
                //cout << buf << endl;
                if (stoll(buf) < minAB){
                    minAB = stoll(buf);
                }
            }
            buf = to_string(X) + to_string(i-1);
            if (!isprime(stoll(buf))){
                //cout << buf << endl;
                if (stoll(buf) < minAB){
                    minAB = stoll(buf);
                }
            }
        }

    cout << minAB;

    return 0;
}