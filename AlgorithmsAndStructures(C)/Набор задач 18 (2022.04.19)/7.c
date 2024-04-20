#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *answ;
int **matrix;
int *bulbs;
int n, k, m, l, rows;

int findSolution(int curI, int curJ, int curT, int step, int *curBulbs)
{
    if (step == n)
    {
        char winFlag = 1;
        for (int i = 0; i < m; i++)
        {
            if (curBulbs[i] != l)
            {
                winFlag = 0;
                break;
            }
        }
        if (winFlag)
        {
            answ[step] = curJ;
            return 1;
        }
    }
    for (int i = step * k; step < n && i < step * k + k; i++)
    {
        int *newBulbs = (int *)calloc(m, 4);
        char launchFlag = 1;
        for (int j = 0; j < m; j++)
        {
            newBulbs[j] = curBulbs[j] + matrix[i][j];
            if (newBulbs[j] + n - step - l < 0)
                return 0;
            if (newBulbs[j] > l)
            {
                launchFlag = 0;
                break;
            }
        }
        if (launchFlag)
            if (findSolution((int)i / k / m, i - (step * k) /*(int)i / (step == 0 ? 1 : step) / m*/, -1, step + 1, newBulbs))
            {
                answ[step] = curJ;
                return 1; // may be we need to limit step
            }
        free(newBulbs); // DOESNT WORK
    }
    return 0;
}

void print2Arr()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
        if ((i + 1) % k == 0)
            printf("\n");
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d %d %d\n", &n, &k, &m, &l);
    rows = n * k;
    matrix = (int **)calloc(rows, sizeof(int *));
    bulbs = (int *)calloc(m, 4);
    answ = (int *)calloc(n + 1, 4);

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)calloc(m, 4);
        for (int j = 0; j < m; j++)
        {
            char cache;
            scanf("%c", &cache);
            if (cache != 'X' && cache != '.')
                j--;
            else if (cache == 'X')
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
        scanf("\n");
    }
    if (findSolution(-1, -1, -1, 0, bulbs))
    {
        printf("YES\n");
        for (int i = 1; i <= n; i++)
            printf("%d\n", answ[i] + 1);
    }
    else
        printf("NO");
    return 0;
}
