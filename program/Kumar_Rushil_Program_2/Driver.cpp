#include "Time.h"
#include "Song.h"
#include "Radio.h"
#include "MaxHeap.h"
#include "LinkedList.h"
#include "Hash.h"

int main(){
    // Time time = Time("23:59:59");
    // Time time1 = Time("00:00:01");
    // Time time2 = Time("12:00:00");
    
    // time2.day = 2;
    // time = time + time1;
    // std::cout << "Adding 23:59:59 and 00:00:01" << std::endl;
    // std::cout << time.stringTime() << std::endl;
    // std::cout << "Difference in seconds between 12:00:00 and new time" << std::endl;
    // std::cout << (time2 - time).getSeconds() << std::endl;

    // Song song = Song("We’re Going to be Friends, The White Stripes, 2:27");
    // std::cout << "Printing song" << std::endl;
    // std::cout << song.stringSong() << std::endl;
    // std::cout << "------ Radio test ------" << std::endl;
    // std::cout << "Starting Radio (try out RUN input.txt)" << std::endl;
    // Radio radio = Radio();
    // radio.runRadio();

    // MaxHeap heap = MaxHeap(10);
    // Time currentTime = Time("12:00:00");
    // std::cout << currentTime.stringTime() << std::endl;
    // Song song = Song("We’re Going to be Friends, The White Stripes, 2:27");
    // Song song2 = Song("Perfect Circle, R.E.M., 3:35");
    // song2.likeability = 1;
    // song2.lastPlayed = currentTime;
    // song.lastPlayed = currentTime;
    // heap.insert(song, &currentTime);
    // heap.insert(song2, &currentTime);
    // heap.insert(song, &currentTime);
    // std::cout << heap.stringHeap() << std::endl;

    Radio radio = Radio();
    radio.runRadio();

    // Time time = Time("12:00:00");
    // radio.songs.currentTime = time;
    // radio.songs.capacity = 100;


    // LinkedList list = LinkedList();
    // list.append(1);
    // list.append(9);
    // list.show();
    // Song song = Song("We’re Going to be Friends, The White Stripes, 2:27");
    // Song song2 = Song("Perfect Circle, R.E.M., 3:35");
    // Hash hash = Hash();
    // std::cout << hash.hashFunction(song) << std::endl;
    // std::cout << hash.hashFunction(song2) << std::endl;
    return 0;
}
