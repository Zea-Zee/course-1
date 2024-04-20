#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void) {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  scanf("%d", &n);
  int arr[n], count;

  for(int i = 0; i < n; i++){
    scanf("%d", &count);
    arr[i] = count;
  }
  
  for(int j = 0; j <= pow(10, 4); j++){
    count = 0;  
    for(int i = 0; i < n; i++){
      if(arr[i] == j) count++;
    }
    if(count > 0) printf("%d: %d\n", j, count);
  } 
}