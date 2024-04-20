// #include <stdlib.h>
// #include <stdio.h>
// #include <math.h>
// #include <string.h>
// #include <time.h>
// #define MX 2 * 100000
// #define DOHUYA 1000000000

// int main(){
// 	freopen("input.txt", "r", stdin);
// 	//freopen("output.txt", "w", stdout);
// 	int n, count = 0;
// 	scanf("%d", &n);
// 	for(int i = 0; i < n - 1; i++){
// 		double a, b;
// 		unsigned long long xo;
// 		char cache;
// 		scanf("%d/%d xor %llx", &a, &b, &xo);
// 		unsigned long long *xorer = (unsigned long long*) xo;
// 		double d = (double)a / b;
// 		unsigned long long* uPtr = (unsigned long long*)&d;
// 		unsigned long long uXor = (*uPtr) ^ (xorer);
// 		double dXor = *((double*)&uXor);
// 		printf("%0.15g\n", dXor);
// 	}
// 	return 0;
// }
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define MX 2 * 100000
#define DOHUYA 1000000000

int main(){
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, count = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		// int a, b;
		// unsigned long long xorer;
		// char cache;
		// scanf("%d", &a);
		// scanf("%c", &cache);
		// scanf("%d", &b);
		// scanf("%c%c%c%c%c", &cache, &cache, &cache, &cache, &cache);
		// scanf("%x", &xorer);
		// double d = (double)a / b;
		// unsigned long long *xo = (unsigned long long*) &d;
		// // unsigned long long c = *xo;
		// printf("%lf/%lf=%lf xorer:%lld answ:%0.15g\n", a, b, d, xorer, xorer ^ *xo);
		int a, b;
		unsigned long long c;
		// double * x = (double*)malloc(sizeof(double));
		scanf("%d/%d xor %llx\n", &a, &b, &c);
		// *x = (double )t /s;
		double quot = (double)a / b;
		double *quotPointer = &quot;
		unsigned long long *quotLong = (unsigned long long*)quotPointer;
		*((unsigned long long*)quotPointer) ^= c;
		printf("%0.15g\n", *quotPointer);
	}
	return 0;
}