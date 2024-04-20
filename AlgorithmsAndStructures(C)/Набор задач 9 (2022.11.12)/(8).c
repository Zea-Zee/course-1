#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAXN 10000
#define RAND -1
#define DOHUYA 1000000000

void binSearch(int arr[], int len, int num, int answArr[]){
	int left = 0;
	int right = len - 1;
	int middle;
	int tmp;
	int min = DOHUYA;
	int minIndex = -1;
	// int answArr[2];
	while(left <= right){
		middle = (left + right) / 2;
		tmp = arr[middle];
		if(tmp == num){
			answArr[0] = middle;
			answArr[1] = 0;
		}
		if(abs(num - tmp) < min){
			min = abs(num - tmp);
			minIndex = middle;
		}
		if(tmp < num){
			left = middle + 1;
		}
		else right = middle - 1;
	}
	answArr[0] = minIndex;
	answArr[1] = min;
}

int main(){
	// FILE* input = fopen("input.txt", "r");
	// FILE* output = fopen("output.txt", "w");
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
	int n;
  scanf("%d", &n);
  int arr[n];
  for(int i = 0; i < n; i++) scanf("%d", &(arr[i]));
  int diff[n - 1];
  for(int i = 1; i < n; i++) diff[i - 1] = arr[i] - arr[i - 1];
  int c;
  scanf("%d", &c);
  int coefs[c];
  for(int i = 0; i < c; i++) scanf("%d", &(coefs[i]));
  for(int i = 0; i < c; i++){
    int res[2];
    binSearch(diff, n - 1, -coefs[i], res);
    int rs = res[0];
    int min = arr[rs] + coefs[i] * rs;
    // res[0] = res[0] + 1;
    if(res[0] != 0) if(arr[rs - 1] + coefs[i] * (rs - 1) < min) {
        min = arr[rs - 1] + coefs[i] * (rs - 1);
        rs--;
        // printf("-");
      }
    if(res[0] != n - 1) if(arr[res[0] + 1] + coefs[i] * (res[0] + 1) <min){
        min = arr[res[0] + 1] + coefs[i] * (res[0] + 1);
        rs = res[0] + 1;
        // printf("+");
      }
    printf("%d\n", rs);
  }
	return 0;
}