#include "FullSailCourse.h"
#include <iostream>

void FullSailCourse::FillMyVectorWithGrades(std::vector<float>& myVectorToFill)
{
	for (int i = 0; i < 10; i++)
	{
		//rand() generates a pseudo-random number from 0-32767
		//limit the value from 0-100
		//% - divides by the number and returns the remainder		
		myVectorToFill.push_back(rand() % 101);
	}
}

void FullSailCourse::PrintMyVectorOfGrades(const std::vector<float>& myVectorToPrint) const
{
	//name = "Bruce Banner";
	std::cout << "\n" << name << "\n";
	for (auto iter = myVectorToPrint.begin(); iter != myVectorToPrint.end(); iter++)
	{
		//*iter means go to the value that it points to
		std::cout << *iter << "\n";
	}
	std::cout << "\n\n";
}
