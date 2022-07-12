#include <iostream>
#include <string>
//#include <vector>
#include "User.h"
#include "Flight.h"
#include "FlightSeat.h"
#include "ReservationSystem.h"
#include "FlightSeatType.h"
#include "Aplicatie.h"
#include "CoVidPolicy.h"
#include "AirlineCompany.h"
#include "Payment.h"
//#include "Exception.h"

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
    std::cout<<"_____________________FLIGHTS________________________"<<std::endl;
    for (const Flight& flight : reserv.flights) {
        strm << flight << std::endl;
    }
    std::cout<<"_______________________USERS________________________"<<std::endl;
    for (const User& user : reserv.users) {
        strm << user << std::endl;
    }
    return strm;
}


int main() {
    Aplicatie app;

    try {
        std::cout<<"____________________________COMPANIES_______________"<<std::endl;
        ChooseCompany chs_company{};
        WizzAirBuilder wizz;
        RyanAirBuilder ryan;
        BlueAirBuilder blue;
        FlyDubaiBuilder fly_dubai;

        chs_company.chooseAirlineComapny(&wizz);
        chs_company.openAirlineCompany();
        chs_company.chooseAirlineComapny(&ryan);
        chs_company.openAirlineCompany();
        chs_company.chooseAirlineComapny(&blue);
        chs_company.openAirlineCompany();
        chs_company.chooseAirlineComapny(&fly_dubai);
        chs_company.openAirlineCompany();
        std::cout<<"____________________________________________________"<<std::endl;

        User user1("Popescu Ion", "popescuion@gmail.com", 32, "0724660071", "006376162");
        User user2("Andronescu Maria Elena", "mariaaaa_elena@yahoo.com", 49, "0726315643", "002231764");
        User user3("Marinescu Rebeca", "rebek_marinescu@gmail.com", 28, "0763203224", "003124962");
        User user4("Iordache Bianca Andreea", "bbiiaa_andreea@gmail.com", 19, "0763482242", "003127123");
        User user5("Dobre Alexandru", "dobre.alexandru@gmail.com", 70, "0763203825", "000149766");
        User user6("Teodorescu Loredana", "lori_teodrsc@gmail.com", 25, "0703725242", "080074962");

        Flight f1(04263, "SUA", "Australia",  410, app.getFlightSeats(), 300);
        Flight f2(27473, "Germany", "Russia",  320, app.getFlightSeats(), 260);
        Flight f3(11343, "UK", "Austria", 240, app.getFlightSeats(), 180);
        Flight f4(42783, "Spain", "Sweden", 290, app.getFlightSeats(), 240);
        Flight f5(93894, "Italy", "Canada", 390, app.getFlightSeats(), 200);
        swap(f3,f5);

        //FS 1
        FlightSeat fs1(012, false, user1);
        //TEMPLATE
        CoVidPolicy<bool> R1(false);
        R1.setRestrictions(f1.getDestination());
        std::cout<< R1.isRestrictions();
        app.booking(fs1, f1);

        //FS2
        Economy fs2(276, false, user2);
        //TEMPLATE
        CoVidPolicy<bool> R2(false);
        R1.setRestrictions(f2.getDestination());
        std::cout<< R2.isRestrictions();
        app.booking(fs2, f2); // NOLINT(cppcoreguidelines-slicing)

        //FS3
        FirstClass fs3(013, false, user3);
        FirstClass::message();
        app.booking(fs3, f1); // NOLINT(cppcoreguidelines-slicing)

        //FS4
        Business fs4(014, false, user4);
        Business::message();
        app.booking(fs4, f3); // NOLINT(cppcoreguidelines-slicing)

        //FS5
        Business fs5(015, false, user5);
        app.booking(fs5, f4); // NOLINT(cppcoreguidelines-slicing)

        //FS6
        FlightSeat fs6(016, false, user6);
        app.booking(fs6, f5);

        std::cout << app.getReservation() << std::endl;


        User user7("Marin Sebastian", "sebastian.marin@gmail.com", 52, "0721203224", "91312871");
        User user8("Marin Gigel", "sebastian.gigel@gmail.com", 58, "072103224", "913132871");


    } catch (std::runtime_error &e) {
        std::cout<<"_____________________REJECTED USERS_________________"<<std::endl;
        std::cout << e.what() << std::endl;
    }


    Facade facade("EA21984284782", "ron", 320);
    facade.start();
}
