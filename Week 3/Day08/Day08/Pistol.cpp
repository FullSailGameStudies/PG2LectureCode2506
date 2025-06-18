#include "Pistol.h"
#include <iostream>

void Pistol::showMe()
{
	Weapon::showMe();
	std::cout << "\n\tRounds: " << rounds_ << "\n\tMag Capacity: " << magCapacity_ << "\n";
}

int Pistol::calcDamage()
{
	return Weapon::calcDamage();
}
