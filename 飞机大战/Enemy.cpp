#include "Enemy.h"
#include "Res.h"
void Enemy::DrawEnemy()
{
	for (auto v : enemy)
	{
		if (v->GetLive())
		{
			v->DrawElement();
		}
	}
}

void Enemy::MoveEnemy(int speed)
{
	for (auto v : enemy)
	{
		v->MoveElement(speed, Point::Dir::Down);
	}
}

void Enemy::CreatEnemy()
{
	int x = rand() % (Res::GetInstance()->GetWidth("背景") / 100) * 100 + (Res::GetInstance()->GetWidth("角色") / 2);
	int y = -1 * 150;
	enemy.push_back(new Element(x, y, "敌机", true, 3));
}

list<Element*>& Enemy::GetEnemy()
{
	// TODO: 在此处插入 return 语句
	return enemy;
}