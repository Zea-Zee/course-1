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
	int n, k, count = 0, i = -1;
	scanf("%d %d", &n, &k);
	int arr[n], flag = n;
	// memset(arr, 1, sizeof(int) * n);
	for(int i = 0; i < n; i++) arr[i] = 1;
	while(flag > 0){
		i++;
		if(i == n) i = 0;
		if(count == k - 1 && arr[i] == 1){
			printf("%d\n", i + 1);
			arr[i] = 0;
			count = 0;
			// i = -1;
			flag--;
			// continue;
		} else if(count == k - 1) continue;
		else if(arr[i] == 1){
			// printf("+%d\n", i + 1);
			count++;
		}
	}
	return 0;
}