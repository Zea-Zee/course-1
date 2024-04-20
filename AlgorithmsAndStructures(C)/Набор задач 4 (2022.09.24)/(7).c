	#define _CRT_SECURE_NO_WARNINGS
	#include <stdlib.h>
	#include <stdio.h>
	#include <math.h>
	#include <string.h>
	#define MX 127

	int main(){
		//FILE * input = fopen("input.txt", "r");
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		int arr[MX] = {0};
		char cache;
		while(scanf("%c", &cache) == 1) arr[(int)cache] += 1;
		for(int i = 0; i < MX; i++){
			if(arr[i] > 0 && i >= 32 && i <= 126){
				printf("%c ", i);
				for(int j = 0; j < arr[i]; j++) printf("#");
				printf("\n");
			}
		} 
		return 0;
	}