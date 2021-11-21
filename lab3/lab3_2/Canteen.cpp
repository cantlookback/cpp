#include <iostream>
#include <map>
#include <vector>
#include "Canteen.h"

using namespace std;

class Organization;

void Canteen::getOrder(const Organization &org){
        c_foodOrder = org.o_foodOrder;
        for (int i = 0; i < 5; i ++){
            for (int j = 0; j < 5; j++){
                maket[i][j] = org.maket[i][j];
            }
        }
    }

void Canteen::print(){
        for (auto x : c_foodOrder){
            cout << x.first << "    " << x.second << "kg" << endl;
        }
        for (int i = 0; i < 5; i ++){
            for (int j = 0; j < 5; j++){
                cout << maket[i][j] << ' ';
            }
            cout << endl;
        }
    }