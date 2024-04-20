#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int compare(const void * x1, const void * x2){
  return ( *(int*)x1 - *(int*)x2 );              // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &(arr[i]));

	qsort(arr, n, sizeof(int), compare);
	int set[n];
	int counter = 1, last = arr[0];
	set[0] = last;
	for(int i = 1; i < n; i++){
		int el = arr[i];
		if(el != last){
			set[counter] = el;
			counter++;
			last = el;
		}
	}
	printf("%d", counter);
	for(int i = 0; i < counter; i++)
		printf("\n%d", set[i]);
	return 0;
}