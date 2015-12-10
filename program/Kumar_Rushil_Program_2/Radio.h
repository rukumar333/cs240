#ifndef Radio_H
#define Radio_H
#include <iostream>
#include <fstream>
#include "Time.h"
#include "Song.h"
#include "MaxHeap.h"

class Radio{
 public:
    MaxHeap songs;
    Time currentTime;
    std::string lastPlayedTitle;
    Radio();
    ~Radio();
    void init(std::string initInfo);
    int runFile(std::string fileName);
    bool runRadio();
    bool runCommand(std::string command);
    bool addSong(std::string songInfo);
    void play(std::string numSongs);
    void like(std::string song);
    void dislike(std::string song);
    void rest(std::string time);
};

#endif
