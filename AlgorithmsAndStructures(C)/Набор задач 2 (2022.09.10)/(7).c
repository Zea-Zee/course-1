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
	time_t t0 = time(0);
	FILE* input = fopen("input.txt", "r");
	FILE* output = fopen("output.txt", "w");


	int start, finish, n, count = 0;
	fscanf(input, "%d %d %d", &start, &finish, &n);

	//for (int i = start; i < finish; i++) {
	//	for (int step = 1; step <= (finish - i) / (n - 1); step++) {
	//		//fprintf(output, "%d %d %d\n", i, i + step, i + 2 * step);
	//		if (n * step + i <= finish && (n + 1) * step + i > finish) count++;
	//	}
	//}


	for (int i = 1; i < finish - start + 1; i++) {
		for (int j = start; j < finish; j++) 
			if ((j + i * (n - 1) <= finish) && (j + i * n > finish)) count++;
	}


	time_t t1 = time(0);
	fprintf(output, "%d", count);
	//fprintf(output, "\nSeconds: %d\n", t1 - t0);

	return 0;
}