#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include "pack.h"

typedef union bits{
//    char *string;
    char string[50];
    double ft;
    int num;
    char* pointer;
} bits;

int pack(char *buffer, const char *format, ...){
    int count = 0;
    char cache;
    char *stringer;
    if(buffer != NULL){
        bits val;
//        val.string = (char*) calloc(100, sizeof(char));
        va_list ap;
        va_start(ap, format);
        for(int i = 0; i < strlen(format) + 1; i++){
            cache = format[i];
            if(cache == '%'){
                i++;
                cache = format[i];
                if(cache == 'd'){
//                    val.num = va_arg(ap, int);
//                    strcpy(&buffer[count], val.string);
//                    count += 4;
//                    for(int b = 0; b < 4; b++){
//                        buffer[count] = val.string[b];
//                        count++;
//                    }
                    int a = va_arg(ap, int);
                    stringer = (char*) &a;
                    for(int b = 0; b < 4; b++){
                        buffer[count] = stringer[b];
                        count++;
                    }
                }else if(cache == 'l'){
//                    val.ft = va_arg(ap, double);
//                    strcpy(&buffer[count], val.string);
//                    count += 8;
//                    for(int b = 0; b < 8; b++){
//                        buffer[count] = val.string[b];
//                        count++;
//                    }
                    double a = va_arg(ap, double);
                    stringer = (char*) &a;
                    for(int b = 0; b < 8; b++){
                        buffer[count] = stringer[b];
                        count++;
                    }
                }
                else if(cache == 's'){
//                    val.pointer = va_arg(ap, char*);
//                    int len = strlen(val.pointer) + 1;
//                    strcpy(&buffer[count], val.pointer);
//                    count += len;
//                    for(int b = 0; b < len; b++){
//                        buffer[count] = val.string[b];
//                        count++;
//                    }
//                    count += len;
                    stringer = va_arg(ap, char*);
                    int len = strlen(stringer) + 1;
                    for(int b = 0 ; b < len; b++){
                        buffer[count] = stringer[b];
                        count++;
                    }
                }
            }
        }
        va_end(ap);
    } else{
        va_list ap;
        va_start(ap, format);
        for(int i = 0; i < strlen(format) + 1; i++){
            cache = format[i];
            if(cache == '%'){
                i++;
                cache = format[i];
                if(cache == 'd'){
                    count += 4;
                    int a = va_arg(ap, int);
                }else if(cache == 'l'){
                    count += 8;
                    double a = va_arg(ap, double );
                }
                else if(cache == 's'){
                    char *a = va_arg(ap, char*);
                    int len = strlen(a) + 1;
                    count += len;
                }
            }
        }
        va_end(ap);
    }
    return count;
}