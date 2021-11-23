#include "Bullet.h"

Bullet::Bullet(const Point &m_point): Entity(m_point){
    bulletThread = thread(&Bullet::move, this);
    bulletThread.detach();
}

Bullet::~Bullet(){
}

void Bullet::move(){
    while (alive){
        this->point.y++;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    // bulletThread.join();
}