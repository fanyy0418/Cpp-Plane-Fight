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
	int x = rand() % (Res::GetInstance()->GetWidth("����") / 100) * 100 + (Res::GetInstance()->GetWidth("��ɫ") / 2);
	int y = -1 * 150;
	enemy.push_back(new Element(x, y, "�л�", true, 3));
}

list<Element*>& Enemy::GetEnemy()
{
	// TODO: �ڴ˴����� return ���
	return enemy;
}