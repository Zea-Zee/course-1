#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAXN 10000

int merge (const int *a , int aLen , const int *b , int bLen , int res[]){
	// res = (int*) malloc(sizeof(int) * (aLen + bLen));
	int aIndex = 0, bIndex = 0;
	for(int i = 0; i < (aLen + bLen); i++){
		int al = a[aIndex];
		int bl = b[bIndex];
		if(bIndex == bLen){
			res[i] = al;
			aIndex++;
		} else if(aIndex == aLen){
			res[i] = bl;
			bIndex++;
		} else if(a[aIndex] < b[bIndex]){
			res[i] = al;
			aIndex++;
		} else{
			res[i] = bl;
			bIndex++;
		}
	}
	return 0;
}

int main(){
	FILE* input = fopen("input.txt", "rb");
	FILE* output = fopen("output.txt", "wb");
	int first, second;
	fread(&first, sizeof(int), 1, input);
	fread(&second, sizeof(int), 1, input);
	// int* firstArr = (int*) malloc(sizeof(int) * first);
	// int* secondArr = (int*) malloc(sizeof(int) * second);
	int firstArr[first];
	int secondArr[second];
	fread(firstArr, sizeof(int), first, input);
	fread(secondArr, sizeof(int), second, input);
	// first = 3;
	// second = 5;
	// firstArr[0] = 4;
	// firstArr[1] = 5;
	// firstArr[2] = 6;

	// secondArr[0] = 1;
	// secondArr[1] = 2;
	// secondArr[2] = 2;
	// secondArr[3] = 3;
	// secondArr[4] = 4;

	// int *result = (int*) malloc(sizeof(int) * (first + second));
	int result[(first + second)];
	merge(firstArr, first, secondArr, second, result);
	fwrite(result, sizeof(int), (first + second), output);
	return 0;
}