#ifndef BULLET_H
#define BULLET_H
#pragma pointers_to_members( full_generality, virtual_inheritance )
#include "Entity.h"

class Bullet : public Entity{
public:
    Bullet(const Point &m_point);
    ~Bullet();
    void move();
    friend class Player;
    friend class Game;
private:
    bool alive = true;
    thread bulletThread;
    mutex m, m2;
};

#endif