#include "Control.h"
int main()
{
	srand((unsigned int)time(nullptr));
	Control* pc = new Control;
	BeginBatchDraw();
	while (true)
	{
		pc->Draw();
		pc->Move();
		pc->Play();
		FlushBatchDraw();
	}
	EndBatchDraw();

	return 0;
}