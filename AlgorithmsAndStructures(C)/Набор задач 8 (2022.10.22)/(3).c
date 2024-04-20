// #include <stdlib.h>
// #include <stdio.h>
// #include <math.h>
// #include <string.h>
// #define MAXN 10000


// int main(){


// 	return 0;
// }

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAXN 10000

typedef struct{
	char name[21];
	long long size;
	char isDirectory;
	long long createTime;
	long long updateTime;
	char isHide;
} file;

file insertSort(file arr[], int len){
	file cache;
	for(int i = 1; i < len; i++){
		for(int j = i; j > 0 && strcmp(arr[j - 1].name, arr[j].name) > 0; j--){
			// // cache.name = arr[j - 1].name;
			// strcpy(cache.name, arr[j - 1].name);
			// // arr[j - 1].name = arr[j].name;
			// strcpy(arr[j - 1].name, arr[j].name);
			// // arr[j].name = cache.name;
			// strcpy(arr[j].name, cache.name);
			cache = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = cache;
		}
	}
}

int main(){
	FILE* input = fopen("input.txt", "rb");
	FILE* output = fopen("output.txt", "wb");
	// FILE* input = fopen("1.in", "rb");
	// FILE* output = fopen("1.out", "wb");
	int n = 0, index = 0;
	file *arr = (file*) malloc (sizeof(file) * MAXN);
	long long createTime = 0, updateTime = 0;
	fread(&n, sizeof(int), 1, input);
	fread(&createTime, sizeof(long long), 1, input);
	fread(&updateTime, sizeof(long long), 1, input);
	for(int i = 0; i < n; i++){
		file cache;
		fread(cache.name, 21, 1, input);
		fread(&cache.size, sizeof(long long), 1, input);
		fread(&cache.isDirectory, sizeof(char), 1, input);
		fread(&cache.createTime, sizeof(long long), 1, input);
		fread(&cache.updateTime, sizeof(long long), 1, input);
		fread(&cache.isHide, sizeof(char), 1, input);
		// if(cache.createTime == 131786542620621115) 1;
		// else while(1);
		if(cache.createTime >= createTime && cache.createTime <= updateTime){
			if(cache.updateTime <= updateTime){
				if((int)cache.isDirectory == 0 && (int)cache.isHide == 0){
					arr[index] = cache;
					index++;
				}
			}
		}
		// if(n == 11) while(1) 1;
	}
	insertSort(arr, index);
	for(int i = 0; i < index; i++){
		fwrite(arr[i].name, 21, 1, output);
		fwrite(&arr[i].size, 8, 1, output);
		fwrite(&arr[i].isDirectory, 1, 1, output);
		fwrite(&arr[i].createTime, 8, 1, output);
		fwrite(&arr[i].updateTime, 8, 1, output);
		fwrite(&arr[i].isHide, 1, 1, output);
	}
	// fwrite(&(sum), sizeof(int), 1, output);
	return 0;
}