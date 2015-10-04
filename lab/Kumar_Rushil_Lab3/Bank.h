#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "./Customer.h"
class Bank{
    Customer * customerArray;
    Customer * currentCustomer;
    int arrayLength;
    int lastPos;
 public:
    Bank(const int& arrayLength);
    Bank(const int& arrayLength, const std::string& fileName);
    bool hasOnlyLetters(std::string input);
    bool hasOnlyNumLetters(std::string input);
    bool hasOnlyNums(std::string input);
    bool checkPassword(std::string pass);
    bool checkState(std::string input);
    bool firstMenu();
    bool secondMenu();
    bool login();
    bool createAccount();
    bool updateAccount();
    void saveBank();
    void loadBank();
    void writeContentsToFile(const std::string& file);
    void loadContentsFromFile(const std::string& file);
    Customer * getCustomerArray();
};
