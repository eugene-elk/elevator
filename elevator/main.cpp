#include <iostream>
#include <string>
#include <fstream>

#include "floor.h"
#include "elevator.h"

using namespace std;

int main()
{
	elevator_one elv(8);
	ifstream fin("commands.txt");

	int num;
	char command;
	int floor;
	fin >> num;
	for (int i = 0; i < num; i++)
	{
		fin >> command;
		if (command == 'o')
		{
			fin >> floor;
			elv.buttons[floor] = true;
		}
		else if (command == 'i')
		{
			fin >> floor;
			elv.floors[floor].button = true;
		}
		elv.go_to();
	}

	return 0;
}