#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define MX 10000
#define inputMX 10000


typedef struct LongNum_s {
	int len ; //сколько цифр в числе
	int arr [MX]; //массив десятичных цифр числа
	// int * arr = (int*) calloc(MX, sizeof(int));
} LongNum ;

void fillArr(int arr[], int len){
	for(int i = 0; i < len; i++) arr[i] = 0;
}

void fillNumber(LongNum *a, int num, int start){
	// a->len = a->len + start;
	int flag = 0;
	while(num > 0){
		flag++;
		a->arr[MX - a->len - start - 1] = num % 10;
		a->len++;
		num = (int)num / 10;
	}
	a->len = a->len + start;
	if(!flag) a->len++;
}

int calcBigNums(int a[], int *b, int len){
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

LongNum multBigNums(int a[], int *b, int lenA, int lenB){
	int carry = 0, cache = 0;
	LongNum total;
	total.len = 0;
	fillArr(total.arr, MX);
	for(int i = MX - 1; i >= MX - lenA; i--){
		LongNum sec;
		sec.len = 0;
		fillArr(sec.arr, MX);
		for(int j = MX - 1; j >= MX - lenB; j--){
			int av = a[i], bv = b[j];
			cache = (b[j] * a[i]) + carry;
			if(cache > 9){
				carry = (int)cache / 10;
				cache = cache % 10;
			} else carry = 0;
			if(j == MX - 1) fillNumber(&sec, cache, MX - 1 - i);
			else fillNumber(&sec, cache, 0);
		}
		if(carry > 0){
			sec.arr[MX -sec.len - 1] = carry;
			sec.len++;
			carry = 0;
		}
		total.len = calcBigNums(sec.arr, total.arr, sec.len);
	}
	return total;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	// LongNum num;
	// fillArr(num.arr, MX);
	// printf("%d", num.arr[10]);
	char first[inputMX] = {"\0"}, second[inputMX] = {"\0"};
	scanf("%s %s", first, second);
	LongNum a;
	LongNum b;
	LongNum res;
	a.len = 0;
	b.len = 0;
	for(int i = 0; i < MX; i++) a.arr[i] = 0;
	for(int i = 0; i < MX; i++) b.arr[i] = 0;
	int stln = strlen(first);
	for(int i = 0; i < stln; i++){
		b.arr[MX - stln + i] = first[i] - '0';
		b.len++;
	}
	stln = strlen(second);
	for(int i = 0; i < stln; i++){
		a.arr[MX - stln + i] = second[i] - '0';
		a.len++;
	}
	// fillArr(a.arr, MX);
	// fillArr(b.arr, MX);
	// fillArr(res.arr, MX);
	// res.len = 0;
	// a.len = 0;
	// b.len = 0;
	
	// fillNumber(&b, first, 0);
	// fillNumber(&b, 1, 1);
	// fillNumber(&a, second, 0);
	// printf("work");
	res = multBigNums(a.arr, b.arr, a.len, b.len);
	// // printf("work");

	// for(int i = MX - b.len; i < MX; i++){
	// 	printf("%d", b.arr[i]);
	// }
	// printf("\n");
	// for(int i = MX - a.len; i < MX; i++){
	// 	printf("%d", a.arr[i]);
	// }
	// printf("\n");
	for(int i = MX - res.len; i < MX; i++){
		printf("%d", res.arr[i]);
		//if(MX - res.len == 0) break;
	}
}