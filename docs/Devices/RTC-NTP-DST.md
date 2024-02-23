# NTP, RTC.h, DST, time.h

Internal system time is based on the standard Unix time_t. The value is the number of seconds since Jan 1, 1970. System time begins at zero when the device starts.

## Different Libraries

## DS1307RTC.h and DS3231.h

allow for easy functions to communicate with those special boards.

### RTC.h

[RTC.h](https://github.com/cvmanjoo/RTC) Library for I2C based RTCs (DS1307, DS3231, PCF8563) and Enables the functionality for clock reading, clock setting, alarms and timers of I2C RTCs.

### TimeLib.h NOT Time.h

[TimeLib.h](https://github.com/PaulStoffregen/Time) library adds timekeeping functionality to Arduino with or without external timekeeping hardware. It allows a sketch to get the time and date as: second, minute, hour, day, month and year. It also provides time as a standard C time_t so elapsed times can be easily calculated and time values shared across different platforms.

### Timezone.h

Timezone.h facilitate time zone conversions and automatic daylight saving (summer) time adjustments.
The primary aim of the Timezone library is to convert Universal Coordinated Time (UTC) to the correct local time, whether it is daylight saving time (a.k.a. summer time) or standard time.

## Pre-defined Functions in time.h

| Function Name | Explanation | Example |
|---- | ----| ----|
| asctime() | This function returns the date and time in the format  day month date hours:minutes:seconds year.| Eg: Sat Jul 27 11:26:03 2019.|
| asctime() | This function returns a string by taking struct tm variable as a parameter.| - |
| clock() | This function returns the processor time consumed by a program| - |
| ctime() | This function returns the date and time in the format day month date hours:minutes:seconds year| Eg: Sat Jul 27 11:26:03 2019 time is printed based on the pointer returned by Calendar Time |
| difftime() | This function returns the difference between the times provided | - |
| gmtime() | This function prints the UTC (Coordinated Universal Time) Time and date. Format for both gmtime() and asctime() is same| Eg: Sat Jul 27 11:26:03 2019.|
| mktime() | This function returns the calendar-time equivalent using struct tm.| - |
| time() | This function returns the calendar-time equivalent using data-type time_t.| - |
| strftime() | This function helps to format the string returned by other time functions using different format specifiers| - |

## configTime()

configTime() function and pass three arguments inside it. The arguments will be the GMT offset, the daylight offset and the NTP server respectively. All of these three values were already defined by us.

```c++
configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
```

!! getLocaltime()
getLocaltime() function to transfer our request to the NTP server and analyze the time stamp which will be received in a human-readable format. Notice that we are passing the time structure as a parameter inside this function. By accessing the members of this time structure (timeinfo) we will acquire the current date and time which we will print on our serial monitor.

The table shows the specifiers which we can use to access a particular configuration of the date/time.

```c++
getLocalTime(&timeinfo)
Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
```

| Specifier | Description | Example |
| --- | --- | --- |
| %A | Full weekday name | Saturday |
| %a | Abbreviated weekday name | Sat |
| %B | Full month name | January |
| %b or %h | Abbreviated month name | Jan |
| %D | Short MM/DD/YY date | 09/12/07 |
| %d | Day of the month (01-31) | 12 |
| %F | Short YYYY-MM-DD date | 2007-09-12 |
| %H | The hour in 24-hour format (00-23) | 13 |
| %I | The hour in 12-hour format (01-12) | 08 |
| %j | Day of the year (001-366) | 78 |
| %Y | Year | 2021 |
| %y | Last two digits of the year (00-99) | 21 |
| %m | Month as a decimal number (01-12) | 02 |
| %M | Minute (00-59) | 12 |
| %p | AM or PM | AM |
| %r | 12-hour clock time | 05:12:32 am |
| %R | 24-hour time HH: MM | 13:22 |
| %S | Second (00-59) | 32 |
| %T | Time format HH: MM: SS | 09:12:01 |

## Using RTC and NTP

```c++
// RTC Items
WiFiUDP Udp; // A UDP instance to let us send and receive packets over UDP
NTPClient timeClient(Udp);

RTCTime currentTime;
/// #define TIME_HEADER "T " // Header tag for serial time sync message
unsigned long updateTime = 0;
void setup() {
  ...
  // initialize RTC module with computer time
  RTC.begin();
  RTC.setHourMode(CLOCK_H24);
  Serial.println("Starting connection to NTP server...");
  timeClient.begin();
  timeClient.update();

  // Get the current date and time from an NTP server and convert it to UTC TIME_ZONE_OFFSET (config.h) by passing the time zone offset in hours.
  auto timeZoneOffsetHours = TIME_ZONE_OFFSET;
  auto unixTime = timeClient.getEpochTime() + (timeZoneOffsetHours * 3600); // get unixTime with TIME_ZONE_OFFSET
  Serial.print("Unix time = ");
  Serial.println(unixTime);
  RTCTime timeToSet = RTCTime(unixTime);
  RTC.setTime(timeToSet);
  // Retrieve the date and time from the RTC and print them
  RTCTime currentTime;
  RTC.getTime(currentTime);
  Serial.println("The RTC was just set to: " + String(currentTime));
 ....
}
```
