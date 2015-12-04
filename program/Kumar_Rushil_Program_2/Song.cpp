#include "Song.h"

Song::Song(){
    // std::cout << "Song default constructor" << std::endl;
    priority = 0;
    likeability = 0;
    lastPlayed = Time();
    length = Time();
    title = "";
    artist = "";
}

Song::Song(const Song& other){
    // std::cout << "Song copy constructor" << std::endl;
    priority = other.priority;
    likeability = other.likeability;
    lastPlayed = other.lastPlayed;
    title = other.title;
    artist = other.artist;
    length = other.length;
}

Song& Song::operator=(const Song& other){
    // std::cout << "Song assignment operator" << std::endl;
    priority = other.priority;
    likeability = other.likeability;
    lastPlayed = other.lastPlayed;
    title = other.title;
    artist = other.artist;
    length = other.length;
    return *this;
}

Song::Song(std::string songInfo){
    int increment = 0;
    std::string partInfo = "";
    for(unsigned int i = 0; i < songInfo.length(); ++ i){
	if(songInfo[i] == ','){
	    switch(increment){
	    case 0:
		title = partInfo;
		break;
	    case 1:
		artist = partInfo;
		break;
	    }
	    ++ increment;
	    partInfo = "";
	    ++ i;
	}else{
	    partInfo = partInfo + songInfo[i];
	}
    }
    partInfo = "00:" + partInfo;
    length = Time(partInfo);
    priority = 0;
    likeability = 0;
    lastPlayed = Time();
}

int Song::getKey(Time * current){
    Time t = *current - lastPlayed;
    return t.getSeconds() + (1000 * likeability);
}

std::string Song::stringSong(){
    std::string val = "";
    val = val + title;
    val = val + " by " + artist;
    return val;
}
