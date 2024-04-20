#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


int sorter(int arr[], int len){

  for(int i = 1; i < len; i++){
    int j = i - 1;
    while(arr[j + 1] < arr[j] && j >= 0){
      int cache = arr[j + 1];
      arr[j + 1] = arr[j];
      arr[j] = cache;
      j--;
    }
  }
  return 0;
}


int main(void) {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  scanf("%d", &n);
  int arr[n], cache;
  
  for(int i = 0; i < n; i++){
    scanf("%d", &cache);
    arr[i] = cache;
  }
  sorter(arr, n);
  for(int i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }
}