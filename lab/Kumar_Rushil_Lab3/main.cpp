#include <string>
#include <iostream>
#include <sstream>
#include "./Bank.h"
int main(int argc, char **argv){    
    if(argc == 3){
	int arrayLength = std::stoi(argv[1]);
	std::string fileName = argv[2];
	Bank * bank = new Bank(arrayLength, fileName);
	while((*bank).firstMenu()){};
    }
    if(argc == 2){
	int arrayLength = std::stoi(argv[1]);
	Bank * bank = new Bank(arrayLength);
	while((*bank).firstMenu()){};
    }
    // Bank * bank = new Bank(100);
    // std::cout << arrayCus[0].getFirstName() << std::endl;
    // std::cout << arrayCus[0].getLastName() << std::endl;
    // std::cout << arrayCus[0].getAge() << std::endl;
    // std::cout << arrayCus[0].getStreetNumber() << std::endl;
    // std::cout << arrayCus[0].getStreetName() << std::endl;
    // std::cout << arrayCus[0].getTown() << std::endl;
    // std::cout << arrayCus[0].getState() << std::endl;
    // std::cout << arrayCus[0].getZipCode() << std::endl;
    // std::cout << arrayCus[0].getUserID() << std::endl;
    // std::cout << arrayCus[0].getPassword() << std::endl;

    // std::cout << arrayCus[1].getFirstName() << std::endl;
    // std::cout << arrayCus[1].getLastName() << std::endl;
    // std::cout << arrayCus[1].getAge() << std::endl;
    // std::cout << arrayCus[1].getStreetNumber() << std::endl;
    // std::cout << arrayCus[1].getStreetName() << std::endl;
    // std::cout << arrayCus[1].getTown() << std::endl;
    // std::cout << arrayCus[1].getState() << std::endl;
    // std::cout << arrayCus[1].getZipCode() << std::endl;
    // std::cout << arrayCus[1].getUserID() << std::endl;
    // std::cout << arrayCus[1].getPassword() << std::endl;
}
