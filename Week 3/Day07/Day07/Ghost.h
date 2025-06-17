#pragma once
#include "../../../Shared/Console/Console.h"
#include "enums.h"
class Ghost
{
	//access modifiers: control what code can see
	//public: 
	//	all code can see it
	//private: (default if you don't specify)
	//	ONLY* this class can see it
	//protected: (inheritance) 
	//	this class and ALL descendent classes can see it
public:
	//
	// Constructors (ctor)
	// PURPOSE: build, initialize the object so that it is ready to use
	// 
	//	IF you don't have a ctor, the compiler will give  you a DEFAULT ctor
	//  a DEFAULT ctor is a ctor w/out parameters.
	//  if the ctor is simple enough, it can be defined in the header
	//  otherwise, define it in the cpp
	//
	//  IF you provide a ctor, the compiler's default ctor is no longer available
	Ghost(ConsoleColor color, int x, int y);
	
	//methods (member functions) behavior. what can the object do?
	void Move(Direction direction);

	//getters (accessors)
	//  most of the time they are const method
	//  return type matches the type of the field
	//  these can be defined in the header
	Mode GetMode() const { return mode_; }

	ConsoleColor Color() const { return color_; }

	//setters (mutators) 
	//  they allow changes to the field
	//  return type is usually void
	//  usually 1 parameter with the same type as the field
	void SetMode(Mode newMode)
	{
		//gatekeeper code
		if (newMode >= Chase && newMode <= Flee)
		{
			mode_ = newMode;
		}
	}
	void Color(ConsoleColor color)
	{
		if (color != ConsoleColor::Yellow)
			color_ = color;
	}

private:
	// FIELDS (data members) describes the object
	// in general, make them private
	// choose a naming convention so that you can visually 
	// see the difference between fields, parameters, local variables
	ConsoleColor color_;//mColor m_color _color
	Mode mode_;
	int speed_;
	int x_, y_;

	void Sample(ConsoleColor inColor)
	{
		ConsoleColor color = ConsoleColor::Red;

		color_ = color;
	}
};

