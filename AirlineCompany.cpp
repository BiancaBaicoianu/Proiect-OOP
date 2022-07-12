#include "AirlineCompany.h"


void AirlineCompany::setAirlineName(const std::string &airlineName) {
    airline_name = airlineName;
}

void AirlineCompany::setLuggageWeight(int luggageWeight) {
    luggage_weight = luggageWeight;
}

void AirlineCompany::open() const {
        std::cout<<"Airline Company: "<<airline_name<<std::endl;
        std::cout<<"Weight accepted for luggage: "<<luggage_weight<<"Kg"<<std::endl;
}

void AirlineCompanyBuilder::IntroduceNewCompany(){
        //smart pointer
        AirlineCmp = std::make_unique<AirlineCompany>();
}

AirlineCompany *AirlineCompanyBuilder::getAirlineCompany(){
        return AirlineCmp.get();
}

void WizzAirBuilder::buildAirlineName() {
    AirlineCmp->setAirlineName("Wizz Air");
}

void WizzAirBuilder::buildAirlineLuggage() {
    AirlineCmp->setLuggageWeight(10);
}

void RyanAirBuilder::buildAirlineName() {
    AirlineCmp->setAirlineName("Ryan Air");
}

void RyanAirBuilder::buildAirlineLuggage() {
    AirlineCmp->setLuggageWeight(15);
}

void BlueAirBuilder::buildAirlineName() {
    AirlineCmp->setAirlineName("Blue Air");
}

void BlueAirBuilder::buildAirlineLuggage() {
    AirlineCmp->setLuggageWeight(12);
}

void FlyDubaiBuilder::buildAirlineName() {
    AirlineCmp->setAirlineName("Fly Dubai");
}

void FlyDubaiBuilder::buildAirlineLuggage() {
    AirlineCmp->setLuggageWeight(20);
}

void ChooseCompany::openAirlineCompany() {
    AirlineCmpBuilder->getAirlineCompany()->open();
}

void ChooseCompany::chooseAirlineComapny(AirlineCompanyBuilder *airline_cmp_bld) {
        AirlineCmpBuilder = airline_cmp_bld;
        AirlineCmpBuilder->IntroduceNewCompany();
        AirlineCmpBuilder->buildAirlineLuggage();
        AirlineCmpBuilder->buildAirlineName();
}

