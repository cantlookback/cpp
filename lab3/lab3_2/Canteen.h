#ifndef CANTEEN_H
#define CANTEEN_H

using namespace std;

class Canteen{
public:

    void getOrder(const Organization &org);

    void print();

private:
    bool maket[5][5] = { 0 };

     map<string, int> c_foodOrder;
};

#endif