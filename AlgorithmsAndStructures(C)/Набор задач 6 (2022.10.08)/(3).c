#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define MX 1000000
#define MX_LEN 1000000
#define MX_REQ 1000000

typedef struct String_s{
	long long len;
	long long index;
	char *str;
	// char str[MX_LEN];
} String;

String arr[MX_REQ];

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n = 0, indexes[MX_REQ];
	long long count = 0;
	scanf("%d", &n);
	for(long long i = 0; i < MX_REQ; i++) indexes[i] = -1;
	long long a = 0;
	for(long long i = 0; i < n; i++){
		long long req;
		scanf("%lld", &req);
		if(req == 0){
			String obj;
			scanf("%lld", &obj.len);
			obj.str = (char*) calloc(obj.len + 1, sizeof(char));
			scanf("%s", obj.str);
			obj.index = count;
			arr[count] = obj;
			count++;
			continue;
		}
		if(req == 1){
			long long index;
			scanf("%lld", &index);
			arr[index].len = 0;
			free(arr[index].str);
			continue;
		}
		if(req == 2){
			long long index;
			scanf("%lld", &index);
			// printf("%c\n", (arr[index].str[0]));
			printf("%s\n", (arr[index].str));
			continue;
		}
		if(req == 3){
			long long index, symbCount = 0;
			char symb;
			scanf("%lld %c", &index, &symb);
			for(long long j = 0; j < arr[index].len; j++){
				if(arr[index].str[j] == symb) symbCount++;
			}
			printf("%lld\n", symbCount);
			continue;
		}
	}
	// for(int i = 0; i < MX_REQ; i++){
	// 	free(arr[i].str);
	// }
	return 0;
}