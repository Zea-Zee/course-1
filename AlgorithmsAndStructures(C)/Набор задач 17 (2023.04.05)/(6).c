#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, e, p, k;
    scanf("%d %d %d %d\n", &n, &e, &p, &k);
    long long adjM[n+1][n+1];
//    memset(adjM, (long long) INT_MAX, (n+1)*(n+1)*sizeof(long long));
    long long ancM[n+1][n+1];
//    memset(ancM, (long long) INT_MAX, (n+1)*(n+1)*sizeof(long long));
//    for(int k = 1; k <= n; k++){
//        for(int i = 1; i <= n; i++){
//            if(i == k) adjM[k][i] = 0;
//            else adjM[k][i] = INT_MAX;
//            ancM[k][i] = 0;
//        }
//    }
//
////    for(int i = 0; i < e; i++){
////        int r, c;
////        scanf("%d %d", &r, &c);
////        scanf("%lld", &adjM[r][c]);
////        adjM[c][r] = adjM[r][c];
////    }
//    for(int k = 1; k <= n; k++){
//        for(int i = 1; i <= n; i++){
//            if(adjM[k][i] == INT_MAX || k == i) ancM[k][i] = 0;
//            else ancM[k][i] = k;
//        }
//    }


    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) {
            adjM[i][j] = INT_MAX;
            ancM[i][j]=j;
        }
    }

    for (int i=0;i<e;i++) {
        int r, c;
        long long d;
        scanf("%d %d %lld", &r,&c, &d);
        if (adjM[r][c]>d) {
            adjM[r][c] = d;
            adjM[c][r] = d;
        }
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                long long a = adjM[i][j];
                long long b = adjM[i][k] + adjM[k][j];
                if(a <= b) adjM[i][j] = a;
                else{
                    adjM[i][j] = b;
//                    ancM[i][j] = ancM[k][j];
                    ancM[i][j] = ancM[i][k];
                }
            }
        }
    }

    for(int i = 0; i < k + p; i++){
        int from, to;
        scanf("%d %d", &from, &to);

        printf("%d ", adjM[from][to]);
        if(i < p){
            VectorInt *vector = (VectorInt*) calloc(1, sizeof(VectorInt));
            int num = 2;
            int anc = ancM[from][to];
            char flag = 0;
            while(anc != 0 && anc != to){
                addToVectorInt(anc, vector);
                num++;
//                if(anc == ancM[anc][to]) break;
                anc = ancM[anc][to];
            }
            printf("%d %d ", num, from);
            for(int i = 0; i < vector->used; i++) printf("%d ", vector->val[i]);
            printf("%d\n", to);
        }else printf("\n");
    }

    return 0;
}