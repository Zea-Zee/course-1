#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define MX 100000

void reverse (char * start, int len){
  for(int i = 0; i < (int)len / 2; i++){
    char tmp = start[i];
    start[i] = start[len - i - 1];
    start[len - i - 1] = tmp;
  }
}

int main(void) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
  int n;
  char str[100], cache = 'y';
  scanf("%d", &n);
  scanf("%c", &cache);
  for(int i = 0; i < n; i++){
    int l = 0;
    scanf("%c", &cache);
    while(cache != '\n'){
      str[l] = cache;
      l++;
      //printf("%d ", n);
      scanf("%c", &cache);
    }
    reverse(str, l);
    for(int j = 0; j < l; j++) printf("%c", str[j]);
    printf("\n");
  }

  return 0;
}