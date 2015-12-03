#include "Radio.h"

Radio::Radio(){
    currentTime = Time();
    endSongs = 0;
}

Radio::~Radio(){
    std::cout << "Destructor for radio" << std::endl;
    delete[] songs;
}

bool Radio::runRadio(){
    bool keepRunning = true;
    std::string input = "";
    while(keepRunning){
	std::getline(std::cin, input);
	keepRunning = runCommand(input);
    }
    return false;
}

int Radio::runFile(std::string fileName){
    std::ifstream file(fileName);
    std::string input = "";
    bool result = false;
    while(std::getline(file, input)){
	result = runCommand(input);
	if(!result){
	    return 0;
	}
    }
    return 1;
}

void Radio::init(std::string initInfo){
    std::string partInfo = "";
    for(unsigned int i = 0; i < initInfo.length(); ++ i){
	if(initInfo[i] == ' '){	    	    
	    currentTime = Time(partInfo);
	    partInfo = "";	    
	}else{
	    partInfo = partInfo + initInfo[i];
	}
    }
    std::cout << "Max songs: " << partInfo << std::endl;
    std::cout << "Start time: " << currentTime.stringTime() << std::endl;
    songs = new Song[std::stoi(partInfo)];
}

void Radio::play(std::string numSongs){
    int number = std::stoi(numSongs);
    std::cout << "Playing " << number << " songs" << std::endl;
}

bool Radio::like(std::string song){
    std::cout << "Liking " << song << std::endl;    
    return true;
}

bool Radio::dislike(std::string song){
    std::cout << "Disliking " << song << std::endl;    
    return true;
}

bool Radio::addSong(std::string songInfo){
    *(songs + endSongs) = Song(songInfo);
    std::cout << "Added " << (songs + endSongs)->stringSong() << std::endl;
    ++ endSongs;
    return true;
}

void Radio::rest(std::string time){
    Time restTime = Time(time);
    currentTime = currentTime + restTime;
    std::cout << "Rested. Current time: " << currentTime.stringTime() << std::endl;
}

bool Radio::runCommand(std::string input){
    std::string command = "";
    unsigned int i = 0;
    for(i = 0; i < input.length() && input[i] != ' '; ++ i){
	command = command + input[i];
    }
    ++ i;
    std::string restStr = "";
    if(i < input.length()){
	restStr = input.substr(i);	
    }
    if(command == "QUIT"){
	return false;
    }
    if(command == "INIT"){
	init(restStr);
	return true;
    }
    if(command == "ADD"){
	addSong(restStr);
	return true;
    }
    if(command == "RUN"){
	int result = 0;
	result = runFile(restStr);
	if(result == 0){
	    return false;
	}else{
	    return true;
	}
    }
    if(command == "REST"){
	rest(restStr);
	return true;
    }
    if(command == "PLAY"){
	play(restStr);
	return true;
    }
    if(command == "LIKE"){
	like(restStr);
	return true;
    }
    if(command == "DISLIKE"){
	dislike(restStr);
	return true;
    }
    return false;
}


