#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> floors;
    int countFloors, turns, heroPower = 1;
    int pos = 0;
    cin >> countFloors >> turns;
    floors.resize(countFloors);
    
    for (int i = 0; i < countFloors; i++){
        cin >> floors[i];
    }

    for (int i = 0; i < turns; i++){
        if (heroPower >= floors[pos+1]){
            heroPower += floors[pos+1];
            pos += 1;
        } else {
            heroPower += floors[pos-1];
            pos -= 1;
        }
    }

    cout << heroPower;


    return 0;
}