#include "Park.h"

Park::Park(int radiusOfEffect) : Landmark(radiusOfEffect) {
    satisfactionIncrease = 20;
}

Park::~Park() {}

// int Park::calculateTotalTaxes() {
//     return 0;
// }