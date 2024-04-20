#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define MX 2 * 100000
#define DOHUYA 1000000000

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, count = 0;
	scanf("%d", &n);
	unsigned long long arr[n] = {0};
	for(int i = 0; i < n; i++){
		scanf("%llx", &arr[i]);
	}
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if((arr[i] & arr[j]) == 0) count++;
		}
	}
	printf("%d", count);
	return 0;
}