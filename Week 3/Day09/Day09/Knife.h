#pragma once
#include "Weapon.h"
class Knife : public Weapon //is-a relationship. Knife is-a Weapon
{
public:

	Knife(int range, int damage, int length)
		: 
		Weapon(range, damage),
		length_(length)
	{
	}

	int calcDamage() override;
	
	void showMe() override;

	int GetLength() const { return length_; }
	void SetLength(int length)
	{
		if (length > 0 && length < 12)
			length_ = length;
	}
private:
	int length_;
};

