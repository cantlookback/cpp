#include <iostream>
#include <ctime>
#include "Canteen.cpp"
#include "Organization.cpp"

using namespace std;


int main(){
    srand(time(0));

    Canteen cant;
    Organization org;

    org.createRandomOrder();
    cant.getOrder(org);
    cant.print();

    return 0;
}