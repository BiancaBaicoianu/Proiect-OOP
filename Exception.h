

#ifndef OOP_EXCEPTION_H
#define OOP_EXCEPTION_H

class Exception: public std::runtime_error{
public:
    Exception(): std::runtime_error("Access denied. You should be at least 16 years, "){}
};

#endif //OOP_EXCEPTION_H
