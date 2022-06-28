#include <iostream>
#include "Aplicatie.h"


void Aplicatie::booking(FlightSeat fs, const Flight& f) {
    if (fs.isBooked()) {
        std::cout << "You have already booked a seat for " << fs.getPasager().getName() << std::endl;
    }
    else {
        flightSeats.push_back(fs);
        reservation.addFlight(f);
        reservation.addUser(fs.getPasager());
    }
}



