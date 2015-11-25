#include "Time.h"
#include "Song.h"
#include "Radio.h"

int main(){
    Time time = Time("23:59:59");
    Time time1 = Time("00:00:01");
    Time time2 = Time("12:00:00");
    
    time2.day = 2;
    time = time + time1;
    std::cout << "Adding 23:59:59 and 00:00:01" << std::endl;
    std::cout << time.stringTime() << std::endl;
    std::cout << "Difference in seconds between 12:00:00 and new time" << std::endl;
    std::cout << (time2 - time).getSeconds() << std::endl;

    Song song = Song("We’re Going to be Friends, The White Stripes, 2:27");
    std::cout << "Printing song" << std::endl;
    std::cout << song.stringSong() << std::endl;
    // Time time = Time("12:00:00");
    // Time songTime = Time("00:03:21");
    // Time other = Time("14:00:00");
    // time = time + songTime;    
    // std::cout << time.stringTime() << std::endl;
    // time = other - time;
    // std::cout << time.stringTime() << std::endl;
    // std::cout << time.getSeconds() << std::endl;
    // Song song = Song("Stayin’ Alive, The Bee Gees, 3:29");
    // Song other = song;
    // other = song;
    // std::cout << song.stringSong() << std::endl;
    // std::cout << other.stringSong() << std::endl;
    std::cout << "------ Radio test ------" << std::endl;
    std::cout << "Starting Radio (try out RUN input.txt)" << std::endl;
    Radio radio = Radio();
    radio.runRadio();
    return 0;
}
