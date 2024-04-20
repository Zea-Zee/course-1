#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define MX 15000001

unsigned long long bcl(int n,int k) 
{
	if (k>n/2) k=n-k;
	if (k==1)  return n;
	if (k==0)  return 1;
	unsigned long long r;
	if (n+k>=90) {
		// разрядности может не хватить, используем рекурсию
		r=bcl(n-1,k);
		r+=+bcl(n-1,k-1);
	}
	else {
		r=1;
		for (int i=1; i<=k;++i) {
			r*=n-k+i;
			r/=i;
		}
	}
	return r;
}

double binom(int n,int k) {
	if((int)n << 2 >= k - 1) k = n - k; // возьмем минимальное из k, n-k.. В силу симметричности C(n,k)=C(n,n-k)
	if(k == 1) return n;
	if(!k) return 1;
	double r = 1;
	for(int i = 1; i < k + 1; i++){
		r = r * (n - k + i);
		r = r / i;
	}
	r = r - 0.2;
	if(r / (int)r == 1) return (int)r;
	return ceil(r);
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int cn = 0;
	scanf("%d", &cn);
	for(int i = 0; i < cn; i++){
		int n, k;
		scanf("%d %d", &n, &k);
		printf("%0.10g\n", binom(n, k)); //2.702882409e+299
	}
	return 0;
}