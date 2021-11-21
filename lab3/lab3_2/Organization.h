#ifndef ORGANIZATION_H
#define ORGANIZATION_H

class Organization{
public:

    void createRandomOrder();

    void createOrder(map<string, int> m_o_foodOrder);

    friend class Canteen;
private:
    bool maket[5][5] = {{0, 0, 1, 0, 1},
                        {1, 1, 0, 1, 0},
                        {0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 0},
                        {0, 1, 0, 1, 0}};

    map<string, int> o_foodOrder = {{"Apple", 0},
                                    {"Banana", 0},
                                    {"Meat", 0},
                                    {"Spaghetti", 0},
                                    {"Vegetables", 0}};
};

#endif