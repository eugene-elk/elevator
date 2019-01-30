#pragma once

#include <vector>
#include "floor.h"

class elevator
{
private:
	int position;
	bool doors; // 0 - closed, 1 - open
	void move_up();
	void move_down();
	void open_doors();
	void close_doors();
	std::vector <floor1> floors;

public:
	
	void go_to(int target_floor);
	elevator(int height);
};