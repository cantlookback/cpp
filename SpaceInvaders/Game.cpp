#include "Game.h"

Game::Game(){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            field[i][j] = '*';
        }
    }
    
}

Game::~Game(){

}

void Game::printField(){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            cout << field[i][j] << ' ';
        }
        cout << endl;
    }
}