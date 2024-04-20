#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 1000001

int main(int argc, char **argv){
	// printf("bebra");     //argv[0] --- путь к испольняемому файлу
	// for (int i = 0; i < argc; i++) {        //argc --- количество параметров + 1
    // 	printf("[%d]: %s\n", i, argv[i]);     //argv[0] --- путь к испольняемому файлу
    // }  
		// printf("DOWN: \n");\
		long long answ;
		if(argc > 4){
			// printf("3\n");
			// printf("%s\n", argv[1]);
			// printf("%s\n", argv[2]);
			// printf("%s\n", argv[3]);
			if(strcmp(argv[1], "-m") == 0){
				long long a = atoll(argv[4]);
				long long b = atoll(argv[5]);
				if(strcmp(argv[3], "add") == 0){
					b += a;
					// printf("add\n %lld", b);
				} else if(strcmp(argv[3], "sub") == 0){
					b = a - b;
					// printf("sub\n %lld", b);
				} else if(strcmp(argv[3], "mul") == 0){
					b *= a;
					// printf("%lld", a, b, a * b);
				}
				// printf("%lld", (long long) atoll(argv[2]));
				b = b % (long long) atoll(argv[2]);
				if(b < 0){
					b += (long long) atoll(argv[2]);
					// b += (long long) atoll(argv[5]);
				}
				printf("%lld", b);
			} else{
				long long a = atoll(argv[2]);
				long long b = atoll(argv[3]);
				if(strcmp(argv[1], "add") == 0){
					b += a;
					// printf("add\n %lld", b);
				} else if(strcmp(argv[1], "sub") == 0){
					b = a - b;
					// printf("sub\n %lld", b);
				} else if(strcmp(argv[1], "mul") == 0){
					b *= a;
					// printf("%lld", a, b, a * b);
				}
				// printf("%lld", (long long) atoll(argv[5]));
				b = b % (long long) atoll(argv[5]);
				if(b < 0){
					b += (long long) atoll(argv[5]);
					// b += (long long) atoll(argv[5]);
				}
				printf("%lld", b);
			}
		}
		else if(argc > 3){
			long long a = atoll(argv[2]);
			long long b = atoll(argv[3]);
			if(strcmp(argv[1], "add") == 0){
				b += a;
				// printf("add\n %lld", b);
			} else if(strcmp(argv[1], "sub") == 0){
				b = a - b;
				// printf("sub\n %lld", b);
			} else if(strcmp(argv[1], "mul") == 0){
				b *= a;
				// printf("%lld", a, b, a * b);
			}
			printf("%lld", b);
		} else{
			fprintf(stderr, "No parameters specified.");
			return 13;
		}
	return 0;
}