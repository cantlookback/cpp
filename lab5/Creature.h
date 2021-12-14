#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>

using namespace std;

struct Point{int x, y;};

class Creature{
public:
    Creature(const char &m_typeOfCreature, const int &m_k, const char &m_direction, const char &m_tag, const int &m_timeToLive, const Point &p);

    virtual void changeDirection();
    virtual void move();
    virtual void eat(vector<Creature*> &creats, Creature *creature);
    virtual void reproduct(vector<Creature*> &creats);
    virtual void death(vector<Creature*> &creats);
    
    friend class Field;
    
protected:
    char typeOfCreature;
    Point point;
    char direction, tag;
    int k, kk, age = 0, timeToLive, saturation = 0;
};
