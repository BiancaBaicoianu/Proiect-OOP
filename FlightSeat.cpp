#include <iosfwd>
#include "FlightSeat.h"
#include "User.h"
//#include <iostream>
//#include <string>
#include <vector>

void FlightSeat::afisare(std::ostream &strm) const {
    const auto& FlightSeat = *this;
    strm << "(" << FlightSeat.id << ", " << FlightSeat.booked << ", " << FlightSeat.pasager << ")";
}

FlightSeat::FlightSeat(const FlightSeat &seat) {
    this->booked = seat.booked;
    this->pasager = seat.pasager;
    this->id = seat.id;
}

FlightSeat::FlightSeat(int id, bool booked, const User &pasager) {
    this->id = id;
    this->booked = booked;
    this->pasager = pasager;
}

bool FlightSeat::isBooked() const {
    return this->booked;
}

User& FlightSeat::getPasager() {
    return this->pasager;
}