#include "game.h"
void menu()
{
	printf("***************** < ��ѡ�� > ******************\n");
	printf("**************** 1; ������Ϸ ******************\n");
	printf("**************** 0; �˳���Ϸ ******************\n");
}
void game()
{
	char board[ROW][COL];
	InitBoard(board, ROW, COL);//��ʼ������
	DisplayBoard(board, ROW, COL);
	char ret = 0;
	while (1)
	{
		Playermove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ����Ϸ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;

		
	}
	if (ret == '*')
	{
		printf("���Ӯ��\n");

	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");

	}
	else if (ret == 'Q')
	{
		printf("ƽ��\n");
	
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
			printf("ѡ��ɹ�\n");
			printf("��Ϸ��ʼ������\n");
			game();
			break;
		}
		case 0:
		{
			printf("��Ϸ���˳�\n");
			break;
		}
		default:
		{
			printf("ѡ�����������ѡ��\n");
			break;
		}
		}
	} while (input);
	return 0;
}