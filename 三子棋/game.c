#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)//ROW COL ��ֵ�÷ֱ���row col ����
{
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }
    }
}
//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < row; i++)
//	{
//		//printf("%d ", i);
//		for (j = 0; j < col; j++)
//		{
//			printf(" %c ", board[i][j]);
//				if (j < row - 1)
//				{
//					printf("|");
//				}
//		}printf("\n");
//		if (i < row - 1)
//		{
//			for (j = 0; j < col; j++)
//			{
//				printf("---");
//				if (j < col - 1)
//					printf("|");
//			}
//		}printf("\n");
//	}
//}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
    int i, j;
    //��ӡ�б�ǩ
    printf("    ");
    for (j = 0; j < col; j++)
    {
        
        printf(" %d  ", j + 1);
    }
    printf("\n");
    for (i = 0; i < row; i++)
    {
        // ��ӡ�б�ǩ
        printf(" %d  ", i + 1);
        
        for (j = 0; j < col; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < col - 1)
            {
                printf("|");
            }
        }
        printf("\n");

        if (i < row - 1)
        {
            printf("    ");
            for (j = 0; j < col; j++)
            {
                printf("---");
                if (j < col - 1)
                {
                    printf("|");
                }
            }
            printf("\n");
        }
    }
}

void Playermove(char board[ROW][COL], int row, int col)
{
    //int x = 0;
    //int y = 0;

    //printf("�����:>\n");

    //while (1)
    //{
    //    printf("���������������:>");
    //    scanf("%d %d", &x, &y);
    //    //�ж�����Ϸ���
    //    if (x >= 1 && x <= row && y >= 1 && y <= col)
    //    {
    //        //����
    //        //�����Ƿ�ռ��
    //        if (board[x - 1][y - 1] == ' ')
    //        {
    //            board[x - 1][y - 1] = '*';
    //            break;
    //        }
    //        else
    //        {
    //            printf("���걻ռ��, ����������\n");
    //        }
    //    }
    //    else
    //    {
    //        printf("����Ƿ�, ����������\n");
    //    }
    //}
    int x = 0;
    int y = 0;
    
    while (1)
    {
        printf("������壬������Ҫ�����ӵ�����>\n");
        scanf("%d %d", &x, &y);
        if (x >=1 && x <= row && y >= 1 && y <= col)
        {
            if (board[x - 1][y - 1] == ' ')
            {
                board[x - 1][y - 1] = '*';
                break;
            }
            else
               {
                  printf("���걻ռ��, ����������\n");
               }
        }
        else
        {
            printf("����Ƿ�����������\n");

        }
    }
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
    while (1)
    {
        int x = rand() % row;
        int y = rand() % col;

        //�ж�ռ��
        if (board[x][y] == ' ')
        {
            board[x][y] = '#';
            break;
        }
    }
}



int Isfull(char board[ROW][COL], int row, int col)//���ص������Σ�������int
{
    int x = 0;
    int y = 0;
    for (x = 0; x < row; x++)
    {
        for (y = 0; y < col; y++)
        {
            if (board[x][y] == ' ')
                return 0;

        }
    }
    return 1;
}





char IsWin(char board[ROW][COL], int row, int col)
{
    int i = 0;

    //�ж���
    for (i = 0; i < row; i++)
    {
        if (board[i][0] == board[i][1] && board[i][2] == board[i][1] && board[i][1] != ' ')
            return board[i][1];
    }
    for (i = 0; i < col; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
            return board[1][i];
    }

    //�ж϶Խ���
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
        return board[1][1];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
        return board[1][1];
    

    int isFull = Isfull(board, ROW, COL);
    if (isFull == 1)
        return 'Q';
    return 'C';
}