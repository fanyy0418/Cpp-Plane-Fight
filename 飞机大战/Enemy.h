#pragma once
#include "Common.h"
#include "Element.h"
class Element;
class Enemy
{
public:
	void DrawEnemy();
	void MoveEnemy(int speed);
	void CreatEnemy();
	list<Element*>& GetEnemy();

private:
	list<Element*> enemy;
};