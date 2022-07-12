#include "Payment.h"

bool CheckData::CheckIBAN(std::string iban) {
    for(int i = 0; i < 10; i++){
        std::string prefix = reinterpret_cast<const char *>(iban[0] + toupper(iban[1]));
        if (country[i].starts_with(prefix )) {
            if (int(iban.size()) == ibanLength[i]) {
                std::cout << "IBAN correct!\n";
                return true;
            } else {
                std::cout << "IBAN incorrect!\n";
                return false;
            }
        }
    }
    return false;
}

float Transaction::Commission(float price) {
    float commission = float(0.3) * price;
    return commission;
}

void Transaction::Currency(const std::string &currency, float price) {
    for(int i = 0; i < 4; i++)
        if(currency == currencies[i]) {
            price += Commission(price);
            price *= values[i];
            std::cout << "Your final payment: " << price << currencies[i];
        }
}

void Facade::start() {
    if(checkdata_.CheckIBAN(iban)){
        transaction_.Currency(currency, price);
    }
}
