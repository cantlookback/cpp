#include "Game.h"

Game::Game(){
    for (int x = 0; x < fieldW; x++){
        for (int y = 0; y < fieldH; y++){
            field[x][y] = '*';
        }
    }
    field[player.point.x][player.point.y] = player.tag;
}

Game::~Game(){

}

void Game::printField(){
    for (int x = 0; x < fieldW; x++){
        for (int y = 0; y < fieldH; y++){
            field[x][y] = '*';
        }
    }
    
    for (auto bullet : player.bullets){
        field[bullet->point.x][bullet->point.y] = '^';
    }

    field[player.point.x][player.point.y] = player.tag;

    checkCollision();
    
    for (int y = fieldH-1; y >= 0; y--){
        for (int x = 0; x < fieldW; x++){
            cout << field[x][y] << ' ';
        }
        cout << endl;
    }
}

void Game::checkCollision(){
    for (auto bullet : player.bullets){
        if (bullet->point.y > fieldH-1){
            delete bullet;
            player.bullets.erase(player.bullets.begin());
        }
    }
}

void Game::gameCycle(){
    system("cls");
    thread t1(&Player::move, &player);
    t1.detach();
    for (int i = 0; i < 100; i++){
        printField();
        Sleep(100);
        clearScreen();
    }
}
