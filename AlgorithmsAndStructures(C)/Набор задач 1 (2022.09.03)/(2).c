#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	FILE* input = fopen("input.txt", "r");
	FILE* output = fopen("output.txt", "w");

	int a, b, c, s = 0;

	fscanf(input, "%d %d %d", &a, &b, &c);
	if (a <= 0 || b <= 0 || c <= 0) {
		//printf("%d %d %d", a, b, c);
		if(a <= 0){fprintf(output, "-1"); }
		else if (b <= 0) { fprintf(output, "-2"); }
		else if (c <= 0) { fprintf(output, "-3"); }
		return 0;
	}
	else {
		s += 2 * a * b;
		s += 2 * a * c;
		s += 2 * b * c;
		printf("%d", s);
		fprintf(output, "%d", s);
		return 0;

	}
}