// Day11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Car.h"
#include <vector>
#include <fstream>
#include "Console.h"
#include "Input.h"

int main()
{
    std::cout << "Gone in 60 Seconds!\n";//https://carbuzz.com/features/beyond-eleanor-gone-in-60-seconds-car-names#:~:text=The%20Complete%20List%20Of%20Gone%20In%2060%20Seconds,8%201961%20Porsche%20Speedster%20-%20%22Natalie%22%20More%20items

    Car myRide(1969, "Plymouth", "Hemi Cuda");
    std::string garageFile = "garage.csv";
    std::ofstream outFile(garageFile);
    if (outFile.is_open())
    {
        myRide.SerializeCSV(outFile, '~');
    }
    else std::cout << "The file couldn't be opened.\n";

    outFile.close();

    myRide.SerializeCSV(std::cout, '\t');
    std::cout << "\n";

    std::vector<Car> garage;
    garage.push_back(Car(1967, "Ford", "Shelby Mustang GT500"));
    garage.push_back(Car(1956, "Ford", "T Bird"));
    garage.push_back(Car(1961, "Porsche", "Speedster"));
    garage.push_back(Car(1965, "Pontiac", "GTO"));
    garage.push_back(Car(1969, "Plymouth", "Hemi Cuda"));

    //1) serialize the vector to a file
    std::string jaysGarage = "jaysGarage.csv";

    std::ofstream jaysFile(jaysGarage);
    if (jaysFile.is_open())
    {
        for(int i=0;i<garage.size();i++)
        {
            if(i != 0) jaysFile << "\n";
            garage[i].SerializeCSV(jaysFile, '~');
        }
    }
    else std::cout << "The file couldn't be opened.\n";
    jaysFile.close();


    std::vector<Car> loadedCars;

    std::ifstream loadFile(jaysGarage);
    if (loadFile.is_open())
    {
        //create a Car object using the data from the file
        while(not loadFile.eof())
        {
            std::string carLine;
            std::getline(loadFile, carLine);
            if(not carLine.empty())
            {
                try
                {
                    Car nextCar(carLine, '~');
                    loadedCars.push_back(nextCar);
                }
                catch (const std::exception&)
                {
                    std::cout << "Error reading car.\n";
                }
            }
        }
    }
    else std::cout << jaysGarage << " could not be opened.\n";
    loadFile.close();
    /*
        ╔═════════════╗
        ║ Serializing ║
        ╚═════════════╝

        Saving the state (data) of objects

        Lecture Code: serialize the vector of Cars to a file.
            Data Format:
                separates cars. EX: car1|car2|car3
                separates data inside a car. EX: 1967;Ford;Shelby Mustang GT500

    */



    /*
        ╔═══════════════╗
        ║ Deserializing ║
        ╚═══════════════╝

        Recreating the objects from the saved state (data) of objects

        Lecture Code:
            Open the file
            Read in each line
            split each line to get each car
            split each car to get the car details

    */

    std::ifstream inFile(garageFile);
    if (inFile.is_open())
    {
        //create a Car object using the data from the file
        std::string carLine;
        std::getline(inFile, carLine);
        Car nextCar(carLine, '~');
        nextCar.SerializeCSV(std::cout, '\t');
        std::cout << "\n";
    }
    else std::cout << garageFile << " could not be opened.\n";
    inFile.close();

    std::string myCarInfo = "1967,Ford,Shelby Mustang GT500";
    Car dreamCar(myCarInfo, ',');
    dreamCar.SerializeCSV(std::cout, '\t');
    std::cout << "\n";

}