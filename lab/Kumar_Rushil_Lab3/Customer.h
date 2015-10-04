#include <string>
#include <math.h>

class Customer{
    std::string lastName, firstName, userID, password, streetName, town, state, zipCode;
    int age, streetNumber;
    float balance = 0;
 public:
    //Setting functions
    void setLastName(const std::string& lastName);
    void setFirstName(const std::string& firstName);    
    void setUserID(const std::string& userID);
    void setPassword(const std::string& password);
    void setStreetName(const std::string& streetName);
    void setTown(const std::string& town);
    void setState(const std::string& state);
    void setZipCode(const std::string& zipCode);
    void setAge(const int& age);
    void setStreetNumber(const int& streetNumber);
    void setBalance(const float& balance);    

    //Getting functions
    std::string getLastName();
    std::string getFirstName();
    std::string getUserID();
    std::string getPassword();
    std::string getStreetName();
    std::string getTown();
    std::string getState();
    std::string getZipCode();
    int getAge();
    int getStreetNumber();
    float getBalance();

    float depositBalance(float money);
    float withdrawBalance(float money);    
};
