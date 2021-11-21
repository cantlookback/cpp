#include <iostream>
#include <Windows.h>
#include "GuessGame.cpp"

using namespace std;

int main(){
    srand(time(0));

    GuessGame game {6};
    int N, x, y;
    while (true){
        cout << "GuessGame!!!\n";
        cout << "Choose N>>";
        cin >> N;
        GuessGame game {N};
        system("cls");
        game.guess();
        break;
    }

    return 0;
}