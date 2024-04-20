#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 1000001

typedef struct{
	char **value;
	int count;
} arr;

arr *create_item(char *value){
	arr *item = (arr *)malloc(sizeof(arr));
	item->value = (char **)malloc(sizeof(char *));
	item->count = 0;
	item->value[item->count] = (char *)malloc(strlen(value) + 1);
	strcpy(item->value[item->count], value);
	item->count++;
	return item;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, key;
	char str[9];
	arr x;
	scanf("%d", &n);
	arr **words = (arr **)malloc(M * sizeof(arr *));
	for (int i = 0; i < n; i++){
		scanf("%d ", &key);
		gets(str);
		if (words[key]){
			words[key]->value = (char **)realloc(words[key]->value, (words[key]->count + 1) * sizeof(char*));
			words[key]->value[words[key]->count] = (char *)malloc(strlen(str) + 1);
			strcpy(words[key]->value[words[key]->count], str);
			words[key]->count++;
		}
		else words[key] = create_item(str);
	}
	for (int i = 0; i < M; i++) if (words[i]) for (int j = 0; j < words[i]->count; j++) printf("%d %s\n", i, words[i]->value[j]);
	return 0;
}