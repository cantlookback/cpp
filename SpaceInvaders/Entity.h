#ifndef ENTITY_H
#define ENTITY_H
#pragma pointers_to_members( full_generality, virtual_inheritance )
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include "Point.h"
using namespace std;

class Entity{
public:
    Entity(const Point &m_point);
    virtual ~Entity() = 0;

protected:
    Point point;
};
#endif