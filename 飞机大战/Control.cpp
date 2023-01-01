#include "Control.h"
#include <vector>

Control::Control()
{
	Widget* pw = new Widget;
	Role* prole = new Role;
	Enemy* penemy = new Enemy;
}
//����
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
//�ƶ�
void Control::Move()
{
	prole->MovePlane(1);
	if (MyTimer::Timer(20, 2))
	{
		penemy->MoveEnemy(1);
	}
}
//��ײ
void Control::Play()
{
	//bullet 19*24
	//enemy  52*39
	//��ײ����
	//X<=35.5
	//Y<=31.5
	int enemyX, enemyY;//enemy(x,y)
	int bulletX, bulletY;//bullet(x,y)
	list<Element*>& enemies = penemy->GetEnemy();//��ȡenemy����
	list<Element*>& bullets = prole->GetBullet();//��ȡbullet����
	//��ײ�ж�
	for (auto v : enemies)
	{
		//ֻ�������Ԫ��
		if (v->GetLive())
		{
			enemyX = v->GetX();
			enemyY = v->GetY();
			for (auto u : bullets)
			{
				//ֻ�������Ԫ��
				if (u->GetLive())
				{
					bulletX = u->GetX();
					bulletY = u->GetY();
					//��ײ��Χ�ж�
					if ((abs(bulletX - enemyX) <= 35) && (abs(bulletY - enemyY) <= 31))
					{
						//����
						v->GetHp() - 1 > 0 ? v->hit(1/*u->GetHp()*/) : v->dead();
						u->dead();
					}
				}
			}
		}
	}
}