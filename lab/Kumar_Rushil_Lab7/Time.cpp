#include "Time.h"

Time::Time(int hours, int minutes, int seconds){
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
}

Time::Time(std::string initTime){
    int increment = 0;
    std::string partTime = "";
    for(unsigned int i = 0; i < initTime.length(); ++ i){
	if(initTime[i] == ':'){
	    std::cout << "Part: " << partTime << std::endl;
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
}

void Time::show(){
    std::string str_hours = std::to_string(hours);
    std::string str_minutes = std::to_string(minutes);
    std::string str_seconds = std::to_string(seconds);
    if(str_hours.length() == 1){
	str_hours = "0" + str_hours;
    }
    if(str_seconds.length() == 1){
	str_seconds = "0" + str_seconds;
    }
    if(str_minutes.length() == 1){
	str_minutes = "0" + str_minutes;
    }
    std::cout << str_hours << ":" << str_minutes << ":" << str_seconds << std::endl;
}



