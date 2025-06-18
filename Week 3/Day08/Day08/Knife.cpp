#include "Knife.h"
#include <iostream>

void Knife::showMe()
{
	Weapon::showMe();
	std::cout << "\n\tLength: " << length_ << "\n";
}
