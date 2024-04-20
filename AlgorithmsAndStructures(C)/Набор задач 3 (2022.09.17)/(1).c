#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, arr[100], count = 0;
  scanf("%d", &n);

  for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
  for(int i = 0; i < n; i++){
    count = 0;
    for(int j = i + 1; j < n; j++){
      if(arr[j] < arr[i]) count++;
    } 
    printf("%d ", count);
  }

	return 0;
}