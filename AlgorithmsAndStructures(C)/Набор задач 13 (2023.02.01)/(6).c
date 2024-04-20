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

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int c, x, y, n, k;
    unsigned int facs[N];
    scanf("%d", &c);
    facs[0] = 1;
    facs[1] = facs [0];
    for(int i = 2; i < N; i++){
        facs[i] = ((unsigned long long) facs[--i] * ++i) % M;
    }
    for(int i = 0; i < c; i++){
        scanf("%d %d", &n, &k);
        gcdE(facs[k], M, &x, &y);
        int res = (long long) facs[n] * x % M;
        gcdE(facs[n - k], M, &x, &y);
        res = (long long) res * x % M;
        if(res < 0){printf("%d\n", res + M);}
        else{printf("%d\n", res);}
    }
    return 0;
}