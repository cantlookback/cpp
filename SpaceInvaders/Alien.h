#ifndef ALIEN_H
#define ALIEN_H
#include <iostream>
using namespace std;

struct Point{
    int x, y;
};

class Alien{
public:
    Alien();
    ~Alien();

private:
    Point point;
};

#endif