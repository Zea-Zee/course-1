#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define MX 2 * 100000
#define DOHUYA 1000000000

// int findNum(int arr[], int len, int num, int addI){
// 	if(!(len & 1)){
// 		if(num < arr[len / 2 - 1]){
			
// 		} else if(num == arr[len / 2 - 1]) return [len / 2 - 1, 0];
// 		else if(num > arr[len / 2]{

// 		} else if(num == arr[len / 2]) return [len / 2, 0];
// 		else {
// 			int minDif = DOHUYA;
// 			minDif = arr[len / 2 - 1] - num;
// 			if(arr[len / 2] > minDif) return [len / 2 - num, arr[len / 2]];
// 			return [len / 2 - 1, minDif];
// 		}
// 	} else{
// 		return [DOHUYA, DOHUYA];
// 	}
// 	return 0;
// }

int binSearch(int arr[], int len, int num){
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
		if(tmp == num && (middle == len - 1 || arr[middle + 1] > tmp)) return middle;
		if(tmp > num) right = middle - 1;
		else left = middle + 1;
	}
	return -1;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	// int *arr = (int*) calloc(n, sizeof(int));
	int arr[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &(arr[i]));
	}
	int num;
	int ops;
	int res;
	int prev = 0;
	scanf("%d", &ops);
	for(int i = 0; i < ops; i++){
		scanf("%d", &num);
		res = binSearch(arr, n, (num + prev));
		printf("\n%d", res);
		prev = res;
	}

	return 0;
}