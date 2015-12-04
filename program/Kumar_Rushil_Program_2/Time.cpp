#include "Time.h"

Time::Time(){
    // std::cout << "Time Default Constructor" << std::endl;
    hours = 0;
    minutes = 0;
    seconds = 0;
    day = 0;
}

Time::Time(const Time& other){
    // std::cout << "Time Copy constructor" << std::endl;
    hours = other.hours;
    minutes = other.minutes;
    seconds = other.seconds;
    day = other.day;
}

Time& Time::operator=(const Time& other){
    // std::cout << "Time Assignment operator" << std::endl;
    hours = other.hours;
    minutes = other.minutes;
    seconds = other.seconds;
    day = other.day;
    return *this;
}

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

Time Time::operator+(const Time& other){
    Time t = Time(*this);
    t.addTime(other.hours, other.minutes, other.seconds);
    return t;
}

Time Time::operator-(const Time& other){
    Time t = Time(*this);
    t.seconds = t.seconds - other.seconds;
    if(t.seconds < 0){
	t.seconds = 60 + t.seconds;
	t.minutes = t.minutes - 1;
    }
    t.minutes = t.minutes - other.minutes;
    if(t.minutes < 0){
	t.minutes = 60 + t.minutes;
	t.hours = t.hours - 1;
    }
    t.hours = t.hours - other.hours;
    if(t.hours < 0){
	t.hours = 24 + t.hours;
	t.day = t.day - 1;
    }
    t.day = t.day - other.day;    
    return t;
}

int Time::getSeconds(){
    int val = 0;
    val = val + day * 24 * 60 * 60;
    val = val + hours * 60 * 60;
    val = val + minutes * 60;
    val = val + seconds;
    return val;
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
    std::string str_hours = "";
    std::string str_minutes = std::to_string(minutes);
    std::string str_seconds = std::to_string(seconds);
    std::string str_day = std::to_string(day);
    std::string end = "";
    if(hours == 0){
	str_hours = "12";
	end = "AM";
    }
    if(hours == 12){
	str_hours = "12";
	end = "PM";
    }
    if(hours > 12 && hours < 24){
	str_hours = std::to_string(hours - 12);
	end = "PM";
    }
    if(hours > 0 && hours < 12){
	str_hours = std::to_string(hours);
	end = "AM";
    }
    if(str_hours.length() == 1){
	str_hours = "0" + str_hours;
    }
    if(str_seconds.length() == 1){
	str_seconds = "0" + str_seconds;
    }
    if(str_minutes.length() == 1){
	str_minutes = "0" + str_minutes;
    }
    
    return "[Day " + str_day + ": " + str_hours + ":" + str_minutes + ":" + str_seconds + end + "]";
}



