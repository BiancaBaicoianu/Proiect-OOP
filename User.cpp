
#include <string>
#include <iostream>
#include "User.h"


    User::User()= default;

    const std::string &User::getName() const {
        return name;
    }
    const std::string &User::getPassportNo() const{
        return passportNo;
    }
    const std::string &User::getPhoneNo() const{
        return phoneNo;
    }
    const int &User::getAge() const {
        return age;
    }

int User::verify_user() const {
    int valid = 0;
    if ((*this).getPassportNo().size() < 9){
        std::cout << "You entered an invalid passport number for " << (*this) << std::endl;
        valid = 1;
    }
    if ((*this).getPhoneNo().size() != 10) {
        std::cout << "You entered an invalid phone number for " << (*this) << std::endl;
        valid = 1;
    }
    return valid;
}


User::User(const User &user) {
    this->name = user.name;
    this->email = user.email;
    this->age = user.age;
    this->phoneNo = user.phoneNo;
    this->passportNo = user.passportNo;
}


User &User::operator=(const User &user) {
    this->name = user.name;
    this->email = user.email;
    this->age = user.age;
    this->phoneNo = user.phoneNo;
    this->passportNo = user.passportNo;
    std::cout << " ";
    return *this;
}


User::User(const std::string &name, const std::string &email, int age, const std::string &phoneNr,
           const std::string &passportNr) {
    this->name = name;
    this->email = email;
    this->age = age;
    this->phoneNo = phoneNr;
    this->passportNo = passportNr;
}
