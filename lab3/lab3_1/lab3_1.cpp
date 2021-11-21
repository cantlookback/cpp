#include "Canteen.cpp"
#include "Organization.cpp"
#include <ctime>
#include <iostream>

using namespace std;

int main(){
    srand(time(0));

    Canteen cant;
    Organization org;

    org.createOrder();
    cant.getOrder(org.getOrderMaket());
    cant.print();

    return 0;
}