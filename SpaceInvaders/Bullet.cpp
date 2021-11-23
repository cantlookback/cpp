#include "Bullet.h"

Bullet::Bullet(const Point &m_point): Entity(m_point){
    thread bulletThread(&Bullet::move, this);
    bulletThread.detach();
}

Bullet::~Bullet(){
}

void Bullet::move(){
    for (int i = 0; i < 10; i++){
        point.y++;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}