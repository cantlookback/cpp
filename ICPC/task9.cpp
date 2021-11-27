#include <iostream>

using namespace std;

int main()
{
    int64_t N, n1, i;
    i = 1;
    n1 = 1;

    cin >> N;
    while (n1 < N) {
        i++;
        n1 += i;
    }
    cout << i-1 << ' ';

    n1 = n1 - (i + (i-1));


    while (i + n1 <= N) {
        i++;
    }
    cout << i - 1;
}