
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class User {
private:
    string nume;
    string cnp;
    int varsta;

    friend std::ostream& operator<<(std::ostream &strm, const User &a);

public:
    User(){
    }
    //constructor de initializare
    User(const string& nume, const string& cnp, int varsta) {
        this->nume = nume;
        this->cnp = cnp;
        this->varsta = varsta;
    }
    //cconstructor de copiere
    User(const User &user) {
        this->nume = user.nume;
        this->cnp = user.cnp;
        this->varsta = user.varsta;
    }
    //destructor
    ~User() {
    }
    //operator =
    User& operator=(const User& user)
    {
        this->nume = user.nume;
        this->cnp = user.cnp;
        this->varsta = user.varsta;
        return *this;
    }

};
//operator <<
std::ostream& operator<<(std::ostream &strm, const User &a) {
    return strm << "(" << a.nume << ", " << a.cnp << ", " << a.varsta << ")";
}

class FlightSeat {
private:
    int id;
    int type;
    bool booked;
    User pasager;
    friend std::ostream& operator<<(std::ostream &strm, const FlightSeat &a);

public:
    FlightSeat(int id, int type, bool booked, const User& pasager) {
        this->id = id;
        this->type = type;
        this->booked = booked;
        this->pasager = pasager;
    }

    FlightSeat(const FlightSeat &seat) {
        this->type = seat.type;
        this->booked = seat.booked;
        this->pasager = seat.pasager;
        this->id = seat.id;
    }
    //constructor de initializare
    FlightSeat(int id, int type, bool booked) {
        this->id = id;
        this->type = type;
        this->booked = booked;
    }
    //destructor
    ~FlightSeat() {
    }
    //metoda
    int bookSeat(const User& pasanger_) {
        if (booked)
            return -1;
        this->booked = true;
        this->pasager = pasanger_;
        return 0;
    }
    //operator =
    FlightSeat& operator=(const FlightSeat& seat)
    {
        this->type = seat.type;
        this->booked = seat.booked;
        this->pasager = seat.pasager;
        this->id = seat.id;
        return *this;
    }
};
//operator <<
std::ostream& operator<<(std::ostream &strm, const FlightSeat &a) {
    return strm << "(" << a.type << ", " << a.booked << ", " << a.pasager << ")";
}

class Flight {
private:
    int flightId;
    std::string departure;
    std::string destination;
    int planeType;
    int duration;
    std::vector<FlightSeat> seats;
    friend std::ostream& operator<<(std::ostream &strm, const Flight &a);

public:
    //constructor de initializare
    Flight(int flightId, const string& departure, const string& destination, int planeType, int duration, const vector<FlightSeat>& seats) {
        this->flightId = flightId;
        this->departure = departure;
        this->destination = destination;
        this->planeType = planeType;
        this->duration = duration;
        this->seats = seats;
    }
    //constructor de copiere
    Flight(const Flight &flight) {
        this->flightId = flight.flightId;
        this->departure = flight.departure;
        this->destination = flight.destination;
        this->planeType = flight.planeType;
        this->duration = flight.duration;
        this->seats = flight.seats;
    }
    //destructor
    ~Flight() {
    }
    //operator =
    Flight& operator=(const Flight& flight)
    {
        this->flightId = flight.flightId;
        this->departure = flight.departure;
        this->destination = flight.destination;
        this->planeType = flight.planeType;
        this->duration = flight.duration;
        this->seats = flight.seats;
        return *this;
    }
};
//operator <<
std::ostream& operator<<(std::ostream &strm, const Flight &a) {
    strm << "Flight = (" << a.departure << ", " << a.destination << ", " << a.planeType << ", " << a.duration << ", Seats = {";

    for (FlightSeat seat : a.seats) {
        strm << seat << ",";
    }
    strm << "})";
    return strm;
}

class ReservationSystem {
private:
    std::vector<Flight> flights;
    std::vector<User> users;
    friend std::ostream& operator<<(std::ostream &strm, const ReservationSystem &a);

public:
    //constructor de initializare
    ReservationSystem() {
    }
    //constructor de copiere
    ReservationSystem(const ReservationSystem &system) {
        this->flights = system.flights;
        this->users = system.users;
    }
    //operator =
    ReservationSystem& operator=(const ReservationSystem& system)
    {
        this->flights = system.flights;
        this->users = system.users;
        return *this;
    }
    //destructor
    ~ReservationSystem() {
    }
    //metoda adaugare user
    void addUser(User user) {
        users.push_back(user);
    }
    //metoda adaugare zbor
    void addFlight(Flight flight) {
        flights.push_back(flight);
    }
};

//operator <<
std::ostream& operator<<(std::ostream &strm, const ReservationSystem &a) {
    strm << "Flights: ";
    for (Flight flight : a.flights) {
        strm << flight << endl;
    }
    strm << "User: ";
    for (User user : a.users) {
        strm << user << endl;
    }
    return strm;
}


int main() {
    ReservationSystem system;

    std::vector<FlightSeat> flightSeats;
    User adi("Adi", "123456789012", 32);
    FlightSeat fs1(0, 1, false, adi);
    flightSeats.push_back(fs1);
    Flight f1(0, "SUA", "Australia", 1, 240, flightSeats);

    system.addFlight(f1);
    system.addUser(adi);

    cout << system << endl;
}
