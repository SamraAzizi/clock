#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void timer(int seconds) {
    while (seconds >= 0) {
        printf("\rTime remaining: %02d:%02d:%02d", seconds / 3600, (seconds % 3600) / 60, seconds % 60);
        fflush(stdout);
        sleep(1);
        seconds--;
    }

    printf("\nTimer completed!\n");
}

int main() {
    int hours, minutes, seconds, totalSeconds;

    printf("Enter the duration of the timer (HH:MM:SS): ");
    scanf("%d:%d:%d", &hours, &minutes, &seconds);

    totalSeconds = hours * 3600 + minutes * 60 + seconds;

    timer(totalSeconds);

    return 0;
}
