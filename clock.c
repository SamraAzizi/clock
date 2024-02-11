#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {
    while(1) {
        // Getting current time
        time_t rawtime;
        struct tm *timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        
        // Printing digital clock
        printf("\r%02d:%02d:%02d", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
        fflush(stdout); // Flush the output buffer to show the time immediately
        
        // Wait for 1 second
        sleep(1);
    }

    return 0;
}
