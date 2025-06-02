#include "Robot.h"
#include <iostream>


//class method definitions
//  code block for the method

//tell the compiler what class this method
// belongs to.
// ClassName:: on the front of the method name
void Robot::CleanRoom(std::string roomToClean)
{
	std::cout << "Cleaning the " << roomToClean << "...";
	std::cout << "vrrr....\n";
	std::cout << "DONE!\n";
}

std::string Robot::CookMeal(std::string recipe, std::vector<std::string> ingredients)
{
	std::cout << "Cooking the " << recipe << "...";
	std::cout << "vrrr....\n";
	std::cout << "DONE!\n";
	return recipe;
}
