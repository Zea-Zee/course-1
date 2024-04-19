#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define M 1000000007;

int N;
long long M = 1000000007;
long long answ;

typedef struct VectorInt{
    int *val;
    int used;
    int len;
} VectorInt;

void addToVectorInt(int el, VectorInt *vector){
    if(vector->used == vector->len){
        vector->val = (int*) realloc(vector->val, (vector->len + 10) * sizeof(int));
        vector->len += 10;
    }
    vector->val[vector->used] = el;
    vector->used++;
}


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N);
    long long answer[N+1][N+1];
    memset(answer, 0, (N+1)*(N+1)* sizeof(long long));
    for(int i = 0; i <= N; i++) answer[0][i] = 1;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(j > i){
                answer[i][j] = answer[i][i];
                continue;
            }
            answer[i][j] = answer[i][j - 1] % M + answer[i - j][j] % M;
        }
    }
    answ = 0;
    printf("%lld", answer[N][N]);
    return 0;
}
