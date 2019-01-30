#include "floor.h"

floor1::floor1()
{
	doors = false;
}

void floor1::open_doors()
{
	doors = true;
}

void floor1::close_doors()
{
	doors = false;
}