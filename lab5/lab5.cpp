#include <iostream>
#include <ctime>
#include "Creature.h"
#include "Predator.h"
#include "Victim.h"
#include "Field.h"


int main(){
    srand(time(0));



    Predator *tiger = new Predator{'T'};
    Predator *lion = new Predator{'L'};
    Victim *zebra = new Victim{'Z'};
    Victim *frog = new Victim{'F'};
    Victim* squirrel = new Victim{ 'S'};
    Victim* buffalo = new Victim{'B'};
    
    vector<Creature*> creats = {tiger, zebra, lion, frog, squirrel, buffalo};

    Field game{creats, 10};
    game.start();

}