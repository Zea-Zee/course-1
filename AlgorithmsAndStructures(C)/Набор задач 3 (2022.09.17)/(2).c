#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, count;
  scanf("%d", &n);
  int arr[n];

  for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
  for(int i = 1; i <= n; i++){
    count = 0;
    for(int j = i - 1; j < n; j = j + i){
      count += arr[j];
    }
    printf("%d\n", count);
  }
  
	return 0;
}