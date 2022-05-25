#include "Flight.h"

Flight::Flight(const Flight &flight) {
    this->flightId = flight.flightId;
    this->departure = flight.departure;
    this->destination = flight.destination;
    this->duration = flight.duration;
    this->seats = flight.seats;
    this->noSeats = flight.noSeats;
}

Flight::Flight(int flightId, const std::string &departure, const std::string &destination, int duration,
               const std::vector<FlightSeat> &seats, int noSeats) {
    this->flightId = flightId;
    this->departure = departure;
    this->destination = destination;
    this->duration = duration;
    this->seats = seats;
    this->noSeats = noSeats;
}

