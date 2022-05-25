#include "FlightSeatType.h"


void FirstClass::message() {
        std::cout<< "If you choose assistence during boarding process, this action could include an extra fee!" << std::endl << "People with disabilities will benefit from these services without paying extra"<< std::endl;
}

void FirstClass::afisare(std::ostream &strm) const {
        FlightSeat::afisare(strm);
    }
void Business::afisare(std::ostream &strm) const {
    FlightSeat::afisare(strm);
}
void Economy::afisare(std::ostream &strm) const {
    FlightSeat::afisare(strm);
}

//std::shared_ptr<FlightSeat> FirstClass::clone() const{
//    return std::make_shared <FirstClass>(*this);
//}

FirstClass::~FirstClass() = default;

std::shared_ptr<FlightSeat> Business::clone() const {
    return std::make_shared <Business>(*this);
}
std::shared_ptr<FlightSeat> BusinessPremium::clone() const {
    return Business::clone();
}
//std::shared_ptr<FlightSeat> Economy::clone() const{
//    return std::make_shared<Economy>(*this);
//}


