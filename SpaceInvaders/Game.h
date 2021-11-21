#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Player.h"
#include "Alien.h"
using namespace std;

class Game{
    public:
    Game();
    ~Game();

    void printField();

private:
    char field[10][10];
};


#endif