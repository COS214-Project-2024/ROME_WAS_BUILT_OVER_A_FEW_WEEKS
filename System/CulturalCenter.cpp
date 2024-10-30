#include "CulturalCenter.h"

CulturalCenter::CulturalCenter(int radiusOfEffect) : Landmark(radiusOfEffect) {
    satisfactionIncrease = 25;
    numVisitors = 0;
    taxRatePerVisitor = 50.0;
}

CulturalCenter::~CulturalCenter() {}

// int CulturalCenter::calculateTotalTax() {
//     return numVisitors * taxRatePerVisitor; 
// }
