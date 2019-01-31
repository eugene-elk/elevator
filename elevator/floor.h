#pragma once

class abstract_floor
{
protected:
	bool doors; // 0 - closed, 1 - open
	abstract_floor();

public:
	void open_doors();
	void close_doors();
	
};

class floor_one : public abstract_floor
{
public:
	bool button;
	floor_one();
};

class floor_two : public abstract_floor
{
public:
	bool button_up;
	bool button_down;
	floor_two();
};