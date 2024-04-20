#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAXN 10000

int compare(const void * x1, const void * x2){
  return ( *(int*)x1 - *(int*)x2 );              // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}

int main(){
	FILE* input = fopen("input.txt", "r");
	FILE* output = fopen("output.txt", "w");
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++) scanf("%d", &(arr[i]));
	qsort(arr, n, sizeof(int), compare);
	long long sum = 0;
	for(int i = 0; i < n - 1; i++){
		sum += (long long) arr[i] * (n - i - 1);
	}
	printf("%lld", sum);
	return 0;
}