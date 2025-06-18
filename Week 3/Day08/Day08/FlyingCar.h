#pragma once
#include "Car.h"
class FlyingCar : public Car
{
public:
	FlyingCar(int year, std::string make, std::string model,
			  int maxAlt, int alt)
		: 
		Car(year,make,model),//calls the base ctor
		maxAlt_(maxAlt), 
		alt_(alt)
	{
		std::cout << "\tFlyingCar ctor\n";
		std::cout << mModelYear;
	}
	//2) add the method declaration to the derived class
	//   - don't need virtual here
	//   - it must match the base exactly.
	std::string vehicleInformation()const override;
private:
	int maxAlt_, alt_;
};

