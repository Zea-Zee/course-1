#include "logger.h"
#include <stdarg.h>
// If file != 0, then enables logging and sets current logfile.
// All the messages printed by logPrintf go into this file afterwards.
// If file = 0, disables logging (logPrintf does nothing afterwards).
// Logging is also disabled initially.
// The file is NOT closed when logging is disabled.
FILE *writePath = NULL;
long long callsCount  = 0;
void logSetFile(FILE *file){
    writePath = file;
}

// Prints text message to the current logfile (with printf formatting).
// If logging is disabled, then it does nothing.
void logPrintf(const char *format, ...){
if(writePath){
        va_list ap;
        va_start(ap, format);
        vfprintf(writePath, format, ap);
        va_end(ap);
        callsCount++;
    }
}

// Returns the number of successful logPrintf calls since program start.
// A call is considered unsuccessful when logging is disabled.
int getLogCallsCount(){
//    printf("%d", callsCount);
    return callsCount;
}