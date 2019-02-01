#pragma once

#include <vector>
#include "floor.h"

class abstract_elevator
{
protected:
	int height;
	bool doors; // 0 - closed, 1 - open
	void move_up();
	void move_down();
	virtual void open_doors();
	virtual void close_doors();
	virtual bool any_button_pressed() = 0;
	abstract_elevator();

public:
	int position;
	std::vector <bool> buttons;
	virtual void go_to() = 0;
};

class elevator_one : public abstract_elevator
{
private:
	bool any_button_pressed() override;

public:
	void close_doors() override;
	void open_doors() override;
	std::vector <floor_one> floors;
	void go_to() override;
	elevator_one(int height);
};

class elevator_two : public abstract_elevator
{
private:
	friend void elevator_one::open_doors();
	friend void elevator_one::close_doors();

public:
	bool any_button_pressed() override;
	std::vector <floor_two> floors;
	void go_to() override;
	elevator_two(int height);
	int direction; // -1 - down, 0 - stop, 1 - up
};
