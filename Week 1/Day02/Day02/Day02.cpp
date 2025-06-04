#include <iostream>
#include <string>
#include <vector>
#include "FullSailCourse.h"

bool postFix(std::string& hero)
{
    srand((unsigned int)time(NULL));
    int postFixNumber = rand() % 1000;
    hero = hero + "-" + std::to_string(postFixNumber);
    return postFixNumber % 2 == 0;
}

float average(const std::vector<int>& scores)
{
    //scores.push_back(5); //not allowed because it is marked as const
    float sum = 0;
    for (auto score : scores)
        sum += score;

    return sum / scores.size();
}

void print(const std::vector<int>& scores)
{
    std::cout << "----SCORES----\n";
    int index = 1;
    for (int score : scores)
        std::cout << index++ << ". " << score << "\n";
}

void printInfo(const std::vector<int>& scores)
{
    //size() - # of items in a vector
    //capacity() - length of the internal array
    //size() <= capacity()
    std::cout << "size: " << scores.size() << "\tcapacity: " << scores.capacity() << "\n";
}

// pass by reference:
//   good for performance. does not make a copy. copies are "expensive"
//          especially for classes. 
//          if the parameter type is a class, pass it by reference
//   good for changing a variable in a different scope (regarless of type)
void PrintMe(std::string& message)//pass by reference (making an alias)
{
    message += "(edited)";
    std::cout << message;
}

void changeMe(std::string& toChange)
{
    toChange += "changed";
}

bool CurveGrade(float& grade,float& curveAmt)
{
    if (grade < 59.5)
    {
        curveAmt = 5;
        grade += curveAmt;//grade is the same as myGrade in main
        return true;
    }
    return false;
}
void MakeACopy(float grade)//pass by value (COPY). grade is a separate variable.
{
    float amt;
    bool curved = CurveGrade(grade, amt);//float& grade = grade;
    //grade += 5;//ONLY changing the local variable
}

void LookAt(const std::string& mySecretIdentity, 
            std::string& alternateIdentity)
{
    alternateIdentity = "Peter Parker";
    //mySecretIdentity = "Peter Parker";//changes!
    std::cout << mySecretIdentity << "\n";//cout does not change the variable
    //changeMe(mySecretIdentity);
}

int main()
{
    std::string identity = "Bruce Wayne";
    std::string alternate;
    LookAt(identity, alternate);

    float myGrade = 59.4;
    MakeACopy(myGrade);//float grade = myGrade; //COPY
    float curveAmount;

    bool wasCurved = CurveGrade(myGrade, curveAmount);//float& grade = myGrade; //a reference
    if (wasCurved)
    {
        std::cout << "My grade was curved by " << curveAmount << " to " << myGrade << "\n";
    }
    float steevsGrade = 12; 
    wasCurved = CurveGrade(steevsGrade, curveAmount);//float& grade = steevsGrade; //a reference
    if (wasCurved)
    {
        std::cout << "My grade was curved by " << curveAmount << " to " << steevsGrade << "\n";
    }

    float grade = myGrade;//grade is a separate variable. copies myGrade.
    grade += 5;//myGrade is NOT changed
    float& gradeRef = myGrade;//gradeRef is a NEW NAME for myGrade.
    gradeRef += 5;//myGrade changes

    std::string m1 = "I am the hero you need.";
    changeMe(m1);
    std::string msg = m1;// making a copy
    msg += " ~Batman";
    //msg is a SEPARATE variable from m1
    //changes to msg DO NOT affect m1

    //& - reference or address-of
    //a reference variable refers to another variable
    std::string bruce = "Bruce Wayne";
    std::string& batman = bruce;//batman is the SAME variable as bruce
    batman = "OUCH!";//bruce changes too
    std::cout << bruce << "\n" << batman << "\n";

    std::cout << msg << "\n";
    PrintMe(msg);//copies msg to message
    std::cout << msg << "\n";
    /*
        ╔══════════════════════════════╗
        ║Parameters: Pass by Reference.║
        ╚══════════════════════════════╝
        Sends the variable itself to the method. The method parameter gives the variable a NEW name (i.e. an alias)

        NOTE: if the method assigns a new value to the parameter, the variable used when calling the method will change too.
            This is because the parameter is actually just a new name for the other variable.
    */
    std::string spider = "Spiderman";
    bool isEven = postFix(spider);
    std::string evenResult = (isEven) ? "TRUE" : "FALSE";
    std::cout << spider << "\n" << "Is Even postfix? " << evenResult << "\n";




    /*
        ╔══════════════════╗
        ║ const parameters ║
        ╚══════════════════╝
        const is short for constant. It prevents the variable from being changed in the method.

        This is the way you pass by reference and prevent the method from changing the variable.
    */
    std::vector<int> highScores;
    highScores.reserve(10);
    printInfo(highScores);//size: 0?  capacity: 0?
    for (int i = 0; i < 20; ++i)
    {
        highScores.push_back(rand() % 5000);
        printInfo(highScores);//size: ?  capacity: ?
    }
    float avg = average(highScores);



    /*
        CHALLENGE 1:

            Write a method to fill the vector of floats with grades.
            1) pass it in by reference
            2) add 10 grades to the vector

    */
    FullSailCourse pg2, pg1, spr;
    std::vector<float> grades;
    pg2.FillMyVectorWithGrades(grades);
    pg2.PrintMyVectorOfGrades(grades);

    /*
        CHALLENGE 2:

            Write a method to calculate the stats on a vector of grades
            1) create a method to calculate the min, max. 
                pass the grades vector as a const reference. Use ref parameters for min and max.
            2) call the method in main and print out the min, max.

    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        [  Removing from a vector  ]

        clear() - removes all elements from the vector
        erase(position) - removes the element at the position
        erase(starting position, ending position) - removes a range of elements. the end position is not erased.

    */
    print(highScores);

    //erase all scores < 2500
    for (int i = 0; i < highScores.size(); i++)
    {
        if (highScores[i] < 2500)
        {
            highScores.erase(highScores.begin() + i);
            i--;//move the index back 1 
        }
    }
    //OR...
    for (int i = 0; i < highScores.size();)
    {
        if (highScores[i] < 2500)
        {
            highScores.erase(highScores.begin() + i);
        }
        else
            i++;//only increment when we don't erase
    }
    //OR...
    for (int i = highScores.size() - 1; i >= 0; i--)
    {
        if (highScores[i] < 2500)
        {
            highScores.erase(highScores.begin() + i);
        }
    }
    //OR...
    auto iter = highScores.begin();
    for (;iter != highScores.end();)
    {
        if (*iter < 2500)
        {
            iter = highScores.erase(iter);
        }
        else iter++;
    }

    print(highScores);



    /*
        CHALLENGE 3:

            Using the vector of grades you created.
            Remove all the failing grades (grades < 59.5).
            Print the grades.
    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        
        size(): # of items that have been ADDED
        capacity(): length of the internal array
        reserve(n): presizes the internal array
    */
    std::vector<int> scores;
    scores.reserve(10); //makes the internal array to hold 10 items.

    printInfo(scores);
}