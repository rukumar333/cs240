#include "LinkedList.h"
#include "Graph.h"
#include <fstream>

int main(int argc, char *argv[]){
    if(argc == 1){
	std::cout << "No input file specified" << std::endl;
	return 1;
    }
    Graph graph = Graph();
    int i = 0;
    std::string fileName = "";
    while(*((argv)[1] + i) != '\0'){
    	fileName = fileName + *((argv)[1] + i);
    	++ i;
    }
    std::ifstream file(fileName);
    std::string input = "";
    getline(file, input);
    int numCities = std::stoi(input);
    graph.setCapacity(numCities);
    for(unsigned int i = 0; i < numCities; ++ i){
    	getline(file, input);
    	graph.addVertex(input);
    }
    getline(file, input);
    int numRoutes = std::stoi(input);
    int spaceIndex = 0;
    for(unsigned int i = 0; i < numRoutes; ++ i){
    	getline(file, input);
	spaceIndex = input.find(" ");
	graph.addEdge(input.substr(0, spaceIndex), input.substr(spaceIndex + 1, std::string::npos));	
    }
    input = "";
    spaceIndex = 0;
    while(input != "QUIT"){
	getline(std::cin, input);
	if(input[0] == 'H'){
	    spaceIndex = input.find(" ");
	    std::string home = input.substr(spaceIndex + 1, std::string::npos);
	    std::cout << graph.BFS(home, home) << std::endl;
	}
	if(input[0] == 'T'){
	    spaceIndex = input.find(" ");
	    std::string tmp = input.substr(spaceIndex + 1, std::string::npos);
	    spaceIndex = tmp.find(" ");
	    std::string from = tmp.substr(0, spaceIndex);
	    std::string to = tmp.substr(spaceIndex + 1, std::string::npos);	    
	    std::cout << graph.BFS(from, to) << std::endl;
	}
    }
}
