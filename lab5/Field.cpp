#include "Field.h"
#include "Victim.h"
#include "Predator.h"

bool operator==(const Point& p1, const Point& p2) {
    return { (p1.x == p2.x) && (p1.y == p2.y) };
}

Field::Field(const vector<Creature*> &m_creats, const int &turns) : creats(m_creats){
    for (auto c : creats){
        field[c->point.y][c->point.x] = c->tag;
    }
}

Field::~Field(){
    for (auto c : creats){
        delete c;
    }
}

void Field::addCreature(Creature *creature){
    creats.push_back(creature);
}

void Field::turn(vector<Creature*> &creats){
    //!MOVING
    for (auto creature : creats){
        field[creature->point.y][creature->point.x] = '*';
        creature->move();
        field[creature->point.y][creature->point.x] = creature->tag;
    }

    // printField();
    // Sleep(1000);
    // system("cls");

    //!EATING
    for (int i = 0; i < creats.size(); i++) {
        for (int j = i+1; j < creats.size();) {
            if ((creats[i]->point == creats[j]->point) && (creats[i]->typeOfCreature != creats[j]->typeOfCreature)) {
                if (creats[i]->typeOfCreature == 'P') {
                    creats[i]->eat(creats, creats[j]);
                }
                else {
                    creats[j]->eat(creats, creats[i]);
                }
            }
            else {
                j++;
            }
        }
    }

    //!AGING
    for (auto creature : creats){
        creature->age++;
    }
    
    //!REPRODUCTION
    for (int i = 0; i < creats.size(); i++) {
            creats[i]->reproduct(creats);
    }
    //?Range-based loop doesn't work, trying to accept nullptr 0xDDDDDDDD
    //!DYING
    for (auto i = 0; i < creats.size();){
        if (creats[i]->age == creats[i]->timeToLive){
            field[creats[i]->point.y][creats[i]->point.x] = '*';
            creats[i]->death(creats);
        } else { 
            i++;
        }
    }
    creats.shrink_to_fit();
}

void Field::printField(){
    for (int x = 0; x < 10; x++){
        for (int y = 0; y < 10; y++){
            cout << field[x][y] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

void Field::start(){
    system("cls");
    printField();
    Sleep(1000);
    clearScreen();
    for (int i = 1; i <= turns; i++){
        turn(creats);
        printField();
        Sleep(1000);
        clearScreen();
    }
}