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
  // ss = 123456789abcdefghijklmnopqrstuvwxyz
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int alphabet[123];
  for(int i = 0; i < 123; i++){                         //Fill alphabet
    if(i >= '0' && i <= '9') alphabet[i] = i - 48;      //Fill 0 - 9
    else if(i >= 10 && i < 97) alphabet[i] = 100000 + i;//Fill zero
    else alphabet[i] = i - 87;                          //Fill a - q
    //printf("%d ", alphabet[i]);
  }
  int p, q, i = 0;
  scanf("%d %d ", &p, &q);
  char num[30], cache;
  while(scanf("%c", &cache) == 1 && cache != '\n'){
    if(cache == ' ') break;
    num[i] = cache;
    i++;
    //printf("%c", cache);
  }
  int len = i;
  long long n = 0;                                      //Num for decimal num
  // if(1){
    // toDec(num, i);
    n = 0;
    for(int i = 0; i < len; i++){                       //Translate from custom to decimal
      int dig;
      if(num[i] >= '0' && num[i] <= '9') dig = num[i] - 48;
      else dig = num[i] - 87;
      //printf("%d\n", dig);
      n += dig * (long long)(pow(p, len - i - 1));
      //printf("%ld %ld\n", n, (long long)pow(p, (len - i -1)));
    }
    //printf("\n:%d:", n);
    //TEST PASSED
  // }
  // if(q != 10){
    char ostArr[30];      //Массив остатка
    int ost = 0, fdIndex = 0; //Остаток и индекс хуй знает зачем
    long long cn = n;     //
    while(cn > 0){
      ost = cn % q;
      cn = (long long)cn / q;
      //printf("%ld %d\n", cn, ost);
      if(ost >= 0 && ost < 10) ostArr[fdIndex] = (char)(ost + 48);
      else ostArr[fdIndex] = (char)(ost + 87);
      fdIndex++;
    }
    for(int l = fdIndex - 1; l >= 0; l--) printf("%c", ostArr[l]);
    printf("\0");
  // }
  return 0;
}