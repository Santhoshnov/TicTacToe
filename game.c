#include<stdio.h>

char board[3][3];

void createBoard()
{
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
          board[i][j]='0';
        }
    }
}

void printBoard()
{   
    createBoard();
    printf("\n-------------\n");
    for (int i = 1; i <= 3; i++) {
        printf("| ");
        for (int j = 1; j <= 3; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n-------------\n");
    }
}



int main()
{
    printBoard();
    
    return 0;
}