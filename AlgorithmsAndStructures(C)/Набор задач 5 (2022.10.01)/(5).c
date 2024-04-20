#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define MX 500


typedef struct LongNum_s {
	int len ; //сколько цифр в числе
	int arr [MX]; //массив десятичных цифр числа
	// int * arr = (int*) calloc(MX, sizeof(int));
} LongNum ;

void fillArr(int arr[], int len){
	for(int i = 0; i < len; i++) arr[i] = 0;
}

int calcBigNums(int a[], int *b, int len){
	// int len, carry = 0;
	// if(lenA > lenB) len = lenA;
	// else len = lenB;
	int carry = 0;
	for(int i = MX - 1; i >= MX - len; i--){
		// printf("\n %d+%d", a[i], b[i]);
		b[i] += (a[i] + carry);
		if(b[i] > 9){
			carry = (int)b[i] / 10;
			b[i] = b[i] % 10;
		} else carry = 0;
		// printf(" b:%d carry:%d", b[i], carry);
	}
	if(carry > 0){
		b[MX - len - 1] = carry;
		return len + 1;
	}
	return len;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	// LongNum num;
	// fillArr(num.arr, MX);
	// printf("%d", num.arr[10]);

	int number, counter = 0;
	scanf("%d", &number);
	LongNum a;
	LongNum b;
	LongNum cache;
	fillArr(a.arr, MX);
	fillArr(b.arr, MX);
	a.len = 1;
	b.len = 1;
	b.arr[MX - 1] = 1;
	int ta = 0;
	int tb = 1;
	for(int i = 1; i < number; i++){
		//B = b + a
		//A = b - a
		// tb += ta;
		// ta = tb - ta;
		cache = b;
		b.len = calcBigNums(a.arr, b.arr, b.len);
		//printf("-> b.len:%d", b.len);
		a = cache;
		
	}
	//calcBigNums(a.arr, b.arr, &b.len);
	for(int i = MX - b.len; i < MX; i++){
		printf("%d", b.arr[i]);
	}
	// printf("\n%d", b.arr[MX - 1]);
}