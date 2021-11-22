#include <iostream>

using namespace std;



int main(){
          //!HHy  WWx
    int field[15][10];

    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 10; j++){
            field[i][j] = i*10+j;
        }
    }
    
    // for (int i = 0; i < 15; i++){
    //     for (int j = 0; j < 10; j++){
    //         cout << field[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    for (int y = 9; y >= 0; y--){
        for (int x = 0; x < 15; x++){
            cout << field[x][y] << ' ';
        }
        cout << endl;
    }

    return 0;
}