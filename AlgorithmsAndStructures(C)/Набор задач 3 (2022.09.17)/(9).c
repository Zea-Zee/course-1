#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define N 26

int sorter(int* ar, int ln){
  for (int i = 1; i < ln; i++){
    int j = i;
    while(j > 0 && ar[j - 1] > ar[j]){
      int cache =  ar[j - 1];
      ar[j - 1] = ar[j];
      ar[j] = cache;
      j--;
    }
  }
  return 0;
}

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n;
  char cache;
  scanf("%d", &n);
  int arr[n];
  for(int i = 0; i < n; i++){
    scanf("%c", &cache);
    if(cache > 32) arr[i] = (int)cache;
    else i--;
  }

  for(int i = n - 1; i > 0; i--){
    int len = n - i;
    int rArr[len];
    for(int j = 0; j < len; j++) rArr[j] = arr[i + j];
    if(len > 1) sorter(rArr, len);
    for(int j = 0; j < len; j++){
      if(rArr[j] > arr[i - 1]){
        //printf("rr:%c ar:%c", rArr[j], arr[i - 1]);
        int tmp = arr[i - 1];
        arr[i - 1] = rArr[j];
        rArr[j] = tmp;
        //printf("rr:%c ar:%c\n", rArr[j], arr[i - 1]);

        sorter(rArr, len);
        for(int k = 0; k < n; k++){
          if(k < i) printf("%c ", arr[k]);
          else printf("%c ", rArr[k - i]);
        }
        return 0; 
      }
    }
  }

  return 0;
}