#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define MX 10
#define MX_LEN 8
#define MX_REQ 10

typedef struct List_s{
	int index;
	char *str;
	int next;
} List;

List makeClean(List list[], int len){
	for(int i = 1; i < len; i++){
		for(int j = i; j > 0; j--){
			if(list[j - 1].index > list[j].index){
				List tmp = list[j - 1];
				list[j - 1] = list[j];
				list[j] = tmp;
			}
		}
	}
}

List showList(List list[], int len){
	for(int i = 0; i < len; i++){
		printf("%d %s", list[i].index, list[i].str);
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n = 0, next = 0;;
	scanf("%d", &n);
	List list[n];
	char cache[MX_LEN] = {"\0"};
	for(int i = 0; i < n; i++){
		List elem;
		elem.str = (char*) calloc(MX_LEN, sizeof(char));
		scanf("%d", &elem.index);
		scanf("%s", elem.str);
		if(i == n - 1) elem.next = -1;
		else scanf("%c", &elem.next);
		// elem.str = *cache;
		list[i] = elem;
	}
	makeClean(list, n);
	// showList(list, n);
	for(int i = 0; i < n; i++){
		printf("%d %s\n", list[i].index, list[i].str);
		// printf("%s\n", (list[i].str));
	}
	return 0;
}