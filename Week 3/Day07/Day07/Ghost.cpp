#include "Ghost.h"

Ghost::Ghost(ConsoleColor color, int x, int y) :
	//member initialization list
	//  a comma-separated list
	color_(color), x_(x), y_(y), mode_(Mode::Chase), speed_(0)
{
}

void Ghost::Move(Direction direction)
{
	//update the position based on the direction
}
