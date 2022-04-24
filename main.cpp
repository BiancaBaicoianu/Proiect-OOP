#include <iostream>
#include <string>
#include <vector>

class User {
    std::string name;
    std::string email;
    int age{};
    std::string phoneNo;
    std::string passportNo;

    friend std::ostream& operator<<(std::ostream &strm, const User &user);

public:
    [[nodiscard]] std::string getPassportNo() const {
        return passportNo;
    }
    [[nodiscard]] std::string getPhoneNo() const {
        return phoneNo;
    }

    User()= default;
    //constructor de initializare
    User(const std::string& name, const std::string& email, int age, const std::string& phoneNo, const std::string& passportNo) {
        this->name = name;
        this->email = email;
        this->age = age;
        this->phoneNo = phoneNo;
        this->passportNo = passportNo;
    }

    //metoda
    void verify_user() const{
        if ((*this).getPassportNo().size() < 9)
            std::cout << "You entered an invalid passport number for " << (*this) << std::endl;
        if ((*this).getPhoneNo().size() != 10)
            std::cout << "You entered an invalid phone number for " <<(*this) << std::endl;
    }

    //constructor de copiere
    User(const User &user) {
        this->name = user.name;
        this->email = user.email;
        this->age = user.age;
        this->phoneNo = user.phoneNo;
        this->passportNo = user.passportNo;
    }
    //destructor
    ~User() = default;

    //operator =
    User& operator=(const User& user)
    {
        this->name = user.name;
        this->email = user.email;
        this->age = user.age;
        this->phoneNo = user.phoneNo;
        this->passportNo = user.passportNo;
        std::cout << "Operator= \n";
        return *this;
    }
};

//operator <<
std::ostream& operator<<(std::ostream &strm, const User &user) {
    return strm << "(" << user.name << ", " << user.email << ", " << user.age << ", " << user.phoneNo << ", " << user.passportNo << ")";
}

class FlightSeat {
private:
    int id;
    int type;
    bool booked;

    friend std::ostream& operator<<(std::ostream &strm, const FlightSeat &flightSeat);

public:
    //constructor de initializare
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


    //metoda
    int bookSeat(const User& pasager_) {
        if (booked)
            return -1;
        this->booked = true;
        this->pasager = pasager_;
        return 0;
    }
    //operator =
    FlightSeat& operator=(const FlightSeat& seat)
    = default;

    User pasager;
};
//operator <<
std::ostream& operator<<(std::ostream &strm, const FlightSeat &flightseat) {
    return strm << "(" << flightseat.type << ", " << flightseat.booked << ", " << flightseat.pasager << ")";
}

class Flight {
private:
    int flightId;
    std::string departure;
    std::string destination;
    std::string planeType;
    int duration;
    std::vector<FlightSeat> seats;
    int noSeats;
    friend std::ostream& operator<<(std::ostream &strm, const Flight &flight);

public:
    //constructor de initializare
    Flight(int flightId, const std::string& departure, const std::string& destination, const std::string& planeType, int duration, const std::vector<FlightSeat>& seats, int noSeats) {
        this->flightId = flightId;
        this->departure = departure;
        this->destination = destination;
        this->planeType = planeType;
        this->duration = duration;
        this->seats = seats;
        this->noSeats = noSeats;
    }
    //constructor de copiere
    Flight(const Flight &flight) {
        this->flightId = flight.flightId;
        this->departure = flight.departure;
        this->destination = flight.destination;
        this->planeType = flight.planeType;
        this->duration = flight.duration;
        this->seats = flight.seats;
        this->noSeats = flight.noSeats;
    }
    //destructor
    ~Flight() = default;

    //operator =
    Flight& operator=(const Flight& flight)
    = default;
};
//operator <<
std::ostream& operator<<(std::ostream &strm, const Flight &flight) {
    strm << "Flight = (" << flight.departure << ", " << flight.destination << ", " << flight.planeType << ", " << flight.duration << ", Seats = {";

    for (const FlightSeat& seat : flight.seats) {
        strm << seat << ",";
    }
    strm << "})";
    return strm;
}

class ReservationSystem {
private:
    std::vector<Flight> flights;
    std::vector<User> users;
    friend std::ostream& operator<<(std::ostream &strm, const ReservationSystem &reserv);

public:
    //constructor de initializare
    ReservationSystem() = default;
    //constructor de copiere
    ReservationSystem(const ReservationSystem &system) {
        this->flights = system.flights;
        this->users = system.users;
    }
    //operator =
    ReservationSystem& operator=(const ReservationSystem& system)
    = default;

    //destructor
    ~ReservationSystem() = default;

    //metoda adaugare user
    void addUser(const User& user) {
        users.push_back(user);
    }
    //metoda adaugare zbor
    void addFlight(const Flight& flight) {
        flights.push_back(flight);
    }
};

//operator <<
std::ostream& operator<<(std::ostream &strm, const ReservationSystem &reserv) {
    strm << "Flights: ";
    for (const Flight& flight : reserv.flights) {
        strm << flight << std::endl;
    }
    strm << "User: ";
    for (const User& user : reserv.users) {
        strm << user << std::endl;
    }
    return strm;
}

ReservationSystem reservation;
std::vector<FlightSeat> flightSeats;


void booking(FlightSeat fs, const Flight& f) {
    if (fs.bookSeat(fs.pasager) == -1) {
        std::cout << "You have already booked a seat!";
    }
    else {
        flightSeats.push_back(fs);
        reservation.addFlight(f);
        reservation.addUser(fs.pasager);
    }
}

    int main() {
        User user1("Popescu Ion", "popescuion@gmail.com", 32, "0724660071", "006376162");
        user1.verify_user();
        Flight f1(0, "SUA", "Australia", "business", 240, flightSeats, 200);

        User user2("Andronescu Maria Elena", "mariaaaa_elena@yahoo.com", 22, "0726315643", "0031764");
        user2.verify_user();
        Flight f2(2, "Germany", "Russia", "business", 180, flightSeats, 260);

        User user3("Marinescu Rebeca", "rebek_marinescu@gmail.com", 28, "07632032242", "0031249626");
        user3.verify_user();
        Flight f3(0, "SUA", "Australia", "economy", 240, flightSeats, 200);

        FlightSeat fs1(012, 1, false, user1);
        booking(fs1, f1);

        FlightSeat fs2(276, 0, false, user2);
        booking(fs2, f2);

        FlightSeat fs3(012, 1, true, user3);
        booking(fs3, f3);

        std::cout << reservation << std::endl;
    }
