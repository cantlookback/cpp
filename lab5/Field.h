#pragma once

#include "Creature.h"

using namespace std;

class Field{
public:
    Field(const vector<Creature*> &m_creats, const int &turns);
    ~Field();

    void addCreature(Creature *creature);

    void start();
    void printField();
    void turn(vector<Creature*> &creats);

    friend bool operator==(const Point &p1, const Point &p2);

    vector<Creature*> creats;
protected:
    char field[10][10] = {
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    };
    int turns;
};
