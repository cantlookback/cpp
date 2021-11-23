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
        player.m1.lock();
        field[bullet->point.x][bullet->point.y] = '^';
        player.m1.unlock();
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
    player.m1.lock();
    for (int i = 0; i < player.bullets.size();){
        if (player.bullets[i]->point.y > fieldH-2){
            player.bullets[i]->alive = false;
            delete player.bullets[i];
            player.bullets.erase(player.bullets.begin());
            //player.bullets.shrink_to_fit();
        } else i++;
    }
    player.m1.unlock();
}

void Game::gameCycle(){
    system("cls");
    thread t1(&Player::move, &player);
    t1.detach();
    for (int i = 0; i < 1000; i){
        printField();
        Sleep(1);
        //clearScreen();
        system("cls");
    }
    system("cls");
}
