
#ifndef OOP_FLIGHT_H
#define OOP_FLIGHT_H

//#pragma once
#include "FlightSeat.h"
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

    //constructor de initializare
    Flight(int flightId, const std::string& departure, const std::string& destination, int duration, const std::vector<FlightSeat>& seats, int noSeats);

    //constructor de copiere
    Flight(const Flight &flight);

    friend void swap(Flight& f1, Flight& f2){
        std::swap(f1.destination, f2.departure);
    };

    std::vector<std::shared_ptr<Flight>>flights;

    friend void swap2(Flight& f1, Flight& f2){
        std::swap(f1.flights, f2.flights);
    };

    //operator =
    Flight& operator=(const Flight & other) {
        auto copie{other};
        swap(copie, *this);
        return *this;
    }
};

#endif //OOP_FLIGHT_H
