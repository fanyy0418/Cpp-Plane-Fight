#pragma once
#include "Common.h"
class Element;
class Role
{
public:
	Role();
	void DrawPlane(int index = 0);
	void MovePlane(int speed);
	void DrawBullet();
	void MoveBullet(int speed);

	Element*& GetPlane();
	list<Element*>& GetBullet();
	/*~Role();*/
private:
	Element* plane;
	list<Element*> bullet;
};