#include "Res.h"
map<string, IMAGE*> Res::img;//静态变量类外定义
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
	//背景
	img["背景"] = new IMAGE;
	loadimage(img["背景"], "res//background.jpg");

	//飞机
	img["角色"] = new IMAGE[2];
	loadimage(img["角色"] + 0, "res//planeNormal_1.jpg");
	loadimage(img["角色"] + 1, "res//planeNormal_2.jpg");

	//子弹
	img["子弹"] = new IMAGE[2];
	loadimage(img["子弹"] + 0, "res//bullet1.jpg");
	loadimage(img["子弹"] + 1, "res//bullet2.jpg");

	//敌机
	img["敌机"] = new IMAGE[2];
	loadimage(img["敌机"] + 0, "res//enemy_1.jpg");
	loadimage(img["敌机"] + 1, "res//enemy_2.jpg");
}