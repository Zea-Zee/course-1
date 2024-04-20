#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	FILE* input = fopen("input.txt", "r");
	FILE* output = fopen("output.txt", "w");


	int h, m, s, k;

	fscanf(input, "%d %d %d %d", &h, &m, &s, &k);

	//while (k > 0) {
	//	while (m < 60 && k > 0) {
	//		int t = (60 - s);
	//		if (k >= t) {
	//			s = 0;
	//			k = k - t;
	//			m++;
	//		}
	//		if(k < (60 - s) & k > 0) {
	//			s = s + k;
	//			k = 0;
	//		}
	//	}
	//	if (k > 0) {
	//		h++;
	//	}
	//}
//
//while(k > 0){
//	if (k > (60 - s)) {
//		s = 0;
//		k = k - (60 - s);
//		m++;
//		if (k > (60 - m) * 60) {
//			m = 0;
//			k = k - (60 - m) * 60;
//			if (k > (60 - h) * 60 * 60) {
//				h = 0;
//				k = k - (60 - h) * 60 * 60;
//			}
//		}
//	}
//	else {
//		s += k;
//		k = 0;
//	}
//}


	int s2 = 0;

	s2 += h * 3600;
	s2 += m * 60;
	s2 += s;

	k = k + s2;
	k = k % (24 * 3600);


	h = (int)k / 3600;
	k = k % 3600;
	m = (int)k / 60;
	s = k % 60;


	fprintf(output, "%d %d %d", h, m, s);
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

//double a, b;
//fscanf(input, "%lf %lf", &a, &b);
//int divMin = floor((double)a / b);
//int divMax = ceil((double)a / b);
//int divZero = (double)a / b;
//int divRem = (int)a % (int)b;
//if (divRem < 0) {
//	divRem = b + divRem;
//}
//fprintf(output, "%d %d %d %d", divMin, divMax, divZero, divRem);
//return 0;

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


	//int n, cn;
	//fscanf(input, "%d", &n);

	//int minNum = 100000, maxNum = -100000, minI, maxI;

	//for (int i = 1; i <= n; i++) {
	//	fscanf(input, "%d", &cn);
	//	if (cn > maxNum) {
	//		maxNum = cn;
	//		maxI = i;
	//	}
	//	if (cn < minNum) {
	//		minNum = cn;
	//		minI = i;
	//	}
	//}
	//fprintf(output, "%d %d %d %d", minNum, minI, maxNum, maxI);
	//return 0;