#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef union {
	int num;
	char digit[4];
} zalupa;

void reverse(char str[]){
	char tmp = str[0];
	str[0] = str[3];
	str[3] = tmp;

	tmp = str[1];
	str[1] = str[2];
	str[2] = tmp;
}

int main(){
	FILE* input = fopen("input.txt", "rb");
	FILE* output = fopen("output.txt", "wb");
	int n = 0, bigFlag = 0;
	zalupa num;
	zalupa sum;
	sum.num = 0;
	fread(&num.num, sizeof(int), 1, input);
	if(num.num > 10000){
		bigFlag = 1;
		reverse(num.digit);
	}
  	for(int i = 0; i < num.num; i++){
		zalupa cache;
		fread(&cache.num, sizeof(int), 1, input);
		if (bigFlag) reverse(cache.digit);
		sum.num += cache.num;
  	}
	if(bigFlag) reverse(sum.digit);
	fwrite(&(sum), sizeof(int), 1, output);
	return 0;
}