#include <stdio.h>
#include <stdlib.h>

int N, W;

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

void makeAns(int k, int s, VectorInt *way, int **table, int *weights){
    if(table[k][s] == 0) return;
    if(table[k - 1][s] == table[k][s]) makeAns(k - 1, s, way, table, weights);
    else{
        makeAns(k - 1, s - weights[k - 1], way, table, weights);
        addToVectorInt(k, way);
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d", &N, &W);
    int *costs = (int*) calloc(N, sizeof(int));
    int *weights =  (int*) calloc(N, sizeof(int));
    int **table = (int**) calloc(N + 1, sizeof(int*));
    for(int i = 0; i < N; i++){
        table[i] = (int*) calloc(W + 1, sizeof(int));
        scanf("%d %d", &weights[i], &costs[i]);
    }
    table[N] = (int*) calloc(W + 1, sizeof(int));

    int sumWeight = 0;
    int sumCost = 0;

    for(int i = 0; i <= W; i++) table[0][i] = 0;
    for(int i = 1; i <= N; i++) table[i][0] = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= W; j++){
            if(weights[i - 1] <= j) {
                int a = table[i - 1][j];
                int b = table[i - 1][j - weights[i - 1]] + costs[i - 1];
                table[i][j] = a >= b ? a : b;
            }
            else  table[i][j] = table[i - 1][j];
        }
    }

    int maxI = 0, maxJ = 0;
    for(int i = 0; i < N; i++)
        if(table[i + 1][W] > table[i][W])
            maxI = i + 1;
    for(int i = 0; i < W; i++) if(table[maxI][i + 1] > table[maxI][i]) maxJ = i + 1;
    sumCost = table[maxI][maxJ];
    sumWeight = maxJ;

    VectorInt *way = (VectorInt*) calloc(1, sizeof(VectorInt));
    makeAns(maxI, maxJ, way, table, weights);

    printf("%d %d %d\n", way->used, sumWeight, sumCost);
    for(int i = 0; i < way->used; i++) printf("%d ", way->val[i]);
    return 0;
}
