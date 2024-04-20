#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 1000001
#define M 1000000007

long long gcd(long long a, long long b) {return (b == 0 ? a : gcd(b, a%b)); }

int gcdE (int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int d = gcdE (b%a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return d;
}

unsigned int ** fillPascalTriangle(int height, long long m){
    unsigned int **pasc = malloc(height * sizeof(int*));
    for(int i = 0; i < height; i++){
        pasc[i] = malloc((i + 2) * sizeof(int));
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i) {pasc[i][j] = 1;}
            else{
                pasc[i][j] = pasc[i - 1][j - 1] + pasc[i - 1][j];
                pasc[i][j] %= m;
            }
        }
    }
    return pasc;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long m;
    int c, n, k;
    scanf("%lld %d", &m, &c);
    unsigned int **pasc = fillPascalTriangle(2001, m);
    for(int i = 0; i < c; i++){
        scanf("%d %d", &n, &k);
        char a = 0;
        if((k < 0) + (k > n) > 0){printf("%d\n", a);}
        else{
            if(k * 2 > n){k = n - k;}
            printf("%d\n", pasc[n][k]);
        }
    }
    return 0;
}