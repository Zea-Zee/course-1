#include <stdio.h>

#if defined(__GNUC__) && !defined(__llvm__)
#define PRINTC void printCompiler(){printf("Compiler: GCC\n");}
#elif defined(__TINYC__)
#define PRINTC void printCompiler(){printf("Compiler: TCC\n");}
#else
#define PRINTC void printCompiler(){printf("Compiler: clang\n");}
#endif

#if !defined(NDEBUG)
#define ISASSERT void printIsAssertOn(){printf("Asserts: enabled\n");}
#else
#define ISASSERT void printIsAssertOn(){printf("Asserts: disabled\n");}
#endif

//#include <assert.h>
//#include <string.h>
//#include <stdlib.h>
//#include <math.h>
//#include <time.h>

PRINTC
ISASSERT

int main(){
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    printCompiler();
    if(sizeof(void*) <= 4) printf("Bitness: 32\n");
    else printf("Bitness: 64\n");
    printIsAssertOn();

//    printf("Compiler: GCC\n");
//    printf("Bitness: 64\n");
//    printf("Asserts: enabled\n");

    return 0;
}