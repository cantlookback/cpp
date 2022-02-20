#include <iostream>
#include <vector>
using namespace std;

class Animal{
public:
    Animal(string m_name) : name(m_name){}
    string name;
};

class Bear : public Animal{
public:
    Bear() : Animal("bear"){}
};

class Pig : public Animal{
public:
    Pig() : Animal("pig"){}
};


class Zoo{
public:
    static Zoo& getInstance(){
        static Zoo *z = new Zoo();
        return *z;
    }

    void add(Animal *animal){
        animals.push_back(animal);
    }
private:
    vector<Animal*> animals;
    Zoo() = default;
    Zoo(const Zoo&) = delete;
    Zoo& operator=(const Zoo&) = delete;
    Zoo(Zoo&&) = delete;
    Zoo& operator=(Zoo&&) = delete;
};

int main(){
    Zoo &z = Zoo::getInstance();

    z.add(new Bear());
    z.add(new Pig());
    
    return 0;
}