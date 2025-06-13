// Day06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <Console.h>


enum class Weapon
{
    Sword, Axe, Spear, Mace
};


void PrintGrades(const std::string& className, const std::map<std::string, double>& grades)
{
    Console::WriteLine(className + " Grades", ConsoleColor::Magenta);
    for (auto& [Student, Grade] : grades)
    {
        Console::SetForegroundColor(
            //ternary operator. shorthand for if-else
            // (condition) ? true-case : false-case
            (Grade < 59.5) ? ConsoleColor::Red :
            (Grade < 69.5) ? ConsoleColor::Yellow :
            (Grade < 79.5) ? ConsoleColor::Blue :
            (Grade < 89.5) ? ConsoleColor::White :
            ConsoleColor::Green
        );
        std::cout << std::right << std::setw(8) << Grade << "  ";
        Console::Reset();
        Console::WriteLine(Student);
    }
}

int main()
{

    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Removing a key and its value from a map  ]

        erase(iterator) -- returns an iterator that points to the first item AFTER the ones that were removed OR end() if no element exist
        erase(key) -- returns the # of items removed

    */
    std::map<Weapon, int> dorasBackpack;
    auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
    dorasBackpack[Weapon::Axe] = 3;

    size_t numberRemoved = dorasBackpack.erase(Weapon::Sword);
    if (numberRemoved > 0)
        std::cout << "The Swords were removed.\n";
    else
        std::cout << "Sword was not found in the map.\n";

    std::map<Weapon, int>::iterator found = dorasBackpack.find(Weapon::Axe);
    if (found != dorasBackpack.end())
    {
        dorasBackpack.erase(found);
        std::cout << "The Axes were removed.\n";
    }
    else
        std::cout << "Axe was not found in the map.\n";





    /*
        CHALLENGE 1:

                    print the students and grades below
                        use std::setw and std::left and std::right to format the output
                    ask for the name of the student to drop from the grades map
                        use std::getline to get the user's input
                    remove the student from the map
                    print message indicating what happened
                    if not found print an error message
                    else print the map again and print that the student was removed


    */
    srand((unsigned int)time(NULL));
    std::map<std::string, double> grades;
    grades["Bruce"] = rand() % 101;
    grades["Dick"] = rand() % 101;
    grades["Diana"] = rand() % 101;
    grades["Alfred"] = rand() % 101;
    grades["Clark"] = rand() % 101;
    grades["Arthur"] = rand() % 101;
    grades["Barry"] = rand() % 101;

    //Ctrl-K,S to open the surrounds-with option
    do
    {
        PrintGrades("DCU", grades);
        std::string student;
        std::cout << "Name of student to drop: ";
        std::getline(std::cin, student);
        if (student.empty()) break;

        auto find = grades.find(student);
        if (find != grades.end())
        {
            std::cout << student << " has a grade of " << find->second << ". Dropping...\n";
            grades.erase(find);//use the iterator
        }
        else
            std::cout << student << " was not enrolled.\n";

    } while (true);
}