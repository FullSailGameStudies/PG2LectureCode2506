// Day10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Console.h"
#include "Input.h"



/*
    ╔══════════╗
    ║ File I/O ║
    ╚══════════╝

    3 things are required for File I/O:
    1) Open the file
    2) read/write to the file
    3) close the file



*/
int main()
{
    std::cout << "Hello PG2!\n";

    /*

        ╔════════════════╗
        ║ write csv data ║
        ╚════════════════╝

        [  Open the file  ]
        [  Write to the file  ]
        [  Close the file  ]

        you need the path to the file
            use full path ( drive + directories + filename )
            or use relative path ( directories + filename )
            or current directory ( filename )

        Make sure to separate the data in the file with a delimiter.
        The delimiter is important because it is used
            to separate the data when reading the file back in.


        Lecture code: set a filePath variable, open an output file, write some csv data to it
    */

    std::string name = "2506.csv";
    std::string path = "C:/temp/2506/";
    std::string fullPath = path + name;
    //1) OPEN the file
    std::ofstream outFile(fullPath);//open + create/overwrite the file
    //it will NOT create the file if any part of the path does not exists
    //1.1) check if the file is open
    char delimiter = '~';
    if (outFile.is_open())
    {
        //2) write to the file
        outFile << "BATMAN!!" << delimiter << 5 << delimiter << true << delimiter << 13.7;
    }
    else
        std::cout << "Something bad happened. Could not open " << fullPath << "\n";

    //3) CLOSE the file
    outFile.close();

    /*

        ╔═══════════════╗
        ║ read csv data ║
        ╚═══════════════╝

        [  Open the file  ]
        [  read the file  ]
        [  Close the file  ]

        Lecture code: using the filePath variable, open an input file, use getline to read a line, print the line
    */

    std::ifstream inFile(fullPath);
    if (inFile.is_open())
    {
        //2) read to the file
        //use std::getline to read 1 line from the file
        //reads until it finds a \n OR the end of the file
        std::string data;
        std::getline(inFile, data);
        std::cout << data << "\n";

        //parsing the string to get the individual pieces of data
        //use std::getline to read a piece of the data
        std::string sData;
        std::stringstream dataStream(data);
        std::getline(dataStream, sData, delimiter);
        std::cout << sData << "\n";

        try
        {
            std::getline(dataStream, sData, delimiter);
            int iData = std::stoi(sData);
            std::cout << iData << "\n";

            std::getline(dataStream, sData, delimiter);
            bool bData = std::stoi(sData);
            std::cout << bData << "\n";

            std::getline(dataStream, sData, delimiter);
            double dData = std::stod(sData);
            std::cout << dData << "\n";

        }
        catch (const std::exception& ex)
        {
            //handle the exception
            std::cout << "Problem reading the file. please check the format.\n";
            std::cout << ex.what() << "\n";
        }
    }
    else
        std::cout << "Something bad happened. Could not open " << fullPath << "\n";

    //3) CLOSE the file
    inFile.close();


    /*

        ╔═════════════════════╗
        ║ parsing csv strings ║
        ╚═════════════════════╝
        
        use getline on a string stream instead of a file stream

        Lecture code: 
            using the line read in above, use a stringstream to split the line using getline.
            store the separate items in a vector
            parse each item in the vector to an appropriate variable.
        

    */



    //reading until the end of the file
    //while (not inFile.eof()) {}

    //OR...
    //std::string line;
    //while (std::getline(inFile, line)) {}


    /*

        CHALLENGE:

        Parse the multi csv string (below) to get the data.
        NOTE: the data is a collection of object data.
        There are multiple delimiters.
        Separate on the first delimiter (collectionSeparator) to get the csv data for each object.
        Then, separate the object csv data on objectSeparator to get the details of the object.

        EX: hero#hero#hero   each hero is separated by a #
            name^secret^age  the details of each hero is separated by a ^

    */
    std::string multi = "Batman^Bruce Wayne^35#Superman^Clark Kent^25#Wonder Woman^Diana Prince^25#Aquaman^Arthur Curry^12";
    char collectionSeparator = '#';
    char objectSeparator = '^';

    //1) open the stream and read the data
    std::stringstream multiStream(multi);
    while (not multiStream.eof())
    {
        //get the hero
        std::string hero;
        std::getline(multiStream, hero, collectionSeparator);

        //parse the hero data
        std::stringstream heroStream(hero);
        std::string name, secret, agestr;
        int age;
        std::getline(heroStream, name, objectSeparator);
        std::getline(heroStream, secret, objectSeparator);
        std::getline(heroStream, agestr, objectSeparator);
        age = std::stoi(agestr);

        std::cout << "Hello citizen! I am " << name << "! (aka " << secret << "). And I am " << age << " years old.\n";
    }
}