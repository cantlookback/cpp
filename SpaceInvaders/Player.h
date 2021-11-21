#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <conio.h>
#include "Point.h"
using namespace std;


class Player{
public:
    Player();
    ~Player();

    void move();
    friend class Game;
private:
    Point point;
    int health;
    const char tag = 'T';
};

#endif