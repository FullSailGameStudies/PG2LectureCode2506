// Day05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Console.h"
#include "Input.h"
#include <iomanip> 

enum class Weapon
{
    Sword, Axe, Spear, Mace
};

int LinearSearch(const std::vector<int>& numbers, int numberToFind)
{
    for (int i = 0; i < numbers.size(); i++)
        if (numbers[i] == numberToFind)
            return i;
    return -1;
}

void PrintGrades(const std::string& className,const std::map<std::string, double>& grades)
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
    srand(time(NULL));
    /*
        ╔═════════╗
        ║Searching║
        ╚═════════╝

        There are 2 ways to search a vector: linear search or binary search

        CHALLENGE:

            write a method to linear search the numbers list.
                The method should take 2 parameters: 
                        vector of ints to search, 
                        int to search for.
                The method should return -1 if NOT found or the index if found.

            The algorithm:
                1) start at the beginning of the vector
                2) compare each item in the vector to the search item
                3) if found, return the index
                4) if reach the end of the vector, return -1 which means not found

    */
    std::vector<int> numbers = { 0,1,2,3,4,5,6 };
    int searchNumber = 15;
    int index = LinearSearch(numbers, searchNumber);
    if (index == -1) std::cout << searchNumber << " not found\n";
    else std::cout << searchNumber << " found at " << index << "\n";

    searchNumber = 0;
    index = LinearSearch(numbers, searchNumber);
    if (index == -1) std::cout << searchNumber << "not found\n";
    else std::cout << searchNumber << " found at " << index << "\n";

    searchNumber = 6;
    index = LinearSearch(numbers, searchNumber);
    if (index == -1) std::cout << searchNumber << "not found\n";
    else std::cout << searchNumber << " found at " << index << "\n";


    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Creating a map  ]

        map<TKey, TValue>  - an associative collection.
            TKey is a placeholder for the type of the keys.
            TValue is a placeholder for the type of the values.

        When you want to create a map variable,
            1) replace TKey with whatever type of data you want to use for the keys
            2) replace TValue with the type you want to use for the values


        [  Adding items to a map  ]

        There are 2 ways to add items to a map:
        1) using the insert method.
        2) using [key] = value
    */
    std::map<Weapon, int> dorasBackpack;//will store the counts of each kind of weapon

    //returns an iterator and a bool. 
    //if the key is already in the map, it will NOT insert it -- the bool will be false.
    auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
    if (inserted.second == false) //meaning not inserted
        std::cout << "The key was already in the map. It was not inserted.\n";
    else
        std::cout << "The key was inserted in the map.\n";

    dorasBackpack[Weapon::Axe] = 3;
    dorasBackpack[Weapon::Axe] = 7;//simply overwrites the value if the key is already in the map


    std::map<std::string, float> menu;
    //2 ways to add data...
    //1) easy way map[key] = value;
    menu["pizza"] = 24.99F;
    menu["corndog"] = 1.99f;
    menu["coffee"] = 4.99f;
    menu["taco"] = 2.99f;
    menu["taco"] = 3.99f;//overwrites the value

    //2) not-easy way
    //   map.insert(pair)
    //   pair objs have 2 parts: first, second
    std::pair<std::string, float> menuPair =
        std::make_pair("cheeeeeez Burger", 8.99f);
    menu.insert(menuPair);
    menuPair.second = 9.99f;
    auto itemInsert = menu.insert(menuPair);//does NOT overwrite if the key is already in the map
    if (itemInsert.second != true) //was NOT inserted
    {
        std::cout << "The menu item already exists. Do you want to update the price? (Y/N)\n\n";
    }

    
    std::cout << "\nWelcome to Quarters\n";
    for (auto i = menu.begin(); i != menu.end(); i++)
    {
        std::cout << i->first << " ";
        std::cout << i->second << "\n";
    }
    std::cout << "\n";

    for (auto& mPair : menu)
    {
        std::cout << mPair.first << " ";
        std::cout << mPair.second << "\n";
    }

    std::cout << "\nWelcome to Quarters\n";
    for (auto& [itemName,itemPrice] : menu)
    {
        std::cout << std::setw(17) << std::left << itemName << " ";
        std::cout << std::right << std::setw(8) << itemPrice << "\n";
    }
    std::cout << "\nWelcome to Quarters\n";
    for (auto& [itemName, itemPrice] : menu)
    {
        Console::Write(itemName, ConsoleColor::Cyan);
        Console::SetCursorLeft(18);
        std::cout << std::right << std::setw(8);// << itemPrice << "\n";
        Console::WriteLine(itemPrice, ConsoleColor::Yellow);
    }

    std::string itemToFind = "cheeeeeez Burger";
    //auto item = menu[itemToFind];//don't do this to find an item
    auto foundItem = menu.find(itemToFind);
    //not found
    if (foundItem == menu.end())
        std::cout << itemToFind << " is not on the menu. Try McDonald's\n";
    else
    {
        float oldPrice = foundItem->second;
        foundItem->second = oldPrice * 1.10;
        std::cout << itemToFind << " used to costs " << oldPrice << "\n";
        std::cout << itemToFind << " now costs " << foundItem->second << ". Thanks PUTIN!!\n";
    }

    /*
        CHALLENGE:

            Create a map that stores names (string) and grades. Call the variable grades.
            Add students and grades to your map.

    */
    /*
        CHALLENGE:

            Loop over your grades map and print each student name and grade.

    */

    std::map<std::string, double> grades;

    std::vector<std::string> students{
        "Garrett","Yansel","Damien","Alex","Abigail","Alexandre","Joshua",
"Jose","Brian","Phillip","Corey","Albert","Asher","Bailey","Einjar",
"Jacob","Marcus","Miguel","Nelson"
    };
    for (auto& student : students)
    {
        grades[student] = rand() % 10001 / 100.0;
    }
    PrintGrades("PG2-2506", grades);





    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Looping over a map  ]

        You should use a ranged-based for loop when needing to loop over the entire map.

    */
    for (auto const& [key, val] : dorasBackpack) //requires C++ 20
    {
        switch (key)
        {
        case Weapon::Sword:
            std::cout << "Sword: ";
            break;
        case Weapon::Axe:
            std::cout << "Axe: ";
            break;
        case Weapon::Spear:
            std::cout << "Spear: ";
            break;
        case Weapon::Mace:
            std::cout << "Mace: ";
            break;
        default:
            break;
        }
        std::cout << val << "\n";
    }




    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Checking for a key in a map  ]

        use the find method to check if the key is in the map

        will return map.end() if NOT found.

    */
    std::map<Weapon, int>::iterator foundIter = dorasBackpack.find(Weapon::Mace);
    if (foundIter == dorasBackpack.end()) //meaning it was NOT found
    {
        std::cout << "Dora did not find any maces.\n";
    }
    else
    {
        //can safely grab the value for the key
        std::cout << "Dora found " << foundIter->second << " Maces\n";
    }



    /*
        CHALLENGE:

            look for a specific student in the map.
            If the student is found, print out the student's grade
            else print out a message that the student was not found

    */




    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Updating a value for a key in a map  ]

        To update an exisiting value in the map, use the [ ]


    */
    dorasBackpack[Weapon::Axe] = 1;//updates the count for the axe



    /*
        CHALLENGE:

            Pick any student and curve the grade (add 5) that is stored in the grades map

    */
}