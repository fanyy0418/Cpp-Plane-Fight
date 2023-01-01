#include "Res.h"
map<string, IMAGE*> Res::img;//��̬�������ⶨ��
int Res::GetWidth(string name)
{
	return img[name]->getwidth();
}

int Res::GetHeight(string name)
{
	return img[name]->getheight();
}

Res* Res::GetInstance()
{
	static Res* pres = new Res;
	return pres;
}

void Res::DrawIMG(int x, int y, string name)
{
	putimage(x, y, GetInstance()->img[name]);
}

void Res::DrawIMG(int x, int y, string name, int index)
{
	putimage(x, y, GetInstance()->img[name] + index, NOTSRCERASE);
	putimage(x, y, GetInstance()->img[name] + index + 1, SRCINVERT);
}

Res::Res()
{
	//����
	img["����"] = new IMAGE;
	loadimage(img["����"], "res//background.jpg");

	//�ɻ�
	img["��ɫ"] = new IMAGE[2];
	loadimage(img["��ɫ"] + 0, "res//planeNormal_1.jpg");
	loadimage(img["��ɫ"] + 1, "res//planeNormal_2.jpg");

	//�ӵ�
	img["�ӵ�"] = new IMAGE[2];
	loadimage(img["�ӵ�"] + 0, "res//bullet1.jpg");
	loadimage(img["�ӵ�"] + 1, "res//bullet2.jpg");

	//�л�
	img["�л�"] = new IMAGE[2];
	loadimage(img["�л�"] + 0, "res//enemy_1.jpg");
	loadimage(img["�л�"] + 1, "res//enemy_2.jpg");
}