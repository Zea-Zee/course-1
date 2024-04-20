#include <stdio.h>
#include <stdlib.h>

void printBinArr(int rows, int columns, char board[rows][columns])
{
    printf("YES\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (board[i][j] == 'X')
                printf("X");
            else
                printf(".");
        }
        printf("\n");
    }
    exit(0);
}

void makeSol(int row, int sizeX, int sizeY, char board[sizeY][sizeX], int verticals[], int mainD[], int antiD[])
{
    if (row == sizeY)
    {
        printBinArr(sizeY, sizeX, board);
    }
    int maxSize = sizeX >= sizeY ? sizeX : sizeY;
    int minSize = sizeX < sizeY ? sizeX : sizeY;
    for (int c = 0; c < sizeX; c++)
    {
        if (board[row][c] != '?')
            continue;
        int maxCur = c >= row ? c : row;
        int minCur = c < row ? c : row;
        if (verticals[c] || mainD[row + c] || antiD[maxSize + c - row])
            continue;

        board[row][c] = 'X';
        verticals[c] = 1;
        mainD[c + row] = 1;
        antiD[maxSize + c - row] = 1;

        makeSol(row + 1, sizeX, sizeY, board, verticals, mainD, antiD);

        board[row][c] = '?';
        verticals[c] = 0;
        mainD[c + row] = 0;
        antiD[maxSize + c - row] = 0;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int rows, columns;
    scanf("%d %d\n", &rows, &columns);
    char board[rows][columns], trash;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            scanf("%c", &board[i][j]);
        scanf("\n", &trash);
    }

    int *mainD = calloc(rows + columns - 1, sizeof(int));
    int *antiD = calloc((rows >= columns ? rows : columns) + columns - 1, sizeof(int));
    int *verticals = calloc(columns, sizeof(int));

    makeSol(0, columns, rows, board, verticals, mainD, antiD);
    printf("NO");
    return 0;
}
