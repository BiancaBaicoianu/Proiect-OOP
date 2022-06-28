#include "FlightSeatType.h"


void FirstClass::message() {
    std::cout<< "[First Class]If you choose assistence during boarding process, this action could include an extra fee!" << std::endl << "People with disabilities will benefit from these services without paying extra"<< std::endl;
}

void FirstClass::afisare(std::ostream &strm) const {
    strm << "[First Class Seat] ";
    FlightSeat::afisare(strm);
}

void Business::message() {
    std::cout<< "[Business Class] If you choose assistence during boarding process, this action could include an extra fee!" << std::endl;
}

void Business::afisare(std::ostream &strm) const {
    strm << "[Business Class Seat] ";
    FlightSeat::afisare(strm);
}
void Economy::afisare(std::ostream &strm) const {
    strm << "[Economy Class Seat] ";
    FlightSeat::afisare(strm);
}


FirstClass::~FirstClass() = default;

std::shared_ptr<FlightSeat> Business::clone() const {
    return std::make_shared <Business>(*this);
}
std::shared_ptr<FlightSeat> BusinessPremium::clone() const {
    return Business::clone();
}


