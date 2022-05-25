#include <iosfwd>
#include "FlightSeat.h"
#include "User.h"

void FlightSeat::afisare(std::ostream &strm) const {
    const auto& FlightSeat = *this;
    strm << "(" << FlightSeat.id << ", " << FlightSeat.booked << ", " << FlightSeat.pasager << ")";
}

int FlightSeat::bookSeat(const User &pasager_) {
    if (booked)
        return -1;
    this->booked = true;
    this->pasager = pasager_;
    return 0;
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