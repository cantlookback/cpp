#include "Predator.h"

Predator::Predator(const char &m_tag, const int &px, const int &py) : Creature('P', 3, 'U', m_tag, 10, Point{px, py}){}

void Predator::changeDirection(){
        switch (direction){
        case 'R':
            direction = 'D';
        break;
        case 'D':
            direction = 'L';
        break;
        case 'L':
            direction = 'U';
        break;
        case 'U':
            direction = 'R';
        break;
        }
    }

void Predator::move(){
    if (kk == 0){
        changeDirection();
        kk = k;
    }
    switch (direction){
            case 'R':
            point.x += 1;
            if (point.x >= 10){
                point.x = point.x - 10;
            }
            break;
            case 'L':
            point.x -= 1;
            if (point.x < 0){
                point.x = 10 + point.x;
            }
            break;
            case 'U':
            point.y += 1;
            if (point.y >= 10){
                point.y = point.y - 10;
            }
            break;
            case 'D':
            point.y -= 1;
            if (point.y < 0){
                point.y = 10 + point.y;
            }
            break;
    }
    kk--;
}

void Predator::eat(vector<Creature*> &creats, Creature *creature){
    vector<Creature*>::iterator it;
    it = find(creats.begin(), creats.end(), creature);
    int index = distance(creats.begin(), it);

    delete creats[index];
    creats.erase(creats.begin() + index);

    saturation++;
}

void Predator::reproduct(vector<Creature*> &creats){
    if (saturation == 2){
        creats.push_back(new Predator{tag, point.x, point.y});
        saturation = 0;
    }
}