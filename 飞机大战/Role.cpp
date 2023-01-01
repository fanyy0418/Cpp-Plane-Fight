#include "Role.h"
#include "Res.h"
#include "Element.h"
#include "timer.hpp"

Role::Role()
{
	//������
	int x = Res::GetInstance()->GetWidth("����") / 2 - Res::GetInstance()->GetWidth("��ɫ") / 2;
	int y = Res::GetInstance()->GetHeight("����") - Res::GetInstance()->GetHeight("��ɫ");
	plane = new Element(x, y, "��ɫ", true, 100);
}

void Role::DrawPlane(int index)
{
	plane->DrawElement(index);
}

void Role::MovePlane(int speed)
{
	//�첽����������
	if (GetAsyncKeyState(VK_UP) && plane->GetY() >= 0)
	{
		plane->MoveElement(speed, Point::Dir::Up);
	}
	if (GetAsyncKeyState(VK_DOWN) &&
		plane->GetY() <=
		Res::GetInstance()->GetHeight("����") - Res::GetInstance()->GetHeight("��ɫ"))
	{
		plane->MoveElement(speed, Point::Dir::Down);
	}
	if (GetAsyncKeyState(VK_LEFT) && plane->GetX() >= 0)
	{
		plane->MoveElement(speed, Point::Dir::Left);
	}
	if (GetAsyncKeyState(VK_RIGHT) &&
		plane->GetX() <=
		Res::GetInstance()->GetWidth("����") - Res::GetInstance()->GetWidth("��ɫ"))
	{
		plane->MoveElement(speed, Point::Dir::Right);
	}

	//�ӵ�����
	if (GetAsyncKeyState(VK_SPACE) && MyTimer::Timer(100, 0))
	{
		mciSendString("close ./res/f_gun.mp3", 0, 0, 0);
		mciSendString("open ./res/f_gun.mp3", 0, 0, 0);
		mciSendString("play ./res/f_gun.mp3", 0, 0, 0);
		bullet.push_back(new Element(plane->GetX() + 45, plane->GetY() - 20, "�ӵ�", true));
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