#pragma once
#include <string>
#include <vector>
class Robot
{
	//declarations
	// describes how to communicate with the method
	//methods or functions or member functions
	// parts of a method:
	//		return type (what data gets returned) 
	//			void if nothing is returned.
	//		parameters (info passed to the method)
	//		identifier (name of the method)
	//		code block
public:
	void CleanRoom(std::string roomToClean);
	std::string CookMeal(std::string recipe, std::vector<std::string> ingredients);
};

