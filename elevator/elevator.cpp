#include <windows.h>
#include <iostream>

#include "elevator.h"

using namespace std;

elevator::elevator(int height)
{
	position = 0;
	for (int i = 0; i < height; i++)
	{
		floor1 new_floor;
		floors.push_back(new_floor);
	}
}

void elevator::move_up()
{
	position += 1;
	Sleep(200);
	cout << "Elevator position: " << position << endl;
}

void elevator::move_down()
{
	position -= 1;
	Sleep(200);
	cout << "Elevator position: " << position << endl;
}

void elevator::open_doors()
{
	doors = true;
	floors[position].open_doors();
	cout << "Elevator opens doors at floor " << position << endl;
	
}

void elevator::close_doors()
{
	doors = false;
	floors[position].close_doors();
	cout << "Elevator closes doors at floor " << position << endl;
}

void elevator::go_to(int target_floor)
{
	close_doors();
	while (target_floor != position)
	{
		if (target_floor > position)
			move_up();
		else
			move_down();
	}
	open_doors();
}