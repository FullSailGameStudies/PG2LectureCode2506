#include "Car.h"

std::string Car::vehicleInformation()
{
	return std::to_string(mModelYear) + " " + mMake + " " + mModel;
}

void Car::DeserializeCSV(const std::string& csvData, char delimiter)
{
	//use stringstream to parse the string
	std::stringstream carStream(csvData);
	std::string data;
	std::getline(carStream, data, delimiter);
	mModelYear = std::stoi(data);
	std::getline(carStream, mMake, delimiter);
	std::getline(carStream, mModel, delimiter);
}

void Car::SerializeCSV(std::ostream& outFile, char delimiter) const
{
	//  <<  insertion operator
	outFile << mModelYear << delimiter << mMake << delimiter << mModel;
}
