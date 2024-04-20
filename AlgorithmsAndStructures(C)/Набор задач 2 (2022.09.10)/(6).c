#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

long bin_to_dec(char* s)
{
	short i;
	long res = 0;

	for (i = 0; i < sizeof(long) * 8 && s[i]; ++i)
	{
		res <<= 1;
		res |= (s[i] - '0');
	}
	return res;
}

int main(void) {
	FILE* input = fopen("input.txt", "r");
	FILE* output = fopen("output.txt", "w");

	int n, num;
	fscanf(input, "%d", &n);
	int ost = n % 8;
	n = floor((double)n / 8);
	char c[100000];
	char cache;
	fscanf(input, "%c", &cache);
	cache = '0';
	
	for (int i = 0; i < n; i++) {
		num = 0;
		for (int j = 0; j < 8; j++) {
			fscanf(input, "%c", &cache);
			int g = cache - '0';
			if(g) num += pow(2, j);
			/*fprintf(output, "%d %d\n", g,  num);*/
		}
		fprintf(output, "%d ", num);
	}

	if (ost > 0) {
		num = 0;
		for (int j = 0; j < ost; j++) {
			fscanf(input, "%c", &cache);
			int g = cache - '0';
			if (g) num += pow(2, j);
			//fprintf(output, "%d %d\n", g, num);
		}
		fprintf(output, "%d", num);
	}



	
	return 0;
}
