#include "FlyingCar.h"

//3) define the override behavior
std::string FlyingCar::vehicleInformation()const
{
    //FULL-OVERRIDE: do NOT call the base method
    //EXTENDION-OVERRIDE: call the base method. DON'T duplicate what the base does.
    std::string baseInfo = Car::vehicleInformation();
    std::string derivedInfo = "\n\tMaximum Altitude: " + std::to_string(maxAlt_);
    return baseInfo + derivedInfo;
}
