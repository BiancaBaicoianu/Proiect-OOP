
#ifndef OOP_USER_H
#define OOP_USER_H

//#pragma once
#include <string>

class User {
    std::string name;
    std::string email;
    int age{};
    std::string phoneNo;
    std::string passportNo;

    friend std::ostream& operator<<(std::ostream &strm, const User &user);

public:
    User();


    [[nodiscard]] const std::string &getName() const;
//    [[nodiscard]] const std::string &getPassportNo() const;
//    [[nodiscard]] const std::string &getPhoneNo() const;
//    [[nodiscard]] const int & getAge() const;


    //constructor de initializare
    User(const std::string& name, const std::string& email, int age, const std::string& phoneNr, const std::string& passportNr);

    //constructor de copiere
    User(const User &user) ;

    //destructor
    ~User() = default;


    //operator =
    User& operator=(const User& user);

};
#endif //OOP_USER_H