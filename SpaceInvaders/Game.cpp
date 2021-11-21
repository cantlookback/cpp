#include "Game.h"

Game::Game(){
    for (int x = 0; x < 10; x++){
        for (int y = 0; y < 10; y++){
            field[x][y] = '*';
        }
    }
    field[player.point.x][player.point.y] = player.tag;
}

Game::~Game(){

}

void Game::printField(){
    for (int x = 0; x < 10; x++){
        for (int y = 0; y < 10; y++){
            field[x][y] = '*';
        }
    }
    field[player.point.x][player.point.y] = player.tag;
    for (int x = 9; x >= 0; x--){
        for (int y = 0; y < 10; y++){
            cout << field[y][x] << ' ';
        }
        cout << endl;
    }
}

void Game::gameCycle(){
    thread t1(&Player::move, &player);
    t1.detach();
    for (int i = 0; i < 50; i++){
        printField();
        Sleep(100);
        system("cls");
    }
}

