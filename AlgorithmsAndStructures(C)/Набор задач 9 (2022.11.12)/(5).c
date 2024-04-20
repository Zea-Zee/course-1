#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAXN 10000

void swap(int arr[], int a, int b){
  int tmp = arr[a];
  arr[a] = arr[b];
  arr[b] = tmp;
}

int partition(int a[], int start, int end){
    int pivot = a[end];
    int counter = start; 
    for (int i = start; i < end; i++) if (a[i] <= pivot) swap(a, i, counter++);
    swap (a, counter, end);
    return counter;
}
 
void quicksort(int a[], int start, int end){
    if (start >= end) return;
    int pivot = partition(a, start, end);
    quicksort(a, start, pivot - 1);
    quicksort(a, pivot + 1, end);
}

int main(){
	FILE* input = fopen("input.txt", "rb");
	FILE* output = fopen("output.txt", "wb");
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
  // int arr[9] = {9,8,7,6,1,5,2,0,-7};
  // quicksort(arr, 0, 8);
  int n;
  fread(&n, sizeof(int), 1, input);
  int *arr = (int*) malloc(sizeof(int) * n);
  fread(arr, sizeof(int), n, input);
  quicksort(arr, 0, n - 1);
  // if(arr[n - 1] == 38) while(1);
  fwrite(arr, sizeof(int), n, output);
	return 0;
}