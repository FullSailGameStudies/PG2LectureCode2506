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

	Pistol operator+(const Pistol& other)
	{
		int rounds = rounds_ + other.rounds_;
		int magCap = std::max(magCapacity_, other.magCapacity_);
		Pistol newPistol(range(), damage(), rounds, magCap);
		return newPistol;
	}

	void showMe();
	int calcDamage() override;

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

