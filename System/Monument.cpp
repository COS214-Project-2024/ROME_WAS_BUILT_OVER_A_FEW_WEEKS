#include "Monument.h"

Monument::Monument(int radiusOfEffect) : Landmark(radiusOfEffect) {
    satisfactionIncrease = 15;
}

Monument::~Monument() {}

// int Monument::calculateTotalTax() {
//     return 0; 
// }