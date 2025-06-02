#include "Robot.h"
#include <iostream>
#include <Console.h>


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
	//how to call a Static method...
	//1) use the name of the class prefixed to the method name.
	Console::Write("Cooking the ");
	Console::Write(recipe, ConsoleColor::Green);
	//2) if it returns data, collect it
	int width = Console::GetWindowWidth();

	//std::cout << "Cooking the " << recipe << "...";
	//for loop
	std::cout << "\nFor loop...\n";
	for (int i = 0; i < ingredients.size(); i++)
	{
		if(ingredients[i] == "Cinnamon")
		{
			auto cinnamonIterator = ingredients.begin() + i;
			ingredients.erase(cinnamonIterator);
		}
		std::string ingredient = ingredients[i];
		Console::WriteLine(ingredient);
	}

	std::cout << "\nForeach (range-based) loop...\n";
	for (auto& ingredient : ingredients)
	{
		Console::WriteLine(ingredient);
	}

	std::cout << "\niterator for loop...\n";
	//iterators are objects that "point" to the data
	//  inside of a collection.
	//they know how to move through a collection.
	//vector.begin() - iterator to the first item in the vector
	//vector.end() - iterator to the last item??
	for (std::vector<std::string>::iterator i = ingredients.begin(); i != ingredients.end(); i++)
	{
		if (*i == "cinnamon")
		{
			ingredients.erase(i);//erase using the loop iterator
		}
		std::string ingredient = *i;//* - "dereference"
		std::cout << ingredient << "\n";
	}

	//how to erase from a vector...
	auto lastIterator = ingredients.end() - 1;
	//to get an iterator to an item inside the vector...
	//begin() + index
	auto cinnamonIterator = ingredients.begin() + 2;
	ingredients.erase(cinnamonIterator);

	std::cout << "vrrr....\n";
	std::cout << "DONE!\n";
	return recipe;
}
