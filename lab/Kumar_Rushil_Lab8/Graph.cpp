#include "Graph.h"

Graph::Graph(){
    vertices = nullptr;
    hashmap = std::unordered_map<std::string, int>();
}

Graph::~Graph(){
    delete[] vertices;
}

void Graph::setCapacity(int cap){
    capacity = cap;
    vertices = new LinkedList[cap];    
}

void Graph::addVertex(std::string city){
    hashmap[city] = length;
    (vertices + length)->startCity = city;
    ++ length;    
}

void Graph::addEdge(std::string from, std::string to){
    int fromPos = hashmap[from];
    int toPos = hashmap[to];
    (vertices + fromPos)->append(to, toPos);
}

void Graph::show(){
    for(unsigned int i = 0; i < capacity; ++ i){
	std::cout << "-- " << (vertices + i)->startCity << " --" << std::endl;
	(vertices + i)->show();
    }
}

std::string Graph::BFS(std::string from, std::string to){
    std::queue<int> Q = std::queue<int>();
    for(unsigned int i = 0; i < capacity; ++ i){
	(vertices + i)->color = 0;
	(vertices + i)->previous = nullptr;
    }    
    int startPos = hashmap[from];
    int endPos = -1;
    (vertices + startPos)->color = 1;
    (vertices + startPos)->previous = nullptr;
    Q.push(startPos);
    while(!Q.empty() && endPos == -1){
	int pos = Q.front();
	// std::cout << "City: " << (vertices + pos)->startCity << std::endl;
	Q.pop();
	LinkedList::Node * iterator = (vertices + pos)->head;
	while(iterator){
	    // std::cout << "Checking here: " << iterator->data << std::endl;
	    int vertPos = iterator->arrPos;
	    if(iterator->data == to){
		std::cout << "Found it" << std::endl;
		endPos = vertPos;
		(vertices + vertPos)->color = 1;
		(vertices + vertPos)->previous = vertices + pos;
	    }
	    if((vertices + vertPos)->color == 0){
		(vertices + vertPos)->color = 1;
		(vertices + vertPos)->previous = vertices + pos;
		Q.push(vertPos);
	    }
	    iterator = iterator->next;
	}
	(vertices + pos)->color = 2;
    }
    std::string result = "";
    LinkedList * it = (vertices + endPos);
    if(endPos == -1){
	return "No";
    }
    while(it){
	result = it->startCity + " " + result;
	it = it->previous;
	if(it == (vertices + endPos)){
	    result = it->startCity + " " + result;
	    it = nullptr;
	}
    }
    return result;
}
