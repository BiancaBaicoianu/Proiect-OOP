#ifndef OOP_FLIGHTSEATTYPE_H
#define OOP_FLIGHTSEATTYPE_H

//#pragma once
#include "FlightSeat.h"
#include <memory>
#include <iostream>


class FirstClass: public FlightSeat{

protected:
    void afisare(std::ostream &strm) const override;

public:
    FirstClass(int id, bool booked, const User &pasager) : FlightSeat(id, booked, pasager){}
    ~FirstClass();
//    [[nodiscard]] virtual std::shared_ptr <FlightSeat> clone() const;
    static void message() ;
};


class Business: public FlightSeat{
protected:
    void afisare(std::ostream &strm) const override;

public:
    Business(int id, bool booked, const User &pasager) : FlightSeat(id, booked, pasager) {}

    virtual ~Business() = default;

    [[nodiscard]] virtual std:: shared_ptr <FlightSeat> clone() const ;

    static void message() ;
};


class [[maybe_unused]] BusinessPremium: public Business{

protected:
    void afisare(std::ostream &strm) const override = 0;

public:
    [[maybe_unused]] BusinessPremium(int id, bool booked, const User &pasager) : Business(id, booked, pasager) {}

    ~BusinessPremium() override = default;

    [[nodiscard]] std:: shared_ptr <FlightSeat> clone() const override ;
};


class Economy: public FlightSeat{
protected:
    void afisare(std::ostream &strm) const override;

public:
    Economy(int id, bool booked, const User &pasager) : FlightSeat(id, booked, pasager) {}

    ~Economy() = default;


};


#endif //OOP_FLIGHTSEATTYPE_H
