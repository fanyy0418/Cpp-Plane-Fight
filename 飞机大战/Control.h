#pragma once
#include "Widget.h"
#include "Role.h"
#include "Enemy.h"
#include "timer.hpp"
class Control
{
public:
	Control();
	void Draw();
	void Move();
	void Play();
private:
	Widget* pw = new Widget;
	Role* prole = new Role;
	Enemy* penemy = new Enemy;
};
