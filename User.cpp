
#include <string>
#include <iostream>
#include "User.h"
#include "Exception.h"

User::User()= default;

const std::string &User::getName() const {
    return name;
}
//const std::string &User::getPassportNo() const{
//    return passportNo;
//}
//const std::string &User::getPhoneNo() const{
//    return phoneNo;
//}
//const int &User::getAge() const {
//    return age;
//}

//cc
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
    if (age < 16)
        throw AgeException(name);

    if (passportNr.size() < 9)
        throw PassportException(name);

    if (phoneNr.size() != 10)
        throw PhoneNumberException(name);

    this->name = name;
    this->email = email;
    this->age = age;
    this->phoneNo = phoneNr;
    this->passportNo = passportNr;
}

