#include "ThemeSong.h"
#include <iostream>
#include "../../../Shared/Console/Console.h"

//define the method
void ThemeSong::batTheme(int numberOfNas)
{
	int x, y;
	int w = Console::GetWindowWidth();
	int h = Console::GetWindowHeight();
	for (int i = 0; i < numberOfNas; i++)
	{
		x = rand() % w;
		y = rand() % h;
		Console::SetCursorPosition(x, y);
		Console::Write("na ", (ConsoleColor)(rand() % 7 + 1));
	}
	std::string bats = "BATMAN!!!";
	Console::SetCursorPosition(w / 2 - bats.size() / 2, h / 2);
	Console::Write(bats, (ConsoleColor)(rand() % 7 + 1));
}