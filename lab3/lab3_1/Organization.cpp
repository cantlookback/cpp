#include <iostream>
#include <map>
#include <vector>
#include "Organization.h"

using namespace std;

void Organization::createOrder(){
        for (auto &amount : o_foodOrder){
            amount.second = rand() % 50;
        }
    }

pair<map<string, int>, vector<vector<bool>>> Organization::getOrderMaket(){
        return {o_foodOrder,  maket};
}