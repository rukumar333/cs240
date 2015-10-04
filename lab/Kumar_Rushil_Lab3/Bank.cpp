#include "./Bank.h"
#include <stdio.h>
#include <ctype.h>

Bank::Bank(const int& arrayLength){
    this->arrayLength = arrayLength;
    lastPos = 0;
    customerArray = new Customer[arrayLength];    
}

Bank::Bank(const int& arrayLength, const std::string& fileName){
    this->arrayLength = arrayLength;
    lastPos = 0;
    customerArray = new Customer[arrayLength];
    loadContentsFromFile(fileName);
}

bool Bank::hasOnlyLetters(std::string input){
    if(input == ""){
	return false;
    }
    for(std::string::iterator it = input.begin(); it != input.end(); it ++){
	if(!isalpha(*it)){
	    return false;
	}
    }
    return true;
}

bool Bank::hasOnlyNumLetters(std::string input){
    if(input == ""){
	return false;
    }
    for(std::string::iterator it = input.begin(); it != input.end(); it ++){
	if(!isalnum(*it)){
	    return false;
	}
    }
    return true;
}

bool Bank::hasOnlyNums(std::string input){
    if(input == ""){
	return false;
    }
    for(std::string::iterator it = input.begin(); it != input.end(); it ++){
	if(!std::isdigit(*it)){
	    return false;
	}
    }
    return true;
}

bool Bank::checkPassword(std::string pass){
    if(pass == ""){
	return false;
    }
    bool hasNonLetter = false;
    for(std::string::iterator it = pass.begin(); it != pass.end(); it ++){
	if(!isalpha(*it)){
	    hasNonLetter = true;
	}
	if(!isprint(*it)){
	    return false;
	}
    }
    if(hasNonLetter){
	return true;
    }else{
	return false;
    }
}

bool Bank::checkState(std::string input){
    if(input == "NY" || input == "PA" || input == "CT" || input == "RI" || input == "ME" || input == "MA" || input == "NH" || input == "NY" || input == "VT"){
	return true;
    }else{
	return false;
    }
}

bool Bank::createAccount(){
    customerArray[lastPos] = Customer();
    std::string lastName, firstName, userID, password, streetName, town, state, zipCode, confirmPass;
    std::string sStreetNum, sAge;
    int age, streetNumber;

    std::cout << "First Name: ";
    std::getline(std::cin, firstName);
    if(!hasOnlyLetters(firstName)){
	std::cout << "Please enter a valid name next time." << std::endl;
	return false;
    }

    std::cout << "Last Name: ";
    std::getline(std::cin, lastName);
    if(!hasOnlyLetters(lastName)){
	std::cout << "Please enter a valid name next time." << std::endl;
	return false;
    }

    std::cout << "Age: ";
    std::getline(std::cin, sAge);
    if(!hasOnlyNums(sAge)){
	std::cout << "Please enter a valid age next time." << std::endl;
	return false;
    }    
    age = std::stoi(sAge, nullptr);
    if(age < 12){
	std::cout << "Sorry too young. Try later!" << std::endl;
	return false;
    }

    std::cout << "Street Number: ";
    std::getline(std::cin, sStreetNum);
    if(!hasOnlyNums(sStreetNum)){
	std::cout << "Please enter a valid street number next time." << std::endl;
	return false;
    }    
    streetNumber = std::stoi(sStreetNum, nullptr);
    if(streetNumber < 0){
	std::cout << "Please enter a valid street number next time." << std::endl;
	return false;	
    }

    std::cout << "Street Name: ";
    std::getline(std::cin, streetName);
    if(streetName == ""){
	std::cout << "Please enter a valid street name next time." << std::endl;
	return false;		
    }

    std::cout << "Town: ";
    std::getline(std::cin, town);
    if(town == ""){
	std::cout << "Please enter a valid town next time." << std::endl;
	return false;		
    }

    std::cout << "State: ";
    std::getline(std::cin, state);
    if(!checkState(state)){
	std::cout << "Please enter a valid state next time." << std::endl;
	return false;
    }

    std::cout << "Zip Code: ";
    std::getline(std::cin, zipCode);
    if(zipCode.length() != 5){
	std::cout << "Please enter a valid zip code next time." << std::endl;
	return false;
    }
    
    bool idExists = false;
    std::cout << "Create a user ID: ";
    std::getline(std::cin, userID);
    if(!hasOnlyNumLetters(userID) || userID.length() < 5 || userID.length() > 10){
	std::cout << "Please enter a valid user id next time." << std::endl;
	return false;	
    }
    for(int i = 0; i < lastPos; i ++){
	if(customerArray[i].getUserID() == userID){
	    idExists = true;
	}
    }
    while(idExists){
	idExists = false;
	std::cout << "User ID already exists! Please enter another." << std::endl;
	std::cout << "Create a user ID: ";
	std::getline(std::cin, userID);
	if(!hasOnlyNumLetters(userID) || userID.length() < 5 || userID.length() > 10){
	    std::cout << "Please enter a valid user id next time." << std::endl;
	    return false;	
	}
	for(int i = 0; i < lastPos; i ++){
	    if(customerArray[i].getUserID() == userID){
		idExists = true;
	    }
	}
    }
    
    std::cout << "Create a password: ";
    std::getline(std::cin, password);
    if(password.length() < 6 || !checkPassword(password)){
	std::cout << "Please enter a valid password next time." << std::endl;
	return false;		
    }    

    std::cout << "Retype password to confirm: ";
    std::getline(std::cin, confirmPass);
    while(password != confirmPass){
	std::cout << "Incorrect password." << std::endl;
	std::cout << "Create a password: ";
	std::getline(std::cin, password);
	std::cout << "Retype password to confirm: ";
	std::getline(std::cin, confirmPass);
    }

    customerArray[lastPos].setFirstName(firstName);
    customerArray[lastPos].setLastName(lastName);
    customerArray[lastPos].setAge(age);
    customerArray[lastPos].setStreetNumber(streetNumber);
    customerArray[lastPos].setStreetName(streetName);
    customerArray[lastPos].setTown(town);
    customerArray[lastPos].setState(state);
    customerArray[lastPos].setZipCode(zipCode);
    customerArray[lastPos].setUserID(userID);
    customerArray[lastPos].setPassword(password);
    lastPos ++;
    return true;
}

bool Bank::updateAccount(){
    std::string lastName, firstName, streetName, town, state, zipCode, confirmPass;
    std::string sStreetNum, sAge;
    int age = 0;
    int streetNumber = 0;
    std::cout << std::endl;
    std::cout << "Please update the following fields. If you do not wish to update, then just leave field empty and hit enter." << std::endl;

    std::cout << "First Name: ";
    std::getline(std::cin, firstName);
    if(!hasOnlyLetters(firstName) && firstName != ""){
	std::cout << "Please enter a valid name next time." << std::endl;
	return false;
    }

    std::cout << "Last Name: ";
    std::getline(std::cin, lastName);
    if(!hasOnlyLetters(lastName) && lastName != ""){
	std::cout << "Please enter a valid name next time." << std::endl;
	return false;
    }

    std::cout << "Age: ";
    std::getline(std::cin, sAge);
    if(!hasOnlyNums(sAge) && sAge != ""){
	std::cout << "Please enter a valid age next time." << std::endl;
	return false;
    }
    if(sAge != ""){
	age = std::stoi(sAge, nullptr);	
    }
    if(age < 12){
	std::cout << "Sorry too young. Try later!" << std::endl;
	return false;
    }

    std::cout << "Street Number: ";
    std::getline(std::cin, sStreetNum);
    if(!hasOnlyNums(sStreetNum) && sStreetNum != ""){
	std::cout << "Please enter a valid street number next time." << std::endl;
	return false;
    }    
    if(sStreetNum != ""){
	streetNumber = std::stoi(sStreetNum, nullptr);	
    }
    if(streetNumber < 0){
	std::cout << "Please enter a valid street number next time." << std::endl;
	return false;	
    }

    std::cout << "Street Name: ";
    std::getline(std::cin, streetName);
    if(streetName == ""){
	std::cout << "Please enter a valid street name next time." << std::endl;
	return false;		
    }

    std::cout << "Town: ";
    std::getline(std::cin, town);
    if(town == ""){
	std::cout << "Please enter a valid town next time." << std::endl;
	return false;		
    }

    std::cout << "State: ";
    std::getline(std::cin, state);
    if(!checkState(state)){
	std::cout << "Please enter a valid state next time." << std::endl;
	return false;
    }

    std::cout << "Zip Code: ";
    std::getline(std::cin, zipCode);
    if(zipCode.length() != 5){
	std::cout << "Please enter a valid zip code next time." << std::endl;
	return false;
    }

    if(firstName != ""){
	(*currentCustomer).setFirstName(firstName);	
    }
    if(lastName != ""){
	(*currentCustomer).setLastName(lastName);
    }
    if(age != 0){
	(*currentCustomer).setAge(age);	
    }
    if(streetNumber != 0){
	(*currentCustomer).setStreetNumber(streetNumber);
    }
    if(streetName != ""){
	(*currentCustomer).setStreetName(streetName);	
    }
    if(town != ""){
	(*currentCustomer).setTown(town);	
    }
    if(state != ""){
	(*currentCustomer).setState(state);	
    }
    if(zipCode != ""){
	(*currentCustomer).setZipCode(zipCode);	
    }
    return true;
}

void Bank::saveBank(){
    std::string file;
    std::cout << "Enter the name of the file you wish to save to: ";
    std::getline(std::cin, file);
    std::ifstream checkFile(file);
    if(checkFile.good()){
	checkFile.close();
	std::string overWrite;
	std::cout << file << " already exists. Do you wish to overwrite its contents? [Yes/No]: ";
	std::getline(std::cin, overWrite);
	if(overWrite == "Yes"){
	    writeContentsToFile(file);
	    std::cout << "Saved!" << std::endl;
	}
	if(overWrite == "No"){
	    std::cout << "Chose another file." << std::endl;
	    saveBank();
	}
	if(overWrite != "No" && overWrite != "Yes"){
	    std::cout << "Answer could not be interpreted." << std::endl;
	    saveBank();
	}
    }else{
	checkFile.close();
	writeContentsToFile(file);
	std::cout << "Saved!" << std::endl;
    }
}

void Bank::writeContentsToFile(const std::string& file){
    std::ofstream outputFile(file);
    for(int i = 0; i < lastPos; i ++){
        outputFile << customerArray[i].getFirstName() << "\n";
	outputFile << customerArray[i].getLastName() << "\n";
	outputFile << customerArray[i].getAge() << "\n";
	outputFile << customerArray[i].getStreetNumber() << "\n";
	outputFile << customerArray[i].getStreetName() << "\n";
	outputFile << customerArray[i].getTown() << "\n";
	outputFile << customerArray[i].getState() << "\n";
	outputFile << customerArray[i].getZipCode() << "\n";
	outputFile << customerArray[i].getUserID() << "\n";
	outputFile << customerArray[i].getPassword() << "\n";
	outputFile << std::fixed << std::setprecision(2) << customerArray[i].getBalance() << "\n";	
    }
}

void Bank::loadContentsFromFile(const std::string& file){
    std::ifstream inputFile(file);
    int lineNum = 0;
    std::string line;
    if(inputFile.good()){
	lastPos = 0;
	bool tooMany = false;
	while(std::getline(inputFile, line) && !tooMany){
	    if(lastPos == arrayLength){
		tooMany = true;
	    }else{	       
		++lineNum;
		if(lineNum == 1){
		    customerArray[lastPos] = Customer();
		    customerArray[lastPos].setFirstName(line);
		}
		if(lineNum == 2){
		    customerArray[lastPos].setLastName(line);
		}
		if(lineNum == 3){
		    int ageSet = std::stoi(line);
		    customerArray[lastPos].setAge(ageSet);
		}
		if(lineNum == 4){
		    int numSet = std::stoi(line);
		    customerArray[lastPos].setStreetNumber(numSet);
		}
		if(lineNum == 5){
		    customerArray[lastPos].setStreetName(line);
		}
		if(lineNum == 6){
		    customerArray[lastPos].setTown(line);
		}
		if(lineNum == 7){
		    customerArray[lastPos].setState(line);
		}
		if(lineNum == 8){
		    customerArray[lastPos].setZipCode(line);		
		}
		if(lineNum == 9){
		    customerArray[lastPos].setUserID(line);
		}
		if(lineNum == 10){
		    customerArray[lastPos].setPassword(line);
		}
		if(lineNum == 11){
		    float balanceSet = std::stof(line);
		    customerArray[lastPos].setBalance(balanceSet);
		    lineNum = 0;
		    ++lastPos;
		}
	    }
	}
	inputFile.close();
	if(!tooMany){
	    std::cout << "File loaded!" << std::endl;   
	}else{
	    std::cout << "Number of customers exceeds limit of customers. Try loading another file." << std::endl;
	    lastPos = 0;
	}
    }else{
	inputFile.close();
	std::cout << "File does not exist." << std::endl;
    }
}

void Bank::loadBank(){
    std::string file;
    std::cout << "Enter the name of the file you wish to load: ";
    std::getline(std::cin, file);
    loadContentsFromFile(file);
}

bool Bank::login(){
    std::string pass, id;
    std::cout << "Enter userid: ";
    std::getline(std::cin, id);
    std::cout << "Enter password: ";    
    std::getline(std::cin, pass);
    for(int i = 0; i < lastPos; ++i){
	std::string customerPass = customerArray[i].getPassword();
	std::string customerID = customerArray[i].getUserID();
	if(id == customerID && pass == customerPass){
	    std::cout << "Successfully logged in!" << std::endl;
	    currentCustomer = customerArray + i;
	    return true;
	}
    }
    std::cout << "Login information was incorrect." << std::endl;
    return false;
}

bool Bank::firstMenu(){
    std::string input;
    std::cout << "Please enter one of the follow commands: " << std::endl;
    std::cout << "[New, Login, Save, Load, Quit]" << std::endl;
    std::cout << "> ";
    std::getline(std::cin, input);
    if(input == "New"){
	if(lastPos == arrayLength){
	    std::cout << "Cannot add another account. You have reached the max quantity of accounts." << std::endl;
	    return true;
	}
	createAccount();
	return true;
    }
    if(input == "Login"){
	bool loggedIn = login();
	if(loggedIn){
	    while(secondMenu()){};
	}
	return true;
    }
    if(input == "Save"){
	saveBank();
	return true;
    }
    if(input == "Load"){
        loadBank();
	return true;
    }
    if(input == "Quit"){
	std::string answer;
	std::cout << "Would you like to save data? [Yes/No]: ";
	std::getline(std::cin, answer);
	if(answer == "Yes"){
	    saveBank();
	    std::cout << "Exiting!" << std::endl;
	    return false;
	}
	if(answer == "No"){
	    std::cout << "Exiting!" << std::endl;
	    return false;
	}
	if(answer != "Yes" && answer != "No"){
	    std::cout << "Answer could not be interpreted." << std::endl;
	    return true;
	}
    }
    return true;
}

bool Bank::secondMenu(){
    std::string input;
    std::cout << std::endl;
    std::cout << "User: " << (*currentCustomer).getUserID() << std::endl;
    std::cout << "Name: " << (*currentCustomer).getFirstName() + " " + (*currentCustomer).getLastName() << std::endl;
    std::cout << "Please enter one of the follow commands: " << std::endl;
    std::cout << "[Update, Passwd, View, Deposit, Withdraw, Balance, Logout]" << std::endl;
    std::cout << "> ";
    std::getline(std::cin, input);
    if(input == "Update"){
	updateAccount();
	return true;
    }
    if(input == "Balance"){
	std::cout << (*currentCustomer).getLastName() + " $" << std::fixed << std::setprecision(2) << (*currentCustomer).getBalance() << std::endl;
	return true;
    }
    if(input == "Passwd"){
	std::string firstPass, secondPass;
	std::cout << "Please enter a new password: ";
	std::getline(std::cin, firstPass);
	if(firstPass.length() < 6 || !checkPassword(firstPass)){
	    std::cout << "Please enter a valid password next time." << std::endl;
	}else{
	    std::cout << "Please reenter the password to confirm: ";	
	    std::getline(std::cin, secondPass);
	    if(firstPass == secondPass){
		std::cout << "Password changed!" << std::endl;
		(*currentCustomer).setPassword(firstPass);
		return true;
	    }else{
		std::cout << "Passwords do not match." << std::endl;
		return true;
	    }   
	}
    }
    if(input == "View"){
	std::cout << "User ID: " << (*currentCustomer).getUserID() << std::endl;
	std::cout << "Balance: $" << std::fixed << std::setprecision(2) << (*currentCustomer).getBalance() << std::endl;
	std::cout << "Name: " << (*currentCustomer).getFirstName() + " " + (*currentCustomer).getLastName() << std::endl;
	std::cout << "Age: " << (*currentCustomer).getAge() << std::endl;
	std::cout << "Address: " << (*currentCustomer).getStreetNumber() << " " + (*currentCustomer).getStreetName() << ", " + (*currentCustomer).getTown() << ", " + (*currentCustomer).getState() << " " + (*currentCustomer).getZipCode() << std::endl;	
	return true;
    }
    if(input == "Deposit"){
	std::cout << "Enter amount to deposit: ";
	std::string sMoney;
	std::getline(std::cin, sMoney);
	float money = std::stof(sMoney);
	while(money < 0){
	    std::cout << "Please enter an amount that is not negative: ";
	    std::getline(std::cin, sMoney);
	    money = std::stof(sMoney);
	}
	float currentBalance = (*currentCustomer).depositBalance(money);
	std::cout << "New Balance: $" << std::fixed << std::setprecision(2) << currentBalance << std::endl;
	return true;
    }
    if(input == "Withdraw"){
	std::cout << "Enter amount to deposit: ";
	std::string sMoney;
	std::getline(std::cin, sMoney);
	float money = std::stof(sMoney);
	while(money < 0){
	    std::cout << "Please enter an amount that is not negative: ";
	    std::getline(std::cin, sMoney);
	    money = std::stof(sMoney);
	}
	float currentBalance = (*currentCustomer).withdrawBalance(money);
	if(currentBalance < 0){
	    std::cout << "Not enough money for transaction. Transcation not completed." << std::endl;
	    return true;
	}else{
	    std::cout << "New Balance: $" << std::fixed << std::setprecision(2) << currentBalance << std::endl;
	    return true;
	}
    }
    if(input == "Logout"){
	std::cout << "Logging off!" << std::endl;
	return false;
    }
    return true;
}

Customer * Bank::getCustomerArray(){
    return customerArray;
}
