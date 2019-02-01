#include <iostream>
#include <string>
#include <fstream>

#include "floor.h"
#include "elevator.h"

using namespace std;

int main()
{
	elevator_two elv(8);
	ifstream fin("commands.txt");

	int num;
	char command, direction;
	int floor;
	fin >> num;
	for (int i = 0; i < num; i++)
	{
		fin >> command;
		if (command == 'o')
		{
			fin >> direction;
			fin >> floor;
			if (direction == 'u')
				elv.floors[floor].button_up = true;
			if (direction == 'd')
				elv.floors[floor].button_down = true;
		}
		else if (command == 'i')
		{
			fin >> floor;
			elv.buttons[floor] = true;
		}
		elv.go_to();
	}
	fin.close();
	return 0;
}