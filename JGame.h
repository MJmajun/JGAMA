#ifndef __JGAME_H_
#define __JGAME_H_

class JGAME
{

public:
	
	//构造方法
	JGAME()
	{
		//轮到谁走,如果p=1,人走 否则 电脑走
		p = rand()%2;
		//重新置为空  恢复为原始状态
		reset();

	}
	
	//相应的方法
	void play();	//游戏函数
	void reset();	//棋局最开始的状态函数
	void drawGrid();	//分别给棋子进行赋值
	int checkVictory();	//判断当前棋局是否可以判断输赢
	void getHumanMove();	//人走 
	void getComputerMove();	//电脑走



private:
	int p;	//用来判断是电脑还是人
	int filed[9];	//格子的状态
	emum players { Computer,Human,Draw,None };
	const int iWin[8][3] ={
							{0,1,2}, {3,4,5}, {6,7,8},
							{0,3,6}, {1,4,7}, {2,5,8},
							{0,4,8}, {2,4,6}
						  };

};


#endif
