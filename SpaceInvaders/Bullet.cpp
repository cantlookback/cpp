#include "Bullet.h"

Bullet::Bullet(const Point &m_point): Entity(m_point){
    bulletThread = thread(&Bullet::move, this);
    bulletThread.detach();
}

Bullet::~Bullet(){
}

void Bullet::move(){
    while (alive){
        cout << this_thread::get_id() << " BULLET THREAD";
        this->point.y++;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}