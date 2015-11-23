#include "Time.h"

int main(){
    Time time = Time("12:00:00");
    std::cout << time.stringTime() << std::endl;
    std::cout << time.addTime("00:05:01") << std::endl;
    std::cout << time.addTime("24:05:59") << std::endl;
    return 0;
}
