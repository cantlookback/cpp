#include "Player.h"

Player::Player(const int &m_x){
    point.x = m_x;
    point.y = 0;
}

Player::~Player(){
    
}

void Player::move(){
    while(true){
        if(_kbhit()){
            switch(_getch()){
                case 97: //LEFT a
                    if (this->point.x == 0)
                        break;
                    this->point.x--;
                    break;
                case 100:    //RIGHT d
                    if (this->point.x == 14)
                        break;
                    this->point.x++;
                    break;
                case 119:   //SHOOT w
                    this->shoot();
                    break;
            }
        }
    }
}

void Player::shoot(){
    m1.lock();
    bullets.push_back(new Bullet{point});
    m1.unlock();
}