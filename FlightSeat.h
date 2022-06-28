
#ifndef OOP_FLIGHTSEAT_H
#define OOP_FLIGHTSEAT_H

//#pragma once
#include "User.h"
#include <ostream>

class FlightSeat {
private:
    int id;
    bool booked;
    User pasager;
    friend std::ostream& operator<<(std::ostream &strm, const FlightSeat &flightSeat);

public:
    virtual void afisare(std::ostream &strm) const;
//    int bookSeat(const User &pasager_);
    [[nodiscard]] bool isBooked() const;
    User& getPasager();


    //constructor de initializare
    FlightSeat(int id, bool booked, const User& pasager);

    FlightSeat(const FlightSeat &seat);

    ~FlightSeat() = default;

    //operator =
    FlightSeat& operator=(const FlightSeat& seat)
    = default;
};

#endif //OOP_FLIGHTSEAT_H
