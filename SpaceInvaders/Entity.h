#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>
#include <thread>
#include <chrono>
#include "Point.h"
using namespace std;

class Entity{
public:
    Entity(const Point &m_point);
    ~Entity();

protected:
    Point point;
};
#endif