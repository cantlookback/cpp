#ifndef ALIEN_H
#define ALIEN_H
#include <iostream>
#include "Point.h"
using namespace std;

class Alien{
public:
    Alien();
    ~Alien();

private:
    Point point;
};

#endif