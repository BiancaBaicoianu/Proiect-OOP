
#ifndef OOP_FLIGHT_H
#define OOP_FLIGHT_H

//#pragma once
#include "FlightSeat.h"
#include "AirlineCompany.h"
#include <memory>
#include <vector>

class Flight {
private:
    int flightId;
    std::string departure;
    std::string destination;
    int duration;
    std::vector<FlightSeat> seats;
    int noSeats;

public:

    friend std::ostream& operator<<(std::ostream &strm, const Flight &flight);

    [[nodiscard]] const std::string &getDestination() const;

    //constructor de initializare
    Flight(int flightId, const std::string& departure, const std::string& destination, int duration, const std::vector<FlightSeat>& seats, int noSeats);

    //constructor de copiere
    Flight(const Flight &flight);

    ~Flight() = default;

    friend void swap(Flight& f1, Flight& f2){
        std::swap(f1.destination, f2.departure);
    };

    //operator =
    Flight& operator=(const Flight & other) {
        auto copie{other};
        swap(copie, *this);
        return *this;
    }
};


#endif //OOP_FLIGHT_H
