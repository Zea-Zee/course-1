#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


int sorter(int (*arr)[2], int len){
  for (int i = 1; i < len; i++){
    int j = i;
    while(j > 0 && arr[j - 1][0] > arr[j][0]){
      int cache =  arr[j - 1][0];
      arr[j - 1][0]  = arr[j][0];
      arr[j][0] = cache;
      j--;
    }
  }
  return 0;
}

int main(void) {
  freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

  int n, cache;
  scanf("%d", &n);
  int arr[n];
  for(int i = 0; i < n; i++){
    scanf("%d", &cache);
    arr[i] = cache;
  }

  int maxSum = -1 * pow(2, 31), maxSumSt = 0, maxSumFn = 0;

  for(int i = 0; i < n; i++){
    int curSum = 0;
    for(int j = i; j < n; j++){
      curSum += arr[j];
      if(curSum > maxSum){
        maxSum = curSum;
        maxSumSt = i;
        maxSumFn = j;
      }
    }
  }
  printf("%d %d %d", maxSumSt, maxSumFn, maxSum);
  return 0;
}





  // int arr[][2] = {{3, 0}, {2, 0}, {1, 0}};
  // sorter(arr, 3);
  // for(int i = 0; i < 3; i++){
  //   printf("%d ", arr[i][0]);
  // }

  // int n;
  // char empty;
  // scanf("%d", &n);
  // int arr[n][2];
  // for(int i = 0; i < n; i++){
  //   // printf("%c", 'e');
  //   char cache, l;
  //   for(int j = 0; j <= 11; j++){
  //     if(j < 2){
  //       scanf("%c", &cache);
  //       scanf("%c", &l);
  //       arr[i][0] = (((int)cache -'0') * 10 + ((int)l - '0')) * 60;
  //       j++;
  //       // printf("%d", atoi());
  //     } else if(j > 2 && j < 5){
  //       scanf("%d", &cache);
  //       scanf("%d", &l);
  //       arr[i][0] = ((int)cache -'0') * 10 + ((int)l - '0');
  //       j++; 
  //       printf("%d",cache);
  //     } else if(j > 5 && j < 8){
  //       scanf("%d", &cache);
  //       scanf("%d", &l);
  //       arr[i][1] = (((int)cache -'0') * 10 + ((int)l - '0')) * 60;
  //       j++;
  //     } else if(j > 8){
  //       scanf("%d", &cache);
  //       scanf("%d", &l);
  //       arr[i][1] = ((int)cache -'0') * 10 + ((int)l - '0');
  //       j++;
  //     }
  //   } 
  // }
  // for(int i = 0; i < n; i++){
  //   printf("\n%d", arr[i][0]);
  // }