// Day09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Pistol.h"
#include "Knife.h"


class base
{
private:
	int mNum;
public:
	base(int num) : mNum(num)
	{

	}
	void print()
	{
		std::cout << "Hello base " << mNum << "\n";
	}
};

class derived : public base
{
private:
	std::string mStr;
public:
	derived(std::string str, int num) : base(num), mStr(str)
	{ }
};


class Car
{
public:
	Car(int year)
	{
		mModelYear = year;
		mNumberOfCarsMade++;
	}

	int mModelYear; //each car has its own model year variable
	static int mNumberOfCarsMade; //shared by ALL cars

	//there is NO this parameter for static methods
	//  cannot access non-static members (fields or methods)
	void reporting()
	{
		std::cout << "Number of cars made: " << mNumberOfCarsMade << "\n";
	}

	//non-static can access both non-static AND static members
	void vehicleInfo() const //there's a hidden parameter called 'this'
	{
		//HEAP memory
		//the memory allocated does NOT go away when the method ends
		int* VINptr = new int(12356789);
		delete VINptr;//remove the allocated memory

		//local variables are created on the stack
		//deleted when the method ends
		int VIN = 12346768;
		std::cout << "Model Year: " << this->mModelYear << "\n";
	}
};
//initialize explicitly using the class name scoping
int Car::mNumberOfCarsMade = 0;

int main()
{
	//stack variables
	//  stays in memory UNTIL the method ends
	//  developers don't have to manage the stack
	//  the runtime manages it for you
	Car gsCar(2010);
	Car bsCar(2013);
	gsCar.vehicleInfo();
	bsCar.vehicleInfo();

	Car& car = gsCar;
	Car* todaysRide = &bsCar;
	//std::cout << bsCar;
	std::cout << todaysRide << "\n";
	todaysRide = nullptr;
	//todaysRide->vehicleInfo();
	todaysRide = &gsCar;
	std::cout << todaysRide << "\n";
	int age = 12;
	int* iPtr = &age;
	//Car::reporting();

	Knife stabby = Knife(3, 10, 6);
	Pistol pewpew = Pistol(50, 100, 10, 5);
	//UPCASTING.
	//   casting UP the hierarchy from a DERIVED type to a BASE type
	//   derived type: Knife
	//   base type: Weapone
	//Weapon* wpn = &stabby;//stores the memory address to a Knife
	std::vector<Weapon*> dorasBackpack;
	dorasBackpack.push_back(new Knife(3, 10, 6));
	dorasBackpack.push_back(new Pistol(50, 100, 10, 5));

	std::cout << "\n\nDora's Backpack\n";
	for (auto& wpn : dorasBackpack)
	{
		//at runtime, it checks the type of the object (Knife for first one) 
		// and checks a v-table for an override
		wpn->showMe();
		std::cout << "\n";
	}



	//heap memory
	//  anytime you see '= new' you are allocated space in the heap
	//  stays in memory UNTIL you use 'delete' on it
	//  developers MUST manage the heap memory
	{
		std::unique_ptr<Car> heapCar = std::make_unique<Car>(2025);
		//std::unique_ptr<Car> otherCar = heapCar;
		std::vector<std::unique_ptr<Car>> garage;
		garage.push_back(std::move(heapCar));//heapCar no longer owns the pointer
		//heapCar->vehicleInfo();
	}//when unique_ptr goes out of scope, it deletes its pointer


	/*
		╔════════════╗
		║ Unique_ptr ║
		╚════════════╝

		Using unique pointers w/ overridden methods


		╔═══════════╗
		║ UPCASTING ║ - casting a derived type variable to a base type variable
		╚═══════════╝

		This is ALWAYS safe.


		To maintain the original object, we need a pointer though. If not, then we're just calling the copy constructor of the base class and lose all the info of the derived.

		Unique pointers owns and manages an object through a pointer.
		std::unique_ptr<derived> pDerived = std::make_unique<derived>("Gotham", 5);


		You can upcast by using the base type in the unique_ptr.
		std::unique_ptr<base> pBase = std::make_unique<derived>("Gotham", 5);
		  OR
		std::unique_ptr<base> pBase = std::move(pDerived); https://learn.microsoft.com/en-us/cpp/standard-library/utility-functions?view=msvc-170&redirectedfrom=MSDN&f1url=%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(std%253A%253Amove)%3Bk(move)%3Bk(DevLang-C%252B%252B)%3Bk(TargetOS-Windows)%26rd%3Dtrue#move



		Lecture Code:
			use make_unique and unique_ptr to create a derived instance
			use std::move to upcast it to a base
	*/
	derived der1("Gotham", 1);
	base base1 = der1; //calls the assignment operator of base therefore you lose all the derived parts. base1 is JUST a base object.
	der1.print();
	std::cout << "\n";
	base1.print();



	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

		Create a vector that holds unique pointers of Weapon.
		Create instances of Weapon and Pistol using make_unique.
		Add them to the vector.

		Loop over the vector and call showMe on each weapon.

	*/




	/*
		╔══════════════════╗
		║  Static Members  ║
		╚══════════════════╝

		When calling a non-static method on a class, you must use a variable of that class.
		That's because the variable is passed in as the 'this' parameter.

		Static methods do not have a 'this' parameter therefore you call them on the
		class name itself.

		That's also why static methods cannot access non-static members.

	*/
	Car myRide(1988);
	//Car::reporting();
	myRide.vehicleInfo();//calling non-static methods. myRide is passed in for 'this'

	/*

		CHALLENGE:
		Add a static method to the Car class that returns an instance of the Car class.

	*/
}