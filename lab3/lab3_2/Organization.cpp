#include "Organization.h"
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void Organization::createRandomOrder(){
        for (auto &amount : o_foodOrder){
            amount.second = rand() % 50;
        }
    }

void Organization::createOrder(map<string, int> m_o_foodOrder){
        o_foodOrder = m_o_foodOrder;
    }