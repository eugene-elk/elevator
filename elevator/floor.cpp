#include "floor.h"
#include <iostream>

using namespace std;

abstract_floor::abstract_floor()
{
	doors = false;
}

void abstract_floor::open_doors()
{
	doors = true;
}

void abstract_floor::close_doors()
{
	doors = false;
}

floor_one::floor_one() : abstract_floor()
{
	button = false;
}

floor_two::floor_two() : abstract_floor()
{
	button_up = false;
	button_down = false;
}
