#pragma once
#include "Creature.h"

class Predator : public Creature{
public:
    Predator(const char &m_tag, const int& px = (rand() % 10), const int& py = (rand() % 10));

    void changeDirection();
    void move();
    void eat(vector<Creature*> &creats, Creature *creature);
    void reproduct(vector<Creature*> &creats);

};
