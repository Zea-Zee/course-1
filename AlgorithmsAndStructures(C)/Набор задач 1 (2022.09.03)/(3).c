#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	FILE* input = fopen("input.txt", "r");
	FILE* output = fopen("output.txt", "w");

	int n, sum = 0;
	int cache;

	fscanf(input, "%d", &n);
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

	for (int i = 0; i < n; i++){
		fscanf(input, "%d", &cache);
		if (cache % 2 == 0){
			sum = sum + cache;
		}
	}
	fprintf(output, "%d", sum);
	return 0;

}