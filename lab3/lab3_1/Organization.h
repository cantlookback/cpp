#ifndef ORGANIZATION_H
#define ORGANIZATION_H

using namespace std;

class Organization{
public:
    void createOrder();

    pair<map<string, int>, vector<vector<bool>>> getOrderMaket();


private:
    vector<vector<bool>> maket = {{0, 0, 1, 0, 1},
                        {1, 1, 0, 1, 0},
                        {0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 0},
                        {0, 1, 0, 1, 0}};

    map<string, int> o_foodOrder = {
        {"Apple", 0},
        {"Banana", 0},
        {"Meat", 0},
        {"Spaghetti", 0},
        {"Vegetables", 0}};
};
#endif