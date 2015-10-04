#include <iostream>
#include "KumarRushilAccountFunctions.h"
#include <math.h>
using namespace std;

int main(int argc, char *argv[]){    
    string lastName;
    string firstName;
    int age;
    int streetNumber;
    string streetName;
    string town;
    string zipCode;
    float balance;
    // boolean exitProgram = false;
    bool keepLooping = true;
    while(keepLooping){
	string input = "";
	cout << "Enter a command: [New, View, Update, Deposit, Withdraw, Balance, Quit]\n";
	cin >> input;
	if(input == "New"){
	    overWriteAccount(lastName, firstName, age, streetNumber, streetName, town, zipCode, balance);
	}
	if(input == "View"){
	    viewAccount(lastName, firstName, age, streetNumber, streetName, town, zipCode, balance);
	}
	if(input == "Update"){
	    updateAccount(lastName, firstName, age, streetNumber, streetName, town, zipCode, balance);
	}
	if(input == "Deposit"){
	    depositMoney(balance);
	}
	if(input == "Withdraw"){
	    withdrawMoney(balance);
	}
	if(input == "Balance"){
	    displayBalance(balance, lastName);
	}
	if(input == "Quit"){
	    keepLooping = false;
	    cout << "Quitting";
	}
    }
}
