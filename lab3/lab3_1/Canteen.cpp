#include <iostream>
#include <map>
#include <vector>
#include "Canteen.h"

using namespace std;

void Canteen::getOrder(pair<map<string, int>, vector<vector<bool>>> m_OrderMaket){
        c_foodOrder = m_OrderMaket.first;
        maket = m_OrderMaket.second;
}

void Canteen::print(){
        for (auto x : c_foodOrder){
            cout << x.first << "    " << x.second << "kg" << endl;
        }

        for (auto x : maket){
            for (auto y : x){
                cout << y << ' ';
            }
            cout << endl;
        }
}