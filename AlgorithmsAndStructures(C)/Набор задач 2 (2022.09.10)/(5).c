#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


int main(void) {
	FILE* input = fopen("input.txt", "r");
	FILE* output = fopen("output.txt", "w");


	int flag = 0, count = 0, i = -1;
	char c[101], cache = 'y';
	while (cache) {
		i++;
		fscanf(input, "%c", &cache);
		if (cache == ' ' || cache == '\n') break;
		if (cache == '.') flag = 0;
		if (flag == 0 && cache != '.') {
			count++;
			flag = 1;
			//fprintf(output, "%d", i);
		}
		i++;
	}
	fprintf(output, "%d", count);
	printf("%d", 1);
	
	return 0;
}
