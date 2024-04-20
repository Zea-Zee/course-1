#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define N 26

// int sorter(int* ar, int ln){
//   for (int i = 1; i < ln; i++){
//     int j = i;
//     while(j > 0 && ar[j - 1] > ar[j]){
//       int cache =  ar[j - 1];
//       ar[j - 1] = ar[j];
//       ar[j] = cache;
//       j--;
//     }
//   }
//   return 0;
// }

int printTime ( int h , int m , int s ){
  printf("%0.2d:%0.2d:%0.2d\n", h, m, s);
  return 0;
}
int main(void) {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  //printf("12:37:59\n01:01:01\n23:59:59");
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    int h, m, s;
    scanf("%d %d %d", &h, &m, &s);
    printTime(h, m , s);
  }
  return 0;
}