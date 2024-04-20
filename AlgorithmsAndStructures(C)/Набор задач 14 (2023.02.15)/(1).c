#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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

long long inv(long long a, long long m){
    long long x;// = -1 * a;
    long long y;
	long long answ = gcdE(a, m, &x, &y);
	// if(x == 0) x = -1;
    // if(x <= 0) x += m;
	return x;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	// printf("%d", inv(100, 11));
	long long k, p = 1;
    // int m;
    long long res = 0;
    scanf("%lld", &k);
    long long *ms = (long long) malloc(sizeof(long long) * (k + 5));
    long long *as = (long long) malloc(sizeof(long long) * (k + 5));
    for(long long i = 0; i < k; i++) {
        scanf("%lld", &(ms[i]));
        p = p * (long long) ms[i];    
    }
    for(long long i = 0; i < k; i++) {scanf("%lld", &(as[i]));}
    for(long long i = 0; i < k; i++) {
        // int tstm = ms[i];
        // int tsta = as[i];
        long long M = p / ms[i];
        long long y = inv(M, ms[i]);
        long long cache = ((as[i] * y) % ms[i] * M);
        /*if(res + cache != 0) */res = (res % p + cache % p) % p;
        if(res < 0) res += p;
        // else res = (res + cache);
    }
    // printf("%d");
    printf("%lld", res);
	return 0;
}