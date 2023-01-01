#include "Point.h"

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

int& Point::GetX()
{
	// TODO: 在此处插入 return 语句
	return x;
}

int& Point::GetY()
{
	// TODO: 在此处插入 return 语句
	return y;
}

void Point::Move(int speed, enum class Dir dir)
{
	//坐标原点在屏幕左上角
	switch (dir)
	{
	case Point::Dir::Left:
		this->x -= speed;
		break;
	case Point::Dir::Right:
		this->x += speed;
		break;
	case Point::Dir::Down:
		this->y += speed;
		break;
	case Point::Dir::Up:
		this->y -= speed;
		break;
	}
}