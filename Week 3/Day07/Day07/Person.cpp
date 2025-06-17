#include "Person.h"
#include <iostream>

void Person::WhoAmI() const
{
	std::cout << "Hello. My name is " << name_ << ". I am " << age_ << " years old.\n";
}

Person::Person(const std::string& name, int age) 
	//:	name_(name), age_(age)
{
	Name(name);
	Age(age);
}
