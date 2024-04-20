#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct data_s{
    char name[33];//(char*) malloc(30 * sizeof(char));
	int birthday;
	char birth[5];
	char country[13];
	char movie[23];
} data;

typedef struct movie_s{
    char name[33];//(char*) malloc(30 * sizeof(char));
	char movie[23];
} movie;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	char trash;
	scanf("%d", &n);
	data arr[n];
	scanf("%c", &trash); //\n
	for(int i = 0; i < n; i++){
		data cache;
		char symb;
		char inp[100];
		gets(inp);
		char* str;
		// scanf("%c", &symb);	//"
		// str = strtok(inp, '"');
		strcpy((cache.name), strtok(inp, "\""));
		strcpy((cache.birth), strtok(NULL, " "));
		strcpy((cache.country), strtok(NULL, "\""));
		// // scanf("%c", &symb);	//' '
		// // scanf("%c", &symb);	//"
		// str = strtok(NULL, '"');
		// strcpy((cache.name), str);
		// scanf("%d", &(cache.birthday));
		// gets(cache.country);
		// printf("%s ", strtok(inp, "\""));
		// printf("%s ", strtok(NULL, " "));
		// printf("%s\n", strtok(NULL, "\""));
		arr[i] = cache;
	}
	int mn;
	scanf("%d", &mn);
	movie movies[mn];
	scanf("%c", &trash); //\n
	for(int i = 0; i < mn; i++){
		movie cache;
		char symb;
		char inp[100];
		gets(inp);
		char* str;
		str = strtok(inp, "\"");
		// printf("%s ", str);
		strcpy((cache.name), str);
		str = strtok(NULL, "\"");
		// printf("%s\n", str);
		str = strtok(NULL, "\"");
		// printf("%s\n", str);
		// printf("%s\n", str);
		// strtok(NULL, "");
		strcpy((cache.movie), str);
		movies[i] = cache;
	}

	for(int i = 0; i < mn; i++){
		for(int j = 0; j < n; j++){
			data elem = arr[j];
			if(!strcmp(elem.name, movies[i].name)){
				printf("\"");
				fputs(elem.name, stdout);
				// printf(" %d", (int)elem.birthday / 1000);
				// printf("%d", (int)(elem.birthday % 1000) / 100);
				// printf("%d", (int)(elem.birthday % 100) / 10);
				// printf("%d ", (int)(elem.birthday % 10));
				printf("\"");
				printf(" ");
				fputs(elem.birth, stdout);
				printf(" ");
				printf("\"");
				fputs(elem.country, stdout);
				printf("\"");
				printf(" ");
				printf("\"");
				fputs(movies[i].name, stdout);
				printf("\"");
				printf(" ");
				printf("\"");
				fputs(movies[i].movie, stdout);
				printf("\"");
				printf("\n");
				// break;
			}
		}
	}
	return 0;
}