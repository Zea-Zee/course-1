#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma comment(linker, "/ STACK :50000000");
//int *strings;
int **ground;

void printBinArr(int **arr, int x, int y){
    for(int i = 0; i < y; i++){
        for (int j = 0; j < x; ++j){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void findDelete(int x, int y, int N){
    ground[y][x] = 0;
    int M = N;
    if(x == N - 1 && y == M - 1) ground[y][x] = 0;
    if(y == M - 1 && ground[y][x]) ground[y][x] = 0;
    if(x == N - 1 && ground[y][x]) ground[y][x] = 0;

    if(x > 0){
        if(ground[y][x-1]){
            findDelete(x - 1,y,N);
        }
    }
    if(x < N - 1){
        if(ground[y][x+1]){
            findDelete(x + 1,y,N);
        }
    }

    if(y > 0){
        if(ground[y-1][x]){
            findDelete(x,y-1,N);
        }
    }
    if(y < M - 1){
        if(ground[y+1][x]){
            findDelete(x,y+1,N);
        }
    }
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    char arr[n][n];
//    strings = (int*) calloc(n, 4);
//    ground = (int**) calloc(n, sizeof(int*));
    ground = (int**) malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++){
        ground[i] = (int*) malloc(n * sizeof(int));
        for(int j = 0; j < n; j++){
            char tmp;
            scanf("%c", &tmp);
            if(tmp == '*') ground[i][j] = 0;
            else if(tmp == ' ') ground[i][j] = 1;
            else j--;
        }
    }

    int islands = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(ground[i][j]){
//                printf("before\n");
//                printBinArr(ground, n, n);
                ground[i][j] = 0;
                findDelete(j, i, n);
//                printf("after\n");
//                printBinArr(ground, n, n);
                islands++;
            }
        }
    }
//    printf("\n\n____TOTAL ISLANDS IS: %d ____\n\n", islands);
//    printBinArr(ground, n, n);
    printf("%d", islands-1);
    return 0;
}