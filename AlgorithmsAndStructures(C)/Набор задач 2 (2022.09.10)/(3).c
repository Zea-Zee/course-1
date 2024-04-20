#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {
	FILE* input = fopen("input.txt", "r");
	FILE* output = fopen("output.txt", "w");

	int n, minus = 0, plus = 0, zero = 0, cache;
	fscanf(input, "%d", &n);

	for (int i = 0; i < n; i++) {
		fscanf(input, "%d", &cache);
		if (cache < 0) minus++;
		else if (cache == 0) zero++;
		else plus++;
	}
	fprintf(output, "%0.5lf %0.5lf %0.5lf", (double)minus / n, (double)zero / n, (double)plus / n);
}