#include "Control.h"
#include <vector>

Control::Control()
{
	Widget* pw = new Widget;
	Role* prole = new Role;
	Enemy* penemy = new Enemy;
}
//创建
void Control::Draw()
{
	pw->show();
	prole->DrawPlane();
	if (MyTimer::Timer(1000, 1))
	{
		penemy->CreatEnemy();
	}
	penemy->DrawEnemy();
}
//移动
void Control::Move()
{
	prole->MovePlane(1);
	if (MyTimer::Timer(20, 2))
	{
		penemy->MoveEnemy(1);
	}
}
//碰撞
void Control::Play()
{
	//bullet 19*24
	//enemy  52*39
	//碰撞区间
	//X<=35.5
	//Y<=31.5
	int enemyX, enemyY;//enemy(x,y)
	int bulletX, bulletY;//bullet(x,y)
	list<Element*>& enemies = penemy->GetEnemy();//获取enemy链表
	list<Element*>& bullets = prole->GetBullet();//获取bullet链表
	//碰撞判定
	for (auto v : enemies)
	{
		//只计算存活的元素
		if (v->GetLive())
		{
			enemyX = v->GetX();
			enemyY = v->GetY();
			for (auto u : bullets)
			{
				//只计算存活的元素
				if (u->GetLive())
				{
					bulletX = u->GetX();
					bulletY = u->GetY();
					//碰撞范围判定
					if ((abs(bulletX - enemyX) <= 35) && (abs(bulletY - enemyY) <= 31))
					{
						//致死
						v->GetHp() - 1 > 0 ? v->hit(1/*u->GetHp()*/) : v->dead();
						u->dead();
					}
				}
			}
		}
	}
}