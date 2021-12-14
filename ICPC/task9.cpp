#include <iostream>

using namespace std;

int main()
{
    int N, n1, i;
    i = 1;
    n1 = 1;

    cin >> N;
    while (n1 < N) {
        i++;
        n1 += i;
    }
    if (i - 1 == 0){
        cout << 1 << ' ';
    } else {
        cout << i-1 << ' ';
    }
    n1 = n1 - (i + (i-1));


    while (i + n1 <= N) {
        i++;
    }
}