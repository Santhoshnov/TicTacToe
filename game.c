#include<stdio.h>

char board[3][3];

void createBoard()
{
    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void printBoard()
{
    printf("\n-------------\n");
    for (int i = 1; i <= 3; i++) {
        printf("| ");
        for (int j = 1; j <= 3; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n-------------\n");
    }
}

int winCondition(char player)
{
    for(int i = 1; i <= 3; i++)
    {
        if(board[i][1] == player && board[i][2] == player && board[i][3] == player)
            return 1;
    }

    for(int i = 1; i <= 3; i++)
    {
        if(board[1][i] == player && board[2][i] == player && board[3][i] == player)
            return 1;
    }

    if((board[1][1] == player && board[2][2] == player && board[3][3] == player) ||
       (board[1][3] == player && board[2][2] == player && board[3][1] == player))
        return 1; //win

    return 0; //tie
}

void playGame()
{
    int row, col;
    char currentPlayer = 'X';
    int moves = 0;

    createBoard();

    while(1)
    {
        printf("\nPlayer %c enter row [1-3]: ", currentPlayer);
        scanf("%d", &row);
        printf("Player %c enter column [1-3]: ", currentPlayer);
        scanf("%d", &col);


        if(row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row][col] == ' ')
        {
            board[row][col] = currentPlayer;
            printBoard();
            moves++;

            if(winCondition(currentPlayer))
            {
                printf("\nPlayer %c wins! and total moves %d \n", currentPlayer,moves);
                break;
            }

            if(moves == 9)
            {
                printf("\nIt's a tie!\n");
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
        else
        {
            printf("\nInvalid move. Try again.\n");
        }
    }
}

int main()
{
    printf("TicTacToe\n");
    printf("Player 1: X\n");
    printf("Player 2: O\n");
    printf("-------------\n");

    playGame();

    return 0;
}
