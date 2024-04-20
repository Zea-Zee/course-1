#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
	FILE* input = fopen("input.txt", "rb");
	FILE* output = fopen("output.txt", "wb");
	// freopen("output.txt", "w", stdout);
	int a[2];
	fread(a, sizeof(int), 2, input);
	// printf("%d %d\n", a[0], a[1]);
	a[0] = floor((double)((long long)a[0] + (long long)a[1]) / 2);	// int c = (int)b;
	// printf("%d %d %lld", a[0], a[1], b);
	fwrite(&(a[0]), sizeof(int), 1, output);
	return 0;
}