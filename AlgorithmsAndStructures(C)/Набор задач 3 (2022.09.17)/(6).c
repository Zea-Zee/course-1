#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define N 100001

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

int main(void) {
  freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

  int n, arr[N] = {0}, c = 0, cache, n2;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &cache);
    if(arr[cache] == 0){
      arr[cache] = 1;
      c++;
    }
  }
  scanf("%d", &n2);
  for(int i = 0; i < n2; i++){
    scanf("%d", &cache);
    if(arr[cache] == 1){
      arr[cache] = 0;
      c--;
    }
  }
  printf("%d\n", c);
  for(int i = 0; i < N; i++){
    if(arr[i] == 1) printf("%d ", i);
  }

  fclose(stdin);
  fclose(stdout);
  return 0;
}