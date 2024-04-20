#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 0, n = 0;
	FILE* input = fopen("input.txt", "r");
	FILE* output = fopen("output.txt", "w");
	fscanf(input, "%d", &a);
	for (int i = 0; i <= a; i++){
		n += i;
		n = n;
	};
	fprintf(output, "%d", n);
	return 0;
}
