//
// Created by kuzga on 23.02.2023.
//
#include <stdio.h>
#include "modular.h"

long long gcd(long long a, long long b) {return (b == 0 ? a : gcd(b, a%b)); }
long long invG;

long long gcdE (long long a, long long b, long long *x, long long *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    long long x1, y1;
    long long d = gcdE (b%a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    // invG = x;
    return d;
}

long long inv(long long a){
//    long long x;// = -1 * a;
//    long long y;
//    long long answ = gcdE(a, m, &x, &y);
//    return x;
    a %= MOD;
    if(a < 0) a += MOD;
    return a % MOD;
}

long long invR(long long a){
    long long x = inv(-1 * a + 1);
    long long y;
    long long answ = gcdE(a, MOD, &x, &y);
//    printf("%d", x);
    return x;
//    if(a < 0) a += MOD;
//    return a % MOD;
}

int MOD; // Определили глобальную переменную.
int pnorm(int a){
    return inv(a);
}

int padd(int a, int b){
    return inv(inv(a) + inv(b));
}

int psub(int a, int b){
    return inv(inv(a) - inv(b));
}

int pmul(int a, int b){
    return (int) inv((long long)inv(a) * (long long)inv(b));
}

int pdiv(int a, int b){
    long long B = invR(b);
    long long x = (int) inv((long long) inv(a) * B);
//            printf("%d", x);
    return x;
} 