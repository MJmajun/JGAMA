/*
 *项目名:			井子游戏
 *项目创建时间:		2020年06月15日19:17:15
 *作者:				马俊
 *联系方式:			1960844919@qq.com
 *编程语言:			C++
*/

#include<windows.h>
#include <string>
#include<iostream>
#include" JGame.h"
using namespace std;

void JGAME::play()
{
	int res = Draw;	//表示最终结果,初始值为平局

	while(true)
	{
		//给出3*3的格子
		drawGrid();

		while(true)
		{
			if(p)
			{
				getHumanMove();
			}
			else
			{
				getComputerMove();
			}

			//根据上一步走的棋子,然后重新画棋盘
			res = checkVictory();

			if(res != None)		//若可以判输赢,就值接跳出循环
			{
				break;
			}
			//计数器加1,进行玩家转换
			++p%=2;
		}

		//这里能够跳出来  就说明已经有人胜出了
		if(res  == Human)
		{
			cout << " Human is Win !!!";
		}
		else if(res == Computer)
		{
			cout << "Computer is win !!!";
		}
		else
		{
			cout << "it is a draw !!!";
		}
		cout <<endl<<endl;

		string input;
		cout<<"Play again ? ( Y || N)";
		cin>>input;
		
		if(input != 'Y' && input != 'N')
		{
			return;
		}

		//计数器加1,重新开局
		++p%=2;
		reset();
	}
}


void JGAME::reset()
{

	for(int x = 0; x < 9; x++)
	{
		filed[x] = None;
	}
}

void JGAME::drawGrid()
{
	//清屏幕
	system("cls");

	//定义控制台光标位置
	SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE), c);

	//棋局初始化的状态
	cout << " 1 | 2 | 3 "<<endl;
	cout << "---+---+---"<<endl;
	cout << " 4 | 5 | 6 "<<endl;
	cout << "---+---+---"<<endl;
	cout << " 7 | 8 | 9 "<<endl<<endl<<endl;

	//棋子计数器
	int f = 0;
	for(int y = 0; y < 5; y += 2 )
	{
		for(int x =1; x < 11; x += 4)
		{
			if(filed[f] != None)
			{
				//光标位置坐标
				COORD_c ={x, 2 + y };
				
				//设置控制台光标位置
				SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE), c);
				
				//判断当前是人还是电脑,如是电脑 就输出X,如果是人 就输出哦;
				string o = filed[f] == Computer ? "X" : "O";
				cout<<o;
			}
			f++;
		}
		c.Y = 9;

		//设置控制台管标位置
		SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE), c);
	}
}


int JGAME::checkVictory()
{
	//如果某一行或者某一列第对角,那么就表示已经赢了
	for(int i = 0; i < 8; i++)
	{
		if(filed[iWin[i][0]] != None &&
				filed[iWin[i][0]] == filrd[iWin[i][1]]&&
				filed[iWin[i][1]] == filrd[iWin[i][2]]
				)
		{
			//赢的状态是人还是电脑取决与diled[]i[0]的值
			return filed[i][0];
		}
	}

	//i表示棋子的个数
	for(int f = 0; f < 9 ; f++)
	{
		//如果当前格子有棋子,i+=1;
		if(filed[f] != None)
		{
			i++;
		}
	}

	//如果已经有9个格子有棋子,那么 就是一个平局状态
	if(i == 9)
	{
		return Draw;
	}

	return None;
}

void JGAME::getHumanMove()
{
	int m;
	cout<<"Enter your move number (1-9) ";

	while(true)
	{
		m=0;
		
		//输入想要下的棋子的格子编号
		cin >> m;

		//如果第m个格子中已经有了棋子.就无法输入
		if(filed[m-1] != None)
		{
			cout << "Invilid Move! Try again!"<<endl;
		}
		else
		{
			//输入有效 
			break;
		}
	}
	filed[m-1] = Human;
}

void JGAME::getComputerMove()
{
	//定义一个电脑要下的棋子的编号
	int move =0;
	do{
		//随机获得一个值
		move = rand() % 9;
	}while(filed[move] != None);

	//对赢的状态进行枚举
	for(int i = 0;i <8; i++)
	{
		//这三个变量表示要赢的三个格子,如果try1,try2已经有了棋子,并且该棋子的玩家
		//是同一个,而且try3这个格子刚好没有棋子,
		int try1 = iWin[i][0],try2=iWin[i][1],try3=iWin[i][2];

		if(filed[try1] != None&&filed[try1] == filed[try2] && filed[try3] == None)
		{
			//电脑会将棋子下载到这个位置
			move = try3;

			//如果try1这个格子的棋子是电脑,那么电脑赢了 游戏结束
			if(filed[try1] == Computer])
			{
				break;
			}
		}

		if(filed[try1] != None&&filed[try1] == filed[try3] && filed[try2] == None)
		{
			//电脑会将棋子下载到这个位置
			move = try2;

			//如果try1这个格子的棋子是电脑,那么电脑赢了 游戏结束
			if(filed[try1] == Computer])
			{
				break;
			}
		}
		
		if(filed[try2] != None&&filed[try2] == filed[try3] && filed[try1] == None)
		{
			//电脑会将棋子下载到这个位置
			move = try1;

			//如果try1这个格子的棋子是电脑,那么电脑赢了 游戏结束
			if(filed[try2] == Computer])
			{
				break;
			}
		}
	}
	//将第move个格子标记为电脑下的棋子
	filed[move] = Computer;
}	















