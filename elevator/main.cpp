#include <iostream>
#include <string>

#include "floor.h"
#include "elevator.h"
#include "house.h"

using namespace std;

int main()
{
	elevator flex(10);

	string input = "";
	while (input != "exit")
	{
		cin >> input;
		if (input[0] == 'o') 
		{
			input.erase(0, 1);
			int target_floor = stoi(input);
			flex.go_to(target_floor);
		}
		else if (input[0] == 'i') 
		{
			input.erase(0, 1);
			int target_floor = stoi(input);
			flex.go_to(target_floor);
		}
	}

	return 0;
}