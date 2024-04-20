// #define _CRT_SECURE_NO_WARNINGS
// #include <stdlib.h>
// #include <stdio.h>
// #include <math.h>
// #include <string.h>
// #define MX 100000

// int main(void) {
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);

// 	int max, n, cache, mn;
// 	scanf("%d %d", &max, &n);
// 	if(max > n) mn = max;
// 	else mn = n;
// 	//if(mn > 301) mn = 301;
// 	int arr[MX][2], cArr[MX] = {0};
// 	for(int i = 0; i < n; i++){
// 		scanf("%d %d", &arr[i][0], &arr[i][1]);
// 		cArr[arr[i][0]]++;
// 	}
// 	int fl1 = 1, fl2 = 1, fl3 = 1, fl4 = 1, fl5 = 1;		//Declare flags
// 	for(int i = 1; i <= mn; i++) if(cArr[i] > 1){			//Chech 1st state
// 		printf("0 ");
// 		return 0;
// 	}
// 	for(int i = 1; i <= n; i++) cArr[i] = 0;//Zero cacheArr
// 	printf("1 ");
// 	if(max <= n) printf("2 ");
// 	for(int i = 0; i < n; i++){
// 		cArr[arr[i][1]]++;
// 		//printf("/%d/", cArr[arr[i][1]]);
// 	}
// 	for(int i = 1; i <= mn; i++){
// 		if(cArr[i] > 1) fl3 = 0;
// 		//printf("%d", cArr[i]);
// 	}
// 	if(fl3 == 1) printf("3 ");
// 	if(fl3 == 1 && n == max) printf("4 ");
// 	if(fl4 == 1 && fl3 == 1) printf("5");
// 	return 0;
// }

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

  // int reverse(char *start, int len){
  //   if(len > 0){
  //     for(int i = len - 1; i >= 0; i--){
  //       printf("%c", start[i]);
  //     }
  //     printf("\n");
  //   }
  //   return 0;
  //}
  // void concat ( char pref , char * suff ){
  //   printf("%c", pref);
  //}

  int calcLetters ( char * iStr , int * oLowerCnt , int * oUpperCnt , int * oDigitsCnt){
    int count = 0;
    for(int i = 0; i < strlen(iStr); i++){
      if(iStr[i] >= 65 && iStr[i] <= 90) (*oUpperCnt)++;
      else if(iStr[i] >= 97 && iStr[i] <= 122) (*oLowerCnt)++;
      else if(iStr[i] >= 48 && iStr[i] <= 57) (*oDigitsCnt)++;
      if(iStr[i] >= 32 && iStr[i] <= 126) count++;
    }
    // printf("has %d chars: %d are letters (%d lower, %d upper), %d are digits.\n", strlen(iStr), (*oUpperCnt) + (*oLowerCnt), *oLowerCnt, *oUpperCnt, *oDigitsCnt);
    return count;
  }


  int main(void) {
    FILE * input = fopen("input.txt", "r");
    //freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char cache[101];
    int j = 1, ln = 0;
    while(fgets(cache, 102, input) && cache != "\n"){
      int l = 0, u = 0, d = 0;
      ln = calcLetters(cache, &l, &u, &d);
      printf("Line %d has %d chars: %d are letters (%d lower, %d upper), %d are digits.\n", j, ln, l + u, l, u, d);
	  j += 1;
    }
    return 0;
  }