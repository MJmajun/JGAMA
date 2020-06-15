#include "JGame.h"
#include <windows.h>
int main()
{
	//随机初始化
	srand (GetTickCount());

	//定义井字棋的实例对象
	
	JGMAE jgame;

	//开始游戏
	jgame.play();
	return 0;
}
