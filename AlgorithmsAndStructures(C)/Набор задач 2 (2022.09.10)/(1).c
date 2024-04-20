#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int main() {
	FILE* input = fopen("input.txt", "r");
	FILE* output = fopen("output.txt", "w");

	int s;
	fscanf(input, "%d", &s);

	for (int i = 2; i <= s; i++) {
		int n = i;
		int flag = 1;
		for (int j = 2; j < n; j++) {
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}
		if (flag) fprintf(output, "%d\n", i);
	}
}