#include "Time.h"
#include "Song.h"

int main(){
    Time time = Time("12:00:00");
    Time songTime = Time("00:03:21");
    Time other = Time("14:00:00");
    time = time + songTime;    
    std::cout << time.stringTime() << std::endl;
    time = other - time;
    std::cout << time.stringTime() << std::endl;    
    // std::cout << time.stringTime() << std::endl;
    // std::cout << time.addTime("00:05:01") << std::endl;
    // std::cout << time.addTime("24:05:59") << std::endl;
    // std::cout << time.addTime("12:00:00") << std::endl;
    return 0;
}
