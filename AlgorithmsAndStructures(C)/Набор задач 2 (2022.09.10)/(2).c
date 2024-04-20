#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {
	FILE* input = fopen("input.txt", "r");
	FILE* output = fopen("output.txt", "w");

	char week[][4] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
	char day[4];
	fgets(day, 4, input);
	/*fscanf(input, "%3s", day);*/

	for (int i = 0; i < 7; i++) {
		if (strcmp(day, week[i]) == 0) fprintf(output, "%d", i + 1);
		/*else fprintf(output, "%3s", week[i]);*/
	}
}