#include "KumarRushilAccountFunctions.h"
#include <string>
#include <math.h>

using namespace std;

//New, View, Update, Deposit, Withdraw, Balance, Quit
void overWriteAccount(string &lastName, string &firstName, int &age, int &streetNumber, string &streetName, string &town, string &zipCode, float &balance){
    cout << "Last Name: ";
    cin >> lastName;
    cout << "First Name: ";
    cin >> firstName;    
    cout << "Age: ";
    cin >> age;
    cout << "Street Number: ";
    cin >> streetNumber;
    cout << "Street Name: ";
    cin >> streetName;
    cout << "Town: ";
    cin >> town;
    cout << "Zip Code: ";
    cin >> zipCode;
    cout << "Balance: ";
    cin >> balance;
  
    cout << "\nLast Name: " + lastName + "\n";
    cout << "First Name: " + firstName + "\n";
    cout << "Age: " + to_string(age) + "\n";
    cout << "Street Number: " + to_string(streetNumber) + "\n";
    cout << "Street Name: " + streetName + "\n";
    cout << "Town: " + town + "\n";
    cout << "Zip Code: " + zipCode + "\n";
    cout << "Balance: ";
    printf("%.2f", balance);
    cout << "\n";
}

void updateAccount(string &lastName, string &firstName, int &age, int &streetNumber, string &streetName, string &town, string &zipCode, float &balance){
    cout << "Last Name: ";
    cin >> lastName;
    cout << "First Name: ";
    cin >> firstName;    
    cout << "Age: ";
    cin >> age;
    cout << "Street Number: ";
    cin >> streetNumber;
    cout << "Street Name: ";
    cin >> streetName;
    cout << "Town: ";
    cin >> town;
    cout << "Zip Code: ";
    cin >> zipCode;
    cout << "Balance: ";
    cin >> balance;
    
    cout << "\nLast Name: " + lastName + "\n";
    cout << "First Name: " + firstName + "\n";
    cout << "Age: " + to_string(age) + "\n";
    cout << "Street Number: " + to_string(streetNumber) + "\n";
    cout << "Street Name: " + streetName + "\n";
    cout << "Town: " + town + "\n";
    cout << "Zip Code: " + zipCode + "\n";
    cout << "Balance: ";
    printf("%.2f", balance);
    cout << "\n";
}

void viewAccount(const std::string &lastName, const std::string &firstName, const int &age, const int &streetNumber, const std::string &streetName, const std::string &town, const std::string &zipCode, const float &balance){
    cout << "Last Name: " + lastName + "\n";
    cout << "First Name: " + firstName + "\n";
    cout << "Age: " + to_string(age) + "\n";
    cout << "Street Number: " + to_string(streetNumber) + "\n";
    cout << "Street Name: " + streetName + "\n";
    cout << "Town: " + town + "\n";
    cout << "Zip Code: " + zipCode + "\n";
    cout << "Balance: ";
    printf("%.2f", balance);
    cout << "\n";
}

void depositMoney(float &balance){
    float amount;
    cout << "Input Amount: ";
    cin >> amount;
    balance = balance + amount;
}

void withdrawMoney(float &balance){
    float amount;
    cout << "Input Amount: ";
    cin >> amount;
    balance = balance - amount;
    balance = roundf(balance);
}

void displayBalance(const float &balance, const string &lastName){    
    cout << lastName + "'s balance: ";
    printf("%.2f", balance);
    cout << "\n";
}

