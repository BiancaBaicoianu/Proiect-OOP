#ifndef OOP_PAYMENT_H
#define OOP_PAYMENT_H

#include <string>
#include <iostream>
#include <utility>


//DESIGN PATTERN -> FACADE
class CheckData{
private:
    std::string country[10]{"EAU", "Croatia", "Austria", "Danemarca", "Spain", "Belgia", "Germania", "Grecia", "Italia","Norvegia"};
    int ibanLength[10]{23, 21, 20, 18,24, 16, 22, 27, 27, 15 };
public:
    //presupunem ca IBAN-ul este format din primele 2 litere din nume tarii, apoi codul numeric unic
    bool CheckIBAN(std::string iban);
};

class Transaction{
private:
    std::string currencies[4]{ "pounds", "dolar", "ron", "dirham"};
    //conversia dintre currencies-urile oferite si euro(moneda in care este dat pretul initial)
    float values[4]{0.84, 1.00, 4.94, 3.69};
public:

    static float Commission(float price);

    void Currency(const std::string& currency, float price);
};

class Facade{
private:
    CheckData checkdata_;
    Transaction transaction_;
    std::string iban;
    std::string currency;
    float price{};
public:

    Facade(std::string iban, std::string currency, float price) : iban(std::move(iban)), currency(std::move(currency)), price(price) {}

    void start();

};



#endif //OOP_PAYMENT_H
