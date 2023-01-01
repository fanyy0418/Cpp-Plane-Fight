#include "Widget.h"
#include "Res.h"
Widget::Widget()
{
	initgraph(WIDTH, HEIGHT);
}

void Widget::show()
{
	Res::DrawIMG(0, 0, "±³¾°");
}

Widget::~Widget()
{
}