#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)//ROW COL 的值用分别用row col 接收
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
    //打印列标签
    printf("    ");
    for (j = 0; j < col; j++)
    {
        
        printf(" %d  ", j + 1);
    }
    printf("\n");
    for (i = 0; i < row; i++)
    {
        // 打印行标签
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

    //printf("玩家走:>\n");

    //while (1)
    //{
    //    printf("请输入下棋的坐标:>");
    //    scanf("%d %d", &x, &y);
    //    //判断坐标合法性
    //    if (x >= 1 && x <= row && y >= 1 && y <= col)
    //    {
    //        //下棋
    //        //坐标是否被占用
    //        if (board[x - 1][y - 1] == ' ')
    //        {
    //            board[x - 1][y - 1] = '*';
    //            break;
    //        }
    //        else
    //        {
    //            printf("坐标被占用, 请重新输入\n");
    //        }
    //    }
    //    else
    //    {
    //        printf("坐标非法, 请重新输入\n");
    //    }
    //}
    int x = 0;
    int y = 0;
    
    while (1)
    {
        printf("玩家下棋，请输入要下棋子的坐标>\n");
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
                  printf("坐标被占用, 请重新输入\n");
               }
        }
        else
        {
            printf("坐标非法请重新输入\n");

        }
    }
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
    while (1)
    {
        int x = rand() % row;
        int y = rand() % col;

        //判断占用
        if (board[x][y] == ' ')
        {
            board[x][y] = '#';
            break;
        }
    }
}



int Isfull(char board[ROW][COL], int row, int col)//返回的是整形，所以用int
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

    //判断行
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

    //判断对角线
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
        return board[1][1];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
        return board[1][1];
    

    int isFull = Isfull(board, ROW, COL);
    if (isFull == 1)
        return 'Q';
    return 'C';
}