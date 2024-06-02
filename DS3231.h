#ifndef __DS3231_H__
#define __DS3231_H__

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <errno.h> // Include errno header
#include <stdint.h>

#define DEVICE_PATH "/dev/ds3231"
#define DS3231_IOCTL_MAGIC 'd'

#define DS3231_IOCTL_WRITE_SECONDS  _IOR(DS3231_IOCTL_MAGIC, 1, int)
#define DS3231_IOCTL_WRITE_MINUTES  _IOR(DS3231_IOCTL_MAGIC, 2, int)
#define DS3231_IOCTL_WRITE_HOURS    _IOR(DS3231_IOCTL_MAGIC, 3, int)
#define DS3231_IOCTL_WRITE_DAY      _IOR(DS3231_IOCTL_MAGIC, 4, int)
#define DS3231_IOCTL_WRITE_DATE     _IOR(DS3231_IOCTL_MAGIC, 5, int)
#define DS3231_IOCTL_WRITE_MONTHS   _IOR(DS3231_IOCTL_MAGIC, 6, int)
#define DS3231_IOCTL_WRITE_YEARS    _IOR(DS3231_IOCTL_MAGIC, 7, int)

#define DS3231_IOCTL_READ_SECONDS   _IOR(DS3231_IOCTL_MAGIC, 8, int)
#define DS3231_IOCTL_READ_MINUTES   _IOR(DS3231_IOCTL_MAGIC, 9, int)
#define DS3231_IOCTL_READ_HOURS     _IOR(DS3231_IOCTL_MAGIC, 10, int)
#define DS3231_IOCTL_READ_DAY       _IOR(DS3231_IOCTL_MAGIC, 11, int)
#define DS3231_IOCTL_READ_DATE      _IOR(DS3231_IOCTL_MAGIC, 12, int)
#define DS3231_IOCTL_READ_MONTHS    _IOR(DS3231_IOCTL_MAGIC, 13, int)
#define DS3231_IOCTL_READ_YEARS     _IOR(DS3231_IOCTL_MAGIC, 14, int)

#define HR_FORMAT_24 0
#define HR_FORMAT_12_AM 1
#define HR_FORMAT_12_PM 2

enum Day{
    Sunday = 1,
    Monday = 2,
    Tuesday = 3,
    Wednesday = 4,
    Thursday = 5,
    Friday = 6,
    Saturday = 7
};

int setTime(int fd, uint8_t sec, uint8_t min, uint8_t hour, uint8_t day, uint8_t date, uint8_t mon, uint8_t year, uint8_t format);
int getTime(int fd, uint8_t* data);

#endif