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
    Time operator+(const Time& other);
    Time operator-(const Time& other);
    //Adding time alters number of days
    std::string addTime(int hours, int minutes, int seconds);
    std::string stringTime();
};

#endif
