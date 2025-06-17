#pragma once
#include <string>

//add a WhoAmI method to the Person class (print the name and age)
class Person
{
public:
	void WhoAmI() const;

	//write a constructor for the Person class
	//  use the member initialization list to initialize the name and age
	Person(const std::string& name, int age);

	//it's ok to define the getters/setters in the header
	int Age() const { return age_; }
	void Age(int age)
	{
		if (age >= 0 && age <= 130)
			age_ = age;
	}

	const std::string& Name() const { return name_; }
	void Name(const std::string& name)
	{
		if (not name.empty() && name.size() < 32)
			name_ = name;
	}
	

private:
	int age_;
	std::string name_;
};

