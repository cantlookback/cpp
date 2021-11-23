#ifndef BULLET_H
#define BULLET_H
#include "Entity.h"

class Bullet : Entity{
public:
    Bullet(const Point &m_point);
    ~Bullet();
    void move();
    friend class Player;
    friend class Game;
private:

};

#endif