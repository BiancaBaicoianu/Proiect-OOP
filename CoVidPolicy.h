#ifndef OOP_COVIDPOLICY_H
#define OOP_COVIDPOLICY_H

#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>

template <class T>
class CoVidPolicy{
private:
    std::vector<std::string> countries{"SUA", "China", "Australia", "Austria", "Spain"};
    bool restrictions = false;
public:

    void setRestrictions(const std::string& destination) {
        CoVidPolicy::restrictions = false;
        for(auto & country : countries)
            if(destination == country)
                CoVidPolicy::restrictions = true;
    }

    T isRestrictions() const {
        if (restrictions) {
            time_t now = time(nullptr);
            char *date_time = ctime(&now);
            std::cout << "Your destination is on the list of epidemiological risk countries, updated " << date_time
            << "Do not forget to check all the CoViD restrictions for your destination country,according to Ministry of External Affairs"<<std::endl;
        }
        else{
            std::cout << "Your destination is free of restrictions. :)"<<std::endl;
        }
        return restrictions;
    }

    explicit CoVidPolicy(T restrictions) : restrictions(restrictions) {}

    virtual ~CoVidPolicy() = default;

};

#endif //OOP_COVIDPOLICY_H
