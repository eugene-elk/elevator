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
	void open_doors() override;
	void close_doors() override;
	bool any_button_pressed() override;

public:
	std::vector <floor_one> floors;
	void go_to() override;
	elevator_one(int height);
};

class elevator_two : public abstract_elevator
{
private:
	void open_doors() override;
	void close_doors() override;
	bool any_button_pressed() override;

public:
	std::vector <floor_two> floors;
	void go_to() override;
	elevator_two(int height);
};
