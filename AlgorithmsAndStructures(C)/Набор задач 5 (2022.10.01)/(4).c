#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define MX 15000001

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//long long MX = 15000000;
	// long long arr[MX] = {0};
	int n = 0, cache = 0, rub;
	scanf("%d", &rub);
	scanf("%d", &n);
	clock_t st = clock();
	short * arr = (short*) calloc(MX, sizeof(short));
	arr[0] = 1;
	arr[1] = 1;
	for(long long i = 2; i < MX; i++) if(!arr[i]) for(long long j = i * i; j < MX; j += i) arr[j] = 1;
	for(int i = 0; i < n; i++){
		scanf("%d", &cache);
		if(!arr[cache]) printf("%d prime\n", cache);
		else printf("%d not\n", cache);
	}
	//for(long long i = 0; i < MX; i++) if(!arr[i]) printf("%lld ", i);
	//fclose(stdout);
	//printf("\ntime = %lf ms", (double)(clock() - st) / CLOCKS_PER_SEC * 1000);
	return 0;
}