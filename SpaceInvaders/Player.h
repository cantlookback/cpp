#ifndef PLAYER_H
#define PLAYER_H
#pragma pointers_to_members( full_generality, virtual_inheritance )
#include <iostream>
#include <conio.h>
#include <vector>
#include "Point.h"
#include "Bullet.h"
using namespace std;


class Player{
public:
    Player(const int &m_x);
    ~Player();

    void move();
    void shoot();
    friend class Game;
    friend class Bullet;
private:
    vector<Bullet*> bullets;
    Point point;
    int health, cooldown;
    const char tag = 'T';
    mutex m1;
};

#endif