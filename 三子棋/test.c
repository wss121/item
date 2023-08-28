#include "game.h"
void menu()
{
	printf("***************** < 请选择 > ******************\n");
	printf("**************** 1; 进入游戏 ******************\n");
	printf("**************** 0; 退出游戏 ******************\n");
}
void game()
{
	char board[ROW][COL];
	InitBoard(board, ROW, COL);//初始化棋盘
	DisplayBoard(board, ROW, COL);
	char ret = 0;
	while (1)
	{
		Playermove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑是否赢得游戏
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;

		
	}
	if (ret == '*')
	{
		printf("玩家赢了\n");

	}
	else if (ret == '#')
	{
		printf("电脑赢了\n");

	}
	else if (ret == 'Q')
	{
		printf("平局\n");
	
	}
}









int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			printf("选择成功\n");
			printf("游戏开始，加油\n");
			game();
			break;
		}
		case 0:
		{
			printf("游戏已退出\n");
			break;
		}
		default:
		{
			printf("选择错误，请重新选择\n");
			break;
		}
		}
	} while (input);
	return 0;
}