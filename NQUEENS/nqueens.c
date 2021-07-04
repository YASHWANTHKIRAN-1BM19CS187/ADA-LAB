#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int n;

bool isSafe(int board[n][n], int row, int col)
{
    for(int i = 0; i < n; i++)
        if(board[row][i])
            return false;
    
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if(board[i][j])
            return false;

    for (int i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;
  
    return true;
}

bool solve(int board[n][n], int col)
{
    if(col >= n)
        return true;
    
    for(int i = 0; i < n; i++)
    {
        if(isSafe(board, i, col))
        {
            board[i][col] = 1;
            if(solve(board, col+1))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}

int main()
{
    freopen("output.txt", "w", stdout);
    n = 8;
    int board[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            board[i][j] = 0;
    }
    if (solve(board, 0) == false) {
        printf("Solution does not exist");
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                printf("%d ", board[i][j]);
            printf("\n");
        }
    }
    return 0;
}