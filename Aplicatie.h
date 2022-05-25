
#ifndef OOP_APLICATIE_H
#define OOP_APLICATIE_H

#include <vector>
#include "Flight.h"
#include "ReservationSystem.h"

class Aplicatie{
private:
    ReservationSystem reservation{};
    std::vector<FlightSeat> flightSeats{};

public:
    Aplicatie() = default;

    [[nodiscard]] ReservationSystem &getReservation() {
        return reservation;
    };
    [[nodiscard]]  std::vector<FlightSeat> getFlightSeats() {
        return flightSeats;
    };

    void booking(FlightSeat fs, const Flight& f);
};

#endif //OOP_APLICATIE_H
