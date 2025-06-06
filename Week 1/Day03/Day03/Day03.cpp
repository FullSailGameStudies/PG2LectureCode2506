#include <iostream>
#include <string>
#include <vector>
#include "ThemeSong.h"

std::string postFix(const std::string& fileName, int postFixNumber = 1) //postFixNumber is optional
{
    return fileName + "_" + std::to_string(postFixNumber);
}

int main()
{

    /*
        ╔═══════════════════════════════╗
        ║Parameters: optional parameters║
        ╚═══════════════════════════════╝
        https://www.geeksforgeeks.org/default-arguments-c/

        Unless specified, parameters to a method are required.
        However, you can make parameters optional, meaning when calling the method, you aren't required to pass values for the optional parameters.

        REQUIREMENT:
            - all optional parameters have to be at the end of the list of parameters
            - in the list of parameters, assign a value to any parameter you want to be optional
    */
    std::string file = "highScores";

    std::string postfile = postFix(file); //if you don't pass a value, the default value will be used for the optional parameter
    std::cout << postfile << "\n";

    postfile = postFix(file, 5); //if a value is passed, it will be used for the optional parameter
    std::cout << postfile << "\n";



    /*
        CHALLENGE 1:

            add a method called batTheme to the ThemeSong class
            Add an optional parameter to determine how many "na" are printed. 
            The default value should be 13.
            
            If the calling code does not pass a value for the parameter, 
            print "na na na na na na na na na na na na na Batman".
            If a value is passed, print the number of "na" equal to the value.
            EX: if 6 is passed, print "na na na na na na Batman"

    */
    ThemeSong themes;
    themes.batTheme();
    //themes.batTheme(10000);





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        [  copying a vector  ]
        https://www.geeksforgeeks.org/ways-copy-vector-c/

        here are 3 ways to copy a vector:
        1) copy each element manually
        2) assignment "=" operator
        3) passing a vector to the constructor of another vector

    */
    std::vector<int> scores = { 1,2,3,4,5,6,7,8,9,0 };
    std::cout << scores.size() << ": " << scores.capacity() << "\n";

    //1) copy each element manually
    std::vector<int> scores2;
    scores2.reserve(scores.size());
    for (size_t i = 0; i < scores.size(); i++)
        scores2.push_back(scores[i]);
    std::cout << scores2.size() << ": " << scores2.capacity() << "\n";

    //2) assignment "=" operator
    std::vector<int> scores3 = scores;
    std::cout << scores3.size() << ": " << scores3.capacity() << "\n";

    //3) passing a vector to the constructor of another vector
    std::vector<int> scores4(scores);
    std::cout << scores4.size() << ": " << scores4.capacity() << "\n";



    /*
        CHALLENGE 2:

            Copy the JLA vector and add some villains to the new vector. Don't modify the original JLA vector.
    */
    std::vector<std::string> JLA = { "Batman", "Wonder Woman", "Superman", "Flash" };

}