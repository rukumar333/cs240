#ifndef Time_H
#define Time_H
#include <iostream>
#include <string>

class Time{     
 public:
    int hours;
    int minutes;
    int seconds;
    int day;
    //Copy Constructor
    Time(const Time& other);
    //Assignment operator
    Time& operator=(const Time& other);
    //Constructors
    Time(int hours, int minutes, int seconds);
    Time(std::string initTime);
    //Overloaded operators
    //Does not check other.day since this will be used when songs are played
    Time operator+(const Time& other);
    //Checks other.day since this will be used for finding how long ago song was played.
    Time operator-(const Time& other);
    int getSeconds();
    //Adding time alters number of days
    std::string addTime(int hours, int minutes, int seconds);
    std::string stringTime();
};

#endif
