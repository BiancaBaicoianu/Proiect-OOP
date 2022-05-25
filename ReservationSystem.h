
#ifndef OOP_RESERVATIONSYSTEM_H
#define OOP_RESERVATIONSYSTEM_H

#include "Flight.h"
#include "User.h"

class ReservationSystem {
private:
    std::vector<Flight> flights;
    std::vector<User> users;
    friend std::ostream& operator<<(std::ostream &strm, const ReservationSystem &reserv);

public:
    //constructor de initializare
    ReservationSystem() = default;

    //constructor de copiere
    [[maybe_unused]] [[maybe_unused]] ReservationSystem(const ReservationSystem &system);

    //operator =
    ReservationSystem& operator=(const ReservationSystem& system)
    = default;

    //destructor
    ~ReservationSystem() = default;

    //metoda adaugare user
    void addUser(const User& user);

    //metoda adaugare zbor
    void addFlight(const Flight& flight);
};

#endif //OOP_RESERVATIONSYSTEM_H
