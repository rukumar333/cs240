#include <iostream>

void overWriteAccount(std::string &lastName, std::string &firstName, int &age, int &streetNumber, std::string &streetName, std::string &town, std::string &zipCode, float &balance);
void updateAccount(std::string &lastName, std::string &firstName, int &age, int &streetNumber, std::string &streetName, std::string &town, std::string &zipCode, float &balance);
void viewAccount(const std::string &lastName, const std::string &firstName, const int &age, const int &streetNumber, const std::string &streetName, const std::string &town, const std::string &zipCode, const float &balance);
void depositMoney(float &balance);
void withdrawMoney(float &balance);
void displayBalance(const float &balance, const std::string &lastName);


