#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;

struct Point{
    int x, y;
};

class Player{
public:
    Player();
    ~Player();

private:
    Point point;
    int health;
};

#endif