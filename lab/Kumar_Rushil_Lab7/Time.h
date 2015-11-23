#include <iostream>
#include <string>

class Time{     
 public:
    int hours;
    int minutes;
    int seconds;
    int day;
    Time(int hours, int minutes, int seconds);
    Time(std::string initTime);    
    std::string addTime(std::string addTime);
    std::string addTime(int hours, int minutes, int seconds);
    std::string stringTime();
};
