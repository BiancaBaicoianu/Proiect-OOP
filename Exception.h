

#ifndef OOP_EXCEPTION_H
#define OOP_EXCEPTION_H

class AgeException: public std::runtime_error{
public:
    explicit AgeException(const std::string& name): std::runtime_error("Access denied. You should be at least 16 years, " + name + ". Exiting..."){}
};

class PassportException: public std::runtime_error{
public:
    explicit PassportException(const std::string& name): std::runtime_error("You entered an invalid passport number, " + name + ". Exiting..."){}
};

class PhoneNumberException: public std::runtime_error{
public:
    explicit PhoneNumberException(const std::string& name): std::runtime_error("You entered an invalid phone number, " + name + ". Exiting..."){}
};

#endif //OOP_EXCEPTION_H
