#pragma once
#include "Weapon.h"
class Pistol : public Weapon
{
public:

	Pistol(int range, int damage, int rounds_, int magCapacity_)
		: 
		Weapon(range, damage),
		rounds_(rounds_), magCapacity_(magCapacity_)
	{
	}

	int Rounds() const { return rounds_; }
	void Rounds(int rounds)
	{
		if (rounds >= 0 && rounds <= magCapacity_)
			rounds_ = rounds;
	}

	int MagCapacity() const { return magCapacity_; }
	void MagCapacity(int magCap)
	{
		if (magCap > 0 && magCap <= 100)
			magCapacity_ = magCap;
	}
private:
	int rounds_, magCapacity_;
};

