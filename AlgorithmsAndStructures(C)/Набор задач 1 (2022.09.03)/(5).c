#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	FILE* input = fopen("input.txt", "r");
	FILE* output = fopen("output.txt", "w");

	//int n;
	//fscanf(input, "%d", &n);
	//if (n == 1) {
	//	fprintf(output, "NO");
	//	return 0;
	//}
	//for (int i = 2; i < n; i++) {
	//	if (n % i == 0) {
	//		fprintf(output, "NO");
	//		return 0;
	//	}
	//}
	//fprintf(output, "YES");

	double a, b;
	fscanf(input, "%lf %lf", &a, &b);
	int divMin = floor((double)a / b);
	int divMax = ceil((double)a / b);
	int divZero = (double)a / b;
	int divRem = (int)a % (int)b;
	if (divRem < 0) {
		divRem = b + divRem;
	}
	fprintf(output, "%d %d %d %d", divMin, divMax, divZero, divRem);
	return 0;
}





//FILE* input = fopen("input.txt", "r");
//FILE* output = fopen("output.txt", "w");

//int n, sum = 0;
//int cache;

//fscanf(input, "%d", &n);

//fprintf(output, "%d", sum);
//return 0;
//if (a <= 0 || b <= 0 || c <= 0) {
//	//printf("%d %d %d", a, b, c);
//	if(a <= 0){fprintf(output, "-1"); }
//	else if (b <= 0) { fprintf(output, "-2"); }
//	else if (c <= 0) { fprintf(output, "-3"); }
//	return 0; 
//}
//else {
//	s += 2 * a * b;
//	s += 2 * a * c;
//	s += 2 * b * c;
//	printf("%d", s);

/*for (int i = 0; i < n; i++){
	fscanf(input, "%d", &cache);
	if (cache % 2 == 0){
		sum = sum + cache;
	}
}*/