#include "GuessGame.h"

GuessGame::GuessGame(const int &m_N) : N(m_N){
    field.resize(N, vector<bool>(N));
    
    int count = N / 2;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            field[i][j] = false;
        }
    }
    while (count != 0){
        field[rand() % N][rand() % N] = true;
        count--;
    }
}

void GuessGame::printField(){
    for (auto x : field){
        for (auto x2 : x){
            cout << x2 << " ";
        }
        cout << endl;
    }
}

void GuessGame::guess(){
    int x, y;
    for (int i = 0; i < N; i++){
        cout << "Make your choice>>";
        cin >> x >> y;
        if (field[x][y]){
            answers++;
        }
    }
    isWin();
}

void GuessGame::isWin(){
    if (answers >= N/3){
        cout << "You win!\n";
    } else {
        cout << "You lose!\n";
    }
}