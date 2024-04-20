#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

long long gcd(long long a, long long b) {return (b == 0 ? a : gcd(b, a%b)); }

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		long long a, b;
		scanf("%lld", &a);
		scanf("%lld", &b);
		printf("%lld\n", gcd(a, b));
	}
	return 0;
}