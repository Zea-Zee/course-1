#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *arr, int i, int j){
	int tmp = arr[i];
	// int tmp2 = arr[j];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void findMax(int arr[], int l, int r, int* max, int* maxCount){
	int mx = *max;
	int mxc = *maxCount;
	for(int i = l; i < r; i++){
		if(arr[i] > mx){
			mx = arr[i];
			mxc = 1;
		} else if(arr[i] == mx) mxc++;
	}
	*max = mx;
	*maxCount = mxc;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int arr[n];
	char rubbish;
	for(int i = 0; i < n; i++) scanf("%d", &(arr[i]));
	scanf("%c", &rubbish);
	int left = 0;
	int right = 0;
	int max = -2000000000;
	int maxCount = 1;
	for(int i = 0; i < 2 * n - 1; i++){
		char operator;
		scanf("%c", &operator);
		if(operator == 'R'){
			int ar = arr[right];
			if(ar > max){
				max = ar;
				maxCount = 1;
			} else if(ar == max) maxCount++;
			right++;
			printf("%d\n", max);
		} else if(operator == 'L'){
			int al = arr[left];
			if(al == max){
				if(maxCount == 1){
					max = -2000000000;
					maxCount = 1;
					findMax(arr, left + 1, right, &max, &maxCount);
				}
				else maxCount--;
			}
			left++;
			printf("%d\n", max);
		}
	}
	return 0;
}