#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAXN 10000

// int sorter(int arr[], int len){
//   for(int i = 1; i < len; i++){
//     int j = i - 1;
//     while(arr[j + 1] < arr[j] && j >= 0){
//       int cache = arr[j + 1];
//       arr[j + 1] = arr[j];
//       arr[j] = cache;
//       j--;
//     }
//   }
//   return 0;
// }

int partition (int *a , int n , int pivot){
	int *left = (int*) malloc(sizeof(int) * n);
	int *right = (int*) malloc(sizeof(int) * n);
	int lIndex = 0, rIndex = 0;
	int lPiv = 0, rPiv = 0;
	for(int i = 0; i < n; i++){
		int el = a[i];
		if(el == pivot){
			if(lPiv > rPiv){
				rPiv++;
				right[rIndex] = el;
				rIndex++;
			} else {
				lPiv++;
				left[lIndex] = el;
				lIndex++;
			}
			continue;
		}
		if(el < pivot){
			left[lIndex] = el;
			lIndex++;
		} else{
			right[rIndex] = el;
			rIndex++;
		}
	}
	// sorter(right, rIndex);
	for(int i = 0; i < lIndex; i++){
		a[i] = left[i];
	}
	for(int i = lIndex; i < n; i++){
		a[i] = right[i - lIndex];
	}
	return lIndex;
}

int main(){
	FILE* input = fopen("input.txt", "rb");
	FILE* output = fopen("output.txt", "wb");
	int n, pivo;
	fread(&n, sizeof(int), 1, input);
	fread(&pivo, sizeof(int), 1, input);
	int *arr = (int*) malloc(sizeof(int) * n);
	fread(arr, sizeof(int), n, input);
	int len  = partition(arr, n, pivo);
	fwrite(&len, sizeof(int), 1, output);
	fwrite(arr, sizeof(int), n, output);
	return 0;
}