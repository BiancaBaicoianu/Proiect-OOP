#include "ReservationSystem.h"

void ReservationSystem::addFlight(const Flight &flight) {
    flights.push_back(flight);
}

void ReservationSystem::addUser(const User &user) {
    users.push_back(user);
}

[[maybe_unused]] ReservationSystem::ReservationSystem(const ReservationSystem &system) {
    this->flights = system.flights;
    this->users = system.users;
}