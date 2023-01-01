#pragma once
#include "Common.h"
class Point
{
public:
	//·½Ïò
	enum class Dir { Left, Right, Down, Up };
	Point(int x = 0, int y = 0);
	int& GetX();
	int& GetY();
	void Move(int speed, enum class Dir dir);
private:
	int x;
	int y;
};