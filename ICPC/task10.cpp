//task 10 wip
#include <iostream>
//#include <vector>
using namespace std;

int main()
{
    int hh, mm, ss, cntr, h10, h1, m10, m1,s10, s1, temp;
    char s;
    //vector<int> nums (6);

    cin >> hh >> s >> mm >> s >> ss;

    h10 = hh / 10;
    h1 = hh % 10;
    m10 = mm / 10;
    m1 = mm % 10;
    s10 = ss / 10;
    s1 = ss % 10;


    if (s1 < 6) {
        temp = s10;
        s10 = s1;
        s1 = temp;
    }
    else if (s1 >= 6 && m1 < 6 && s10 > m1) {
        temp = m1;
        m1 = s10;
        s10 = temp;
    }
    else if (s1 >= 6 && m1 < 6 && s10 < m1) {
        temp = m1;
        m1 = s10;
        s10 = temp;
    }
    if (s1 >= 6 && m1 < 6 && s10 > m1) {
        temp = m1;
        m1 = s10;
        s10 = temp;
    }
    else if (s1 >= 6 && m1 < 6 && s10 < m1) {
        temp = m1;
        m1 = s10;
        s10 = temp;
    }
    cout << h10 << h1 << " " << m10 << m1 << " "<< s10 << s1 << endl;
    //cout << cntr;

}