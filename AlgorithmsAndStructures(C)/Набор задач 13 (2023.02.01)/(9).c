#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#define MaxL 20
#define MaxN 400
const int Dx[5] = {0, 0, 1, -1}, Dy[5] = {1, -1, 0, 0};

int n, Tot;
int A[MaxN][MaxN], Map[MaxL][MaxL], Ans[MaxL][MaxL];

void Get_Equation(int x, int y){
    int Id, Id2, xx, yy;
    Id = x * n + y + 1;           //get index
    for (int i = 1; i <= Tot; ++i) A[Id][i] = 0;
    A[Id][Tot + 1] = Map[x][y];
    A[Id][Id] = 1;
    for(int k = 0; k < 4; ++k){
        xx = x + Dx[k]; yy = y + Dy[k];
        if ((yy < 0 || yy >= n || xx < 0 || xx >= n)) continue;     //inside
        Id2 = xx * n + yy + 1;
        A[Id][Id2] = 1;
    }
}

void Gauss(){
    for (int i = 1; i <= Tot; ++i){
        int Tj = i;
        for (int j = i + 1; j <= Tot; ++j){
            if (!A[Tj][i] && A[j][i]){
                Tj = j;
                break;
            }
        }
        if (!A[Tj][i]) continue;
        if (Tj > i || Tj < i){               //swap
            for (int t = 0; t <= Tot; t++) {
                int tmp;
                tmp = A[i][t + 1];//A[Tj][t];
                A[i][t + 1] = A[Tj][t + 1];
                A[Tj][t + 1] = tmp;
            }
        }
        for (int j = i + 1; j <= Tot; ++j){
            if (!A[j][i]) continue;
            for (int k = i; k <= Tot + 1; ++k) A[j][k] = A[j][k] ^ A[i][k];//(int) pow((int) A[j][k], (int) A[i][k]);
        }
    }

    //posER
    for (int i = Tot; i >= 1; --i){
        int nx = (i - 1) / n;
        int ny = ((i % n - 1) + n) % n;
        Ans[nx][ny] = A[i][Tot + 1];
        for (int j = i - 1; j >= 1; --j) if (A[j][i]) A[j][Tot + 1] ^= A[i][Tot + 1];
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    Tot = n * n;
    char cache;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            scanf("%c", &cache);
            if (cache == '*') Map[i][j] = 1;
            else if (cache == '.') Map[i][j] = 0;
            else j--;
        }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            Get_Equation(i, j);
    Gauss();
    int counter = 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if(Ans[i][j]) counter++;
    printf("%d\n", counter);
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if(Ans[i][j]) printf("%d %d\n", i + 1, j + 1);
    return 0;
}