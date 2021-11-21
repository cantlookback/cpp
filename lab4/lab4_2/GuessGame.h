#ifndef GUESSGAME_H
#define GUESSGAME_H
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class GuessGame{
public:
    GuessGame(const int &m_N);

    void printField();

    void guess();

    void isWin();

private:
    vector<vector<bool>> field;
    int N;
    int answers = 0;
};



#endif