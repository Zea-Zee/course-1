#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAXN 10000

void merge(int arr[], int start, int mid, int end) {
  int lenA = mid - start + 1;
  int lenB = end - mid;

  int *arrA = (int*) malloc(4 * lenA);
  int *arrB = (int*) malloc(4 * lenB);

  for (int i = 0; i < lenA; i++) arrA[i] = arr[start + i];
  for (int j = 0; j < lenB; j++) arrB[j] = arr[mid + 1 + j];

  int i = 0, j = 0, k = start;

  while (i < lenA && j < lenB) {
    if (arrA[i] <= arrB[j]) arr[k++] = arrA[i++];
    else arr[k++] = arrB[j++];
  }

  while (i < lenA) arr[k++] = arrA[i++];
  while (j < lenB) arr[k++] = arrB[j++];
}

void mergeSort(int arr[], int start, int end) {
  if (start >= end) return;
    int mid = start + (int)(end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main(){
	FILE* input = fopen("input.txt", "rb");
	FILE* output = fopen("output.txt", "wb");
	int n;
	fread(&n, sizeof(int), 1, input);
	int *arr = (int*) malloc(sizeof(int) * n);
	fread(arr, sizeof(int), n, input);
  mergeSort(arr, 0, n - 1);
	fwrite(arr, sizeof(int), n, output);
  // free(arr);
	return 0;
}