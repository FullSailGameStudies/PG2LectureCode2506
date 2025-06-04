#pragma once
#include <vector>
#include <string>
class FullSailCourse
{
public:

	//Write a method to fill the vector of floats with grades.
	//declaration here in the header
	//definition in the cpp
	//parameter by reference a vector
	void FillMyVectorWithGrades(std::vector<float>& myVectorToFill);


	//write a method to print a vector (pass the vector as a parameter)
	//pass by reference + const
	void PrintMyVectorOfGrades(const std::vector<float>& myVectorToPrint) const;
private:
	std::string name = "PG2";
};

