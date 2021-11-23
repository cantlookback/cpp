#include <iostream>
#include "Game.h"
using namespace std;
mutex m1;


int main(){

    Game game;
    game.gameCycle();    
    return 0;
}