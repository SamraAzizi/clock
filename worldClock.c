#include <stdio.h>
#include <time.h>
#include <windows.h>

void print_time(const char *city, int timezone_offset) {
    time_t rawtime;
    struct tm *timeinfo;
    char date_buffer[80];
    char time_buffer[80];

    time(&rawtime);
    timeinfo = gmtime(&rawtime);
    timeinfo->tm_hour += timezone_offset; // Adjust time for timezone offset
    mktime(timeinfo);

    strftime(date_buffer, sizeof(date_buffer), "%Y-%m-%d", timeinfo);
    strftime(time_buffer, sizeof(time_buffer), "%I:%M:%S %p", timeinfo);
    printf("%-15s : Date: %s  Time: %s\n", city, date_buffer, time_buffer);
}

int main() {
    while (1) {
        system("cls"); // Clear the console screen
        printf("=== World Clock ===\n");
        print_time("New York", -5);     // Eastern Standard Time (EST)
        print_time("London", 0);        // Greenwich Mean Time (GMT)
        print_time("Tokyo", +9);        // Japan Standard Time (JST)
        print_time("Sydney", +11);      // Australian Eastern Standard Time (AEST)
        print_time("Dubai", +4);        // Gulf Standard Time (GST)
        print_time("Paris", +1);        // Central European Time (CET)
        print_time("Moscow", +3);       // Moscow Standard Time (MSK)
        print_time("Beijing", +8);      // China Standard Time (CST)
        print_time("Berlin", +1);       // Central European Time (CET)
        print_time("Rome", +1);         // Central European Time (CET)
        print_time("Toronto", -5);      // Eastern Standard Time (EST)
        print_time("São Paulo", -3);    // Brasília Time (BRT)
        print_time("Mexico City", -6);  // Central Standard Time (CST)
        print_time("Mumbai", +5);       // Indian Standard Time (IST)
        print_time("Singapore", +8);    // Singapore Standard Time (SGT)
        print_time("Bangkok", +7);      // Indochina Time (ICT)
        print_time("Cairo", +2);        // Eastern European Time (EET)
        print_time("Stockholm", +1);    // Central European Time (CET)
        print_time("Madrid", +1);       // Central European Time (CET)
        print_time("Quetta", +5);       // Pakistan Standard Time (PKT)
        Sleep(1000); // Wait for 1 second before updating
    }
    return 0;
}
