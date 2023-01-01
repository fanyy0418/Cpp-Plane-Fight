#include "Role.h"
#include "Res.h"
#include "Element.h"
#include "timer.hpp"

Role::Role()
{
	//出生点
	int x = Res::GetInstance()->GetWidth("背景") / 2 - Res::GetInstance()->GetWidth("角色") / 2;
	int y = Res::GetInstance()->GetHeight("背景") - Res::GetInstance()->GetHeight("角色");
	plane = new Element(x, y, "角色", true, 100);
}

void Role::DrawPlane(int index)
{
	plane->DrawElement(index);
}

void Role::MovePlane(int speed)
{
	//异步处理按键控制
	if (GetAsyncKeyState(VK_UP) && plane->GetY() >= 0)
	{
		plane->MoveElement(speed, Point::Dir::Up);
	}
	if (GetAsyncKeyState(VK_DOWN) &&
		plane->GetY() <=
		Res::GetInstance()->GetHeight("背景") - Res::GetInstance()->GetHeight("角色"))
	{
		plane->MoveElement(speed, Point::Dir::Down);
	}
	if (GetAsyncKeyState(VK_LEFT) && plane->GetX() >= 0)
	{
		plane->MoveElement(speed, Point::Dir::Left);
	}
	if (GetAsyncKeyState(VK_RIGHT) &&
		plane->GetX() <=
		Res::GetInstance()->GetWidth("背景") - Res::GetInstance()->GetWidth("角色"))
	{
		plane->MoveElement(speed, Point::Dir::Right);
	}

	//子弹发射
	if (GetAsyncKeyState(VK_SPACE) && MyTimer::Timer(100, 0))
	{
		mciSendString("close ./res/f_gun.mp3", 0, 0, 0);
		mciSendString("open ./res/f_gun.mp3", 0, 0, 0);
		mciSendString("play ./res/f_gun.mp3", 0, 0, 0);
		bullet.push_back(new Element(plane->GetX() + 45, plane->GetY() - 20, "子弹", true));
	}
	DrawBullet();
	MoveBullet(1);
}

void Role::DrawBullet()
{
	for (auto v : bullet)
	{
		if (v->GetLive())
		{
			v->DrawElement();
		}
	}
}

void Role::MoveBullet(int speed)
{
	for (auto v : bullet)
	{
		v->GetY() -= speed;
	}
}

Element*& Role::GetPlane()
{
	return plane;
}

list<Element*>& Role::GetBullet()
{
	return bullet;
}

//Role::~Role()
//{
//}