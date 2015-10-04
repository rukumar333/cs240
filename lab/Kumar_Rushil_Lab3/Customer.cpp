#include "./Customer.h"

//Setting parameters
void Customer::setLastName(const std::string& lastName){
    this->lastName = lastName;
}
void Customer::setFirstName(const std::string& firstName){
    this->firstName = firstName;
}    
void Customer::setUserID(const std::string& userID){
    this->userID = userID;
}
void Customer::setPassword(const std::string& password){
    this->password = password;
}
void Customer::setStreetName(const std::string& streetName){
    this->streetName = streetName;
}
void Customer::setTown(const std::string& town){
    this->town = town;
}
void Customer::setState(const std::string& state){
    this->state = state;
}
void Customer::setZipCode(const std::string& zipCode){
    this->zipCode = zipCode;
}
void Customer::setAge(const int& age){
    this->age = age;
}
void Customer::setStreetNumber(const int& streetNumber){
    this->streetNumber = streetNumber;
}
void Customer::setBalance(const float& balance){
    this->balance = balance;
}

//Getting parameters
std::string Customer::getLastName(){
    return lastName;
}
std::string Customer::getFirstName(){
    return firstName;
}    
std::string Customer::getUserID(){
    return userID;
}
std::string Customer::getPassword(){
    return password;
}
std::string Customer::getStreetName(){
    return streetName;
}
std::string Customer::getTown(){
    return town;
}
std::string Customer::getState(){
    return state;
}
std::string Customer::getZipCode(){
    return zipCode;
}
int Customer::getAge(){
    return age;
}
int Customer::getStreetNumber(){
    return streetNumber;
}
float Customer::getBalance(){
    return balance;
}
float Customer::depositBalance(float money){
    balance = balance + money;
    return balance;
}
float Customer::withdrawBalance(float money){
    if(money > balance){
	return -1;
    }else{
	balance = balance - money;
	return balance;
    }
}
