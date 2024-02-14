#include <stdio.h>
#include <time.h>
#include <unistd.h>

void stopwatch() {
    int hours = 0, minutes = 0, seconds = 0;

    while (1) {
        printf("\r%02d:%02d:%02d", hours, minutes, seconds);
        fflush(stdout);
        sleep(1);
        seconds++;

        if (seconds == 60) {
            seconds = 0;
            minutes++;
        }
        if (minutes == 60) {
            minutes = 0;
            hours++;
        }
    }
}

int main() {
    printf("Stopwatch started. Press Ctrl+C to stop.\n");
    stopwatch();

    return 0;
}
