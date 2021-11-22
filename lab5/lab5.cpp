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

    // int choice, k, i, turns;
    // char type, tag, dir;
    // bool trigger = true;
    // Field game;
    // while (trigger){
    //     cout << "Predator - Victim simulation\n";
    //     cout << "1 - Add creature\n2 - Start simulation\n0 - Exit\n";
    //     cin >> choice;
    //     switch (choice){
    //         case 1:
    //             system("cls");
    //             cout << "Predator/Victim, Tag, Direction and k>>";
    //             cin >> type >> tag >> dir >> k;
    //             if (type == 'P'){
    //                 game.addCreature(new Predator{tag, dir, k});
    //             } else {
    //                 game.addCreature(new Victim{tag, dir, k});
    //             }
    //         break;
    //         case 2:
    //             system("cls");
    //             cout << "Number of turns>>";
    //             cin >> turns;
    //             game.start(turns);
    //         break;
    //         case 0:
    //             trigger = false;
    //         break;
    //     }
    // }
}