#include <iostream>
#include <string>
#include <vector>
#include "User.h"
#include "Flight.h"
#include "FlightSeat.h"
#include "ReservationSystem.h"
#include "FlightSeatType.h"
#include "Aplicatie.h"
#include "Exception.h"

//operator <<
std::ostream& operator<<(std::ostream &strm, const User &user) {
    return strm << "(" << user.name << ", " << user.email << ", " << user.age << ", " << user.phoneNo << ", " << user.passportNo << ")";
}

//operator <<
std::ostream& operator<<(std::ostream &strm, const FlightSeat &flightseat) {
    flightseat.afisare(strm);
    return strm;
}

//operator <<
std::ostream& operator<<(std::ostream &strm, const Flight &flight) {

    strm << "Flight = (" << flight.departure << ", " << flight.destination << ", " << flight.duration << ", Seats = {";

    for (const FlightSeat& seat : flight.seats) {
        strm << seat << ",";
    }
    strm << "})";
    return strm;
}

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

    int main() {
        Aplicatie app;

        User user1("Popescu Ion", "popescuion@gmail.com", 32, "0724660071", "006376162");
        User user2("Andronescu Maria Elena", "mariaaaa_elena@yahoo.com", 49, "0726315643", "0031764");
        User user3("Marinescu Rebeca", "rebek_marinescu@gmail.com", 28, "07632032242", "0031249626");
        User user4("Iordache Bianca Andreea", "bbiiaa_andreea@gmail.com", 19, "0763482242", "0031271234");
        User user5("Dobre Alexandru", "dobre.alexandru@gmail.com", 7, "0763203825", "000149766");
        User user6("Teodorescu Loredana", "lori_teodrsc@gmail.com", 25, "0703725242", "0800749626");
        User user7("Marin Sebastian", "sebastian.marin@gmail.com", 52, "0721203224", "9131282716");

        Flight f1(04263, "SUA", "Australia",  410, app.getFlightSeats(), 300);
        Flight f2(27473, "Germany", "Russia",  320, app.getFlightSeats(), 260);
        Flight f3(11343, "UK", "Austria", 240, app.getFlightSeats(), 180);
        Flight f4(42783, "Spain", "Sweden", 290, app.getFlightSeats(), 240);
        Flight f5(93894, "Italy", "Canada", 390, app.getFlightSeats(), 200);
        swap(f3,f5);
        swap2(f3,f5);

        if(user1.verify_user() == 0) {
            auto *fs1 = new FlightSeat(012, false, user1);
            try {
                if (fs1->pasager.getAge() >= 16) {
                    std::cout << "Access granted for " << fs1->pasager.getName() << std::endl;
                    app.booking(*fs1, f1);
                } else {
                    throw Exception();
                }
            }
            catch (Exception &exp) {
                std::cout << exp.what() << fs1->pasager.getName() << std::endl;
            }
            FirstClass *fc;
            fc = dynamic_cast<FirstClass *>(fs1);
            fc->message();  // NOLINT(readability-static-accessed-through-instance)
        }

        if(user2.verify_user() == 0) {
            Economy fs2(276, false, user2);
            try {
                if (fs2.pasager.getAge() >= 16) {
                    std::cout << "Access granted for " << fs2.pasager.getName() << std::endl;
                    app.booking(fs2, f2); // NOLINT(cppcoreguidelines-slicing)
                } else {
                    throw Exception();
                }
            }
            catch (Exception &exp) {
                std::cout << exp.what() << fs2.pasager.getName() << std::endl;
            }
        }

        if(user3.verify_user() == 0) {
            FirstClass fs3(012, true, user3);
            try {
                if (fs3.pasager.getAge() >= 16) {
                    std::cout << "Access granted for " << fs3.pasager.getName() << std::endl;
                    app.booking(fs3, f1); // NOLINT(cppcoreguidelines-slicing)
                } else {
                    throw Exception();
                }
            }
            catch (Exception &exp) {
                std::cout << exp.what() << fs3.pasager.getName() << std::endl;
            }
        }

        if(user4.verify_user() == 0) {
            Business fs4(012, false, user4);
            try {
                if (fs4.pasager.getAge() >= 16) {
                    std::cout << "Access granted for " << fs4.pasager.getName() << std::endl;
                    app.booking(fs4, f3); // NOLINT(cppcoreguidelines-slicing)
                } else {
                    throw Exception();
                }
            }
            catch (Exception &exp) {
                std::cout << exp.what() << fs4.pasager.getName() << std::endl;
            }
        }


        if(user5.verify_user() == 0) {
            Business fs5(012, false, user5);

            try {
                if (fs5.pasager.getAge() >= 16) {
                    std::cout << "Access granted for " << fs5.pasager.getName();
                    app.booking(fs5, f4); // NOLINT(cppcoreguidelines-slicing)
                } else {
                    throw Exception();
                }
            }
            catch (Exception &exp) {
                std::cout << exp.what() << fs5.pasager.getName() << std::endl;
            }

        }

        if(user6.verify_user() == 0) {
            FlightSeat fs6(012, false, user6);
            try {
                if (fs6.pasager.getAge() >= 16) {
                    std::cout << "Access granted for " << fs6.pasager.getName() << std::endl;
                    app.booking(fs6, f5);
                } else {
                    throw Exception();
                }
            }
            catch (Exception &exp) {
                std::cout << exp.what() << fs6.pasager.getName() << std::endl;
            }
        }

        if(user7.verify_user() == 0) {
            FlightSeat fs7(012, false, user7);
            try {
                if (fs7.pasager.getAge() >= 16) {
                    std::cout << "Access granted for " << fs7.pasager.getName() << std::endl;
                    app.booking(fs7, f3);
                } else {
                    throw Exception();
                }
            }
            catch (Exception &exp) {
                std::cout << exp.what() << fs7.pasager.getName() << std::endl;
            }
        }

        std::cout << app.getReservation() << std::endl;
    }
