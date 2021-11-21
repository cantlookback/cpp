#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include "Player.h"
#include "Alien.h"
using namespace std;

class Game{
    public:
    Game();
    ~Game();

    void printField();

private:
    Player player;
    vector<Alien> aliens;
    char field[10][10];
};


#endif