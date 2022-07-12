#ifndef OOP_AIRLINECOMPANY_H
#define OOP_AIRLINECOMPANY_H

#include <string>
#include <iostream>
#include <memory>

//DESIGN PATTERN -----> BUILDER
class AirlineCompany{
private:
    std::string airline_name;
    int luggage_weight{};
public:
    void setAirlineName(const std::string &airlineName);

    void setLuggageWeight(int luggageWeight);

    void open() const;

};

class AirlineCompanyBuilder{
protected:
    std::unique_ptr<AirlineCompany> AirlineCmp;
public:
    virtual ~AirlineCompanyBuilder() = default;

    AirlineCompany* getAirlineCompany();

    void IntroduceNewCompany();

    virtual void buildAirlineName() = 0;
    virtual void buildAirlineLuggage() = 0;
};

class WizzAirBuilder: public AirlineCompanyBuilder{
public:
    ~WizzAirBuilder() override = default;

    void buildAirlineName() override;
    void buildAirlineLuggage() override;
};

class RyanAirBuilder: public AirlineCompanyBuilder{
public:
    ~RyanAirBuilder() override = default;

    void buildAirlineName() override;
    void buildAirlineLuggage() override;
};

class BlueAirBuilder: public AirlineCompanyBuilder{
public:
    ~BlueAirBuilder() override = default;

    void buildAirlineName() override;
    void buildAirlineLuggage() override;
};

class FlyDubaiBuilder: public AirlineCompanyBuilder{
public:
    ~FlyDubaiBuilder() override = default;

    void buildAirlineName() override;
    void buildAirlineLuggage() override;
};

class ChooseCompany{
private:
    AirlineCompanyBuilder* AirlineCmpBuilder;
public:
    void openAirlineCompany();

    void chooseAirlineComapny(AirlineCompanyBuilder *airline_cmp_bld);
};

#endif //OOP_AIRLINECOMPANY_H
