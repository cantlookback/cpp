#ifndef CANTEEN_H
#define CANTEEN_H

using namespace std;

class Canteen{
public:

    void getOrder(pair<map<string, int>, vector<vector<bool>>>);

    void print();

private:
    vector<vector<bool>> maket;
    map<string, int> c_foodOrder;
};
#endif