#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include <thread>
#include <Windows.h>
#include "Player.h"
#include "Alien.h"
#include "Bullet.h"
#include "../Utilities/utilities.h"

using namespace std;

class Game{
    public:
    Game();
    ~Game();

    void printField();
    void checkCollision();
    void gameCycle();

    friend class Player;
private:
    static const int fieldH = 10, fieldW = 15;
    Player player{fieldW / 2};
    vector<Alien> aliens;
    char field[fieldW][fieldH];
};


#endif