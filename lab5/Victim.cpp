#include "Victim.h"

Victim::Victim(const char &m_tag, const int &px, const int &py) : Creature('V', 2, 'R', m_tag, 7, Point{px, py}){}

void Victim::changeDirection(){
        switch (direction){
        case 'R':
            direction = 'U';
        break;
        case 'U':
            direction = 'L';
        break;
        case 'L':
            direction = 'D';
        break;
        case 'D':
            direction = 'R';
        break;
        
        }
}

void Victim::move(){
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

void Victim::eat(vector<Creature*> &creats, Creature *creature){
    cout << "wtf";
}

void Victim::reproduct(vector<Creature*> &creats){
    if (age == 5 || age == 10) {
        creats.push_back(new Victim{tag, point.x, point.y});
    }
}