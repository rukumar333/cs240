#include "Time.h"

Time::Time(int hours, int minutes, int seconds){
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
    day = 1;
}

Time::Time(std::string initTime){
    int increment = 0;
    std::string partTime = "";
    for(unsigned int i = 0; i < initTime.length(); ++ i){
	if(initTime[i] == ':'){
	    switch(increment){
	    case 0:
		hours = std::stoi(partTime);
	    case 1:
		minutes = std::stoi(partTime);
	    }
	    ++ increment;
	    partTime = "";
	}else{
	    partTime = partTime + initTime[i];
	}
    }
    seconds = std::stoi(partTime);
    day = 1;
}

std::string Time::addTime(std::string timeAdd){
    int addHours = 0;
    int addMinutes = 0;
    int addSeconds = 0;
    int increment = 0;
    std::string partTime = "";
    for(unsigned int i = 0; i < timeAdd.length(); ++ i){
	if(timeAdd[i] == ':'){
	    switch(increment){
	    case 0:
		addHours = std::stoi(partTime);
	    case 1:
		addMinutes = std::stoi(partTime);
	    }
	    ++ increment;
	    partTime = "";
	}else{
	    partTime = partTime + timeAdd[i];
	}
    }
    addSeconds = std::stoi(partTime);
    return addTime(addHours, addMinutes, addSeconds);
}

std::string Time::addTime(int addHours, int addMinutes, int addSeconds){
    seconds = seconds + addSeconds;
    if(seconds >= 60){
	seconds = seconds - 60;
	++ addMinutes;
    }
    minutes = minutes + addMinutes;
    if(minutes >= 60){
	minutes = minutes - 60;
	++ addHours;
    }
    hours = hours + addHours;
    if(hours >= 24){
	hours = hours - 24;
	++ day;
    }
    return stringTime();
}

std::string Time::stringTime(){
    std::string str_hours = std::to_string(hours);
    std::string str_minutes = std::to_string(minutes);
    std::string str_seconds = std::to_string(seconds);
    std::string str_day = std::to_string(day);
    if(str_hours.length() == 1){
	str_hours = "0" + str_hours;
    }
    if(str_seconds.length() == 1){
	str_seconds = "0" + str_seconds;
    }
    if(str_minutes.length() == 1){
	str_minutes = "0" + str_minutes;
    }
    return "[Day " + str_day + ": " + str_hours + ":" + str_minutes + ":" + str_seconds + "]";
}



