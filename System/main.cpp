#include <iostream>

using namespace std;

// SET-UP REQUIREMENTS SO FAR:
// Create CityMap and CityHall.
// CityHall needs reference to political system

int main(){

    int x = 0;
    int y = 0;
    int z = 0;

    while (true) {
        if (x == 1000000000){
            cout << "Hello" << endl;
            x = 0;
        }
        
        x++;
    }

    while (true){
        x += 1;
        
        if (x % 100000000 == 0){
            y += 1;
        }

        if (y % 1000000 == 0){
            z += 1;
            x = 0;
        }

        if (z % 100000 == 0){
            cout << "x: " << x << " y: " << y << " z: " << z << endl;
            y = 0;
        }
    }

    return 0;
}