#ifndef Song_H
#define Song_H
#include <iostream>
#include <string>
#include "Time.h"
class Song{
 public:
    int priority;
    int likeability;
    Time lastPlayed;
    Time length;
    std::string title;
    std::string artist;
    //Default constructor
    Song();
    //Copy constructor
    Song(const Song& other);
    //Assignment operator
    Song(std::string songInfo);
    Song& operator=(const Song& other);
    void like();
    void dislike();
    int getKey(Time * current);
    std::string stringSong();    
};
#endif
