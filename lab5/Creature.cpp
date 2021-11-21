#include "Creature.h"

Creature::Creature(const char &m_typeOfCreature, const int &m_k, const char &m_direction, const char &m_tag, const int &m_timeToLive, const Point &p) : 
                    typeOfCreature(m_typeOfCreature), k(m_k), kk(m_k), direction(m_direction), tag(m_tag), point(p), timeToLive(m_timeToLive){}

    void Creature::changeDirection(){}

    void Creature::move(){}

    void Creature::eat(vector<Creature*> &creats, Creature *creature){}

    void Creature::reproduct(vector<Creature*> &creats){}

    void Creature::death(vector<Creature*> &creats){
        vector<Creature*>::iterator it;
        it = find(creats.begin(), creats.end(), this);
        int index = distance(creats.begin(), it);

        delete creats[index];
        creats.erase(creats.begin() + index);
    }