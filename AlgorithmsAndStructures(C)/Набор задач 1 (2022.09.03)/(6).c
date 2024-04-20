#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	FILE* input = fopen("input.txt", "r");
	FILE* output = fopen("output.txt", "w");


	int n, cn;
	fscanf(input, "%d", &n);

	int minNum = 100000, maxNum = -100000, minI, maxI;

	for (int i = 1; i <= n; i++) {
		fscanf(input, "%d", &cn);
		if (cn > maxNum) {
			maxNum = cn;
			maxI = i;
		}
		if (cn < minNum) {
			minNum = cn;
			minI = i;
		}
	}
	fprintf(output, "%d %d %d %d", minNum, minI, maxNum, maxI);
	return 0;

}