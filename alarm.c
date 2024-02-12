#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void playSound() {
    // Add system-specific sound playing command
    // This example assumes the 'aplay' command on Linux, you may need to change it for Windows or MacOS
    system("alarm.mp3"); // '&' to run the command in the background
}

int main() {
    int alarm_hour, alarm_min;
    char am_pm;

    // Set the alarm time
    printf("Set the alarm (HH:MM AM/PM): ");
    scanf("%d:%d %c", &alarm_hour, &alarm_min, &am_pm);

    // Convert to 24-hour format if needed
    if (am_pm == 'p' || am_pm == 'P') {
        if (alarm_hour != 12)
            alarm_hour += 12;
    } else if (am_pm == 'a' || am_pm == 'A') {
        if (alarm_hour == 12)
            alarm_hour = 0;
    }

    while(1) {
        // Getting current time
        time_t rawtime;
        struct tm *timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        
        // Printing digital clock
        printf("\rCurrent Time: %02d:%02d:%02d", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
        
        // Check if it's time for the alarm
        if (timeinfo->tm_hour == alarm_hour && timeinfo->tm_min == alarm_min) {
            printf("\n\nALARM! ALARM! ALARM!\n");
            playSound(); // Play sound when alarm rings
            break; // Break out of the loop when alarm rings
        }
        
        fflush(stdout); // Flush the output buffer to show the time immediately
        
        // Wait for 1 second
        sleep(1);
    }

    return 0;
}
