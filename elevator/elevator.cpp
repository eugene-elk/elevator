#include <windows.h>
#include <iostream>

#include "elevator.h"

using namespace std;

abstract_elevator::abstract_elevator()
{
	position = 0;
}

elevator_one::elevator_one(int new_height) : abstract_elevator()
{
	height = new_height;
	for (int i = 0; i < new_height; i++)
	{
		floor_one new_floor;
		bool new_button = false;
		floors.push_back(new_floor);
		buttons.push_back(new_button);
	}
}

elevator_two::elevator_two(int new_height) : abstract_elevator()
{
	direction = 0;
	height = new_height;
	for (int i = 0; i < new_height; i++)
	{
		floor_two new_floor;
		bool new_button = false;
		floors.push_back(new_floor);
		buttons.push_back(new_button);
	}
}

void abstract_elevator::move_up()
{
	position += 1;
	cout << "Elevator position: " << position << endl;
}

void abstract_elevator::move_down()
{
	position -= 1;
	cout << "Elevator position: " << position << endl;
}

// Open doors methods
void abstract_elevator::open_doors()
{
	doors = true;
	cout << "Elevator opens doors at floor " << position << endl;
}

void elevator_one::open_doors()
{
	abstract_elevator::open_doors();
	floors[position].open_doors();
}

// Close doors methods
void abstract_elevator::close_doors()
{
	doors = false;
	cout << "Elevator closes doors at floor " << position << endl;
}

void elevator_one::close_doors()
{
	abstract_elevator::close_doors();
	floors[position].close_doors();
}

// Checking buttons
bool elevator_one::any_button_pressed()
{
	bool result = false;
	for (int i = 0; i < height; i++)
	{
		if (buttons[i]) result = true;
		if (floors[i].button) result = true;
	}
	return result;
}

bool elevator_two::any_button_pressed()
{
	bool result = false;
	for (int i = 0; i < height; i++)
	{
		if (buttons[i]) result = true;
		if (floors[i].button_up) result = true;
		if (floors[i].button_down) result = true;
	}
	return result;
}

void elevator_one::go_to()
{
	// где-то нажата кнопка и двери закрыты
	if (any_button_pressed() && !doors)
	{
		if (buttons[position] || floors[position].button)
		{
			open_doors();
			buttons[position] = false;
			floors[position].button = false;
		}
		else
		{
			int target_floor;
			// choose floor to move to
			for (int i = 0; i < height; i++)
				if (floors[i].button)
					target_floor = i;

			for (int i = height - 1; i >= 0; i--)
				if (buttons[i])
					target_floor = i;
			
			if (target_floor > position) 
				move_up();
			else
				move_down();
		}
	}
	else
		close_doors();
}

void elevator_two::go_to()
{
	static bool doors_were_already_opening = false;
	if (any_button_pressed() && !doors)
	{
		if ((buttons[position] || floors[position].button_up || floors[position].button_down)
			&& !doors_were_already_opening)
		{
			open_doors();
			buttons[position] = false;
			doors_were_already_opening = true;
			if (floors[position].button_up && direction == 1) {
				floors[position].button_up = false;
			}
			else if (floors[position].button_down && direction == -1) {
				floors[position].button_down = false;
			}
		}
		else
		{
			int target_floor;
			// choose floor to move to
			for (int i = 0; i < height; i++)
				if ((floors[i].button_up) || (floors[i].button_down))
					target_floor = i;

			for (int i = height - 1; i >= 0; i--)
				if (buttons[i])
					target_floor = i;

			if (target_floor > position)
			{
				cout << "Move up to " << target_floor << endl;
				move_up();
				direction = 1;
				doors_were_already_opening = false;
			}
			else if (target_floor < position)
			{
				cout << "Move down to " << target_floor << endl;
				move_down();
				direction = -1;
				doors_were_already_opening = false;
			}
			else
			{
				direction = 0;
				doors_were_already_opening = true;
				floors[position].button_up = false;
				floors[position].button_down = false;
			}
		}
	}
	else 
	{
		if (doors)
			close_doors();
		direction = 0;
	}
}
