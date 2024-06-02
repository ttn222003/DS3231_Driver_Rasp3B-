#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <errno.h> // Include errno header
#include <stdint.h>
#include "DS3231.h"

uint8_t time_read[8];

int main() {
    int fd;
    // Open the device
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return errno;
    }

    while (1)
    {
        if(getTime(fd, time_read) < 0)
        {
            printf("Fail to read data\n");
        }

        if(time_read[7] == HR_FORMAT_24)
            printf("%d:%d:%d\n", time_read[2], time_read[1], time_read[0]);

        else if(time_read[7] == HR_FORMAT_12_AM)
            printf("%d:%d:%d AM\n", time_read[2], time_read[1], time_read[0]);

        else if(time_read[7] == HR_FORMAT_12_PM)
            printf("%d:%d:%d PM\n", time_read[2], time_read[1], time_read[0]);

        if(time_read[3] == Sunday)
            printf("Today is Sunday\n");
        else if(time_read[3] == Monday)
            printf("Today is Monday\n");
        else if(time_read[3] == Tuesday)
            printf("Today is Tuesday\n");
        else if(time_read[3] == Wednesday)
            printf("Today is Wednesday\n");
        else if(time_read[3] == Thursday)
            printf("Today is Thursday\n");
        else if(time_read[3] == Friday)
            printf("Today is Friday\n");
        else if(time_read[3] == Saturday)
            printf("Today is Saturday\n");

        printf("%d-%d-%d\n", time_read[4], time_read[5], time_read[6]);
        printf("\n");
        sleep(1);
    }
    
    // Close the device
    close(fd);
    return 0;
}