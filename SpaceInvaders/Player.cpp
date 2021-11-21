#include "Player.h"

Player::Player(){
    point.x = 5;
    point.y = 0;
}

Player::~Player(){
    
}

void Player::move(){
    bool trigger = true;
    while(true){
        if(kbhit()){
            switch(getch()){
                case 65: //LEFT A
                    this->point.x--;
                    trigger = false;
                    break;
                case 68:    //RIGHT D
                    this->point.x++;
                    trigger = false;
                    break;
            }
        }
    }
}