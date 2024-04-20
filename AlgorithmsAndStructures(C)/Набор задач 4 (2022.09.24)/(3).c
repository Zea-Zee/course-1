#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define MX 100000

char * concat (char * pref, char * suff){
  // int len1 = strlen(pref), len2 = strlen(suff);
  // //printf("%d %d\n", len1, len2);
  // for(int i = len1; i < (len1 + len2) - 1; i++) pref[i] = suff[i - len1];
  memcpy(pref + strlen(pref), suff, strlen(suff) + 1);
  return pref;
}

int main(void) {
  //FILE * input = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
  int n, g = 0;
  char strFn[1000001], str[102], cache = 'y';
  scanf("%d\n", &n);
  for(int i = 0; i < n; i++){
    scanf("%s", str);
    concat(strFn, str);
    //for(int j = 0; j < strlen(strFn); j++) printf("%c", strFn[j]);
  }
  printf("%s", strFn);
  return 0;
}