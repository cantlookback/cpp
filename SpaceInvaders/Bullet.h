#ifndef BULLET_H
#define BULLET_H
#include <iostream>
#include <thread>
#include <chrono>
#include "Point.h"
using namespace std;

class Bullet{
public:
    Bullet(const Point &m_point);
    ~Bullet();
    void move();
    friend class Player;
    friend class Game;
private:
    Point point;
};

#endif