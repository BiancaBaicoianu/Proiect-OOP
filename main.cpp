#include <iostream>
#include <string>
#include <vector>

using namespace std;

class User {
    std::string name;
    std::string email;
    int age;
    std::string phoneNo;
    std::string passportNo;

    friend std::ostream& operator<<(std::ostream &strm, const User &a);

public:
    //functii prieten
    friend string return_passportNo(const User& user_);
    friend string return_phoneNo(const User& user_);

    User()= default;
    //constructor de initializare
    User(const string& name, const string& email, int age, const string& phoneNo, const string& passportNo) {
        this->name = name;
        this->email = email;
        this->age = age;
        this->phoneNo = phoneNo;
        this->passportNo = passportNo;
    }

    //metoda
    static void verify_user(const User& user_) {
        if (return_passportNo(user_).size() < 9)
            std::cout << "You entered an invalid passport number for " << user_ << endl;
        if (return_phoneNo(user_).size() != 10)
            std::cout << "You entered an invalid phone number for " << user_ << endl;
}

    //regula celor 3
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
        return *this;
    }

};

string return_passportNo(const User& user_){
    return user_.passportNo;
}
string return_phoneNo(const User& user_){
    return user_.phoneNo;
}

//operator <<
std::ostream& operator<<(std::ostream &strm, const User &a) {
    return strm << "(" << a.name << ", " << a.email << ", " << a.age << ", " << a.phoneNo << ", " << a.passportNo << ")";
}

class FlightSeat {
private:
    int id;
    int type;
    bool booked;
    User pasager;
    friend std::ostream& operator<<(std::ostream &strm, const FlightSeat &a);

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

    for (const FlightSeat& seat : a.seats) {
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
std::ostream& operator<<(std::ostream &strm, const ReservationSystem &a) {
    strm << "Flights: ";
    for (const Flight& flight : a.flights) {
        strm << flight << endl;
    }
    strm << "User: ";
    for (const User& user : a.users) {
        strm << user << endl;
    }
    return strm;
}


int main() {
    ReservationSystem system;
    //economy = 1 ; bussiness = 0
    std::vector<FlightSeat> flightSeats;
    User user1("Popescu Ion", "popescuion@gmail.com", 32, "0724660071", "006376162");
    User::verify_user(user1);
    User user2("Andronescu Maria Elena", "mariaaaa_elena@yahoo.com", 22, "0726315643", "0031764");
    User::verify_user(user2);
    User user3("Marinescu Rebeca", "rebek_marinescu@gmail.com", 28, "07632032242", "0031249626");
    User::verify_user(user3);

    FlightSeat fs1(012, 1, false, user1);
    if (fs1.bookSeat(user1) == -1)
        { std::cout << "You have already booked a seat!"; }
    else {
        flightSeats.push_back(fs1);
        Flight f1(0, "SUA", "Australia", 1, 240, flightSeats);
        system.addFlight(f1);
        system.addUser(user1);
    }

    FlightSeat fs2(276, 0, false, user2);
    if (fs2.bookSeat(user2) == -1)
        { std::cout << "You have already booked a seat at this flight!"; }
    else {
        flightSeats.push_back(fs2);
        Flight f2(2,"Germany", "Russia", 0, 180, flightSeats);
        system.addFlight(f2);
        system.addUser(user2);
    }

    FlightSeat fs3(012,1,true, user3);
    if (fs3.bookSeat(user3) == -1)
        { std::cout << "You have already booked a seat at this flight!"<<endl; }
    else {
        flightSeats.push_back(fs3);
        Flight f3(0, "SUA", "Australia", 1, 240, flightSeats);
        system.addFlight(f3);
        system.addUser(user3);
    }


    cout << system << endl;
}


