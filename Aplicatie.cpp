#include <iostream>
#include "Aplicatie.h"


void Aplicatie::booking(FlightSeat fs, const Flight& f) {
    if (fs.bookSeat(fs.pasager) == -1) {
        std::cout << "You have already booked a seat for " << fs.pasager.getName() << std::endl;
    }
    else {
        flightSeats.push_back(fs);
        reservation.addFlight(f);
        reservation.addUser(fs.pasager);
    }
}


