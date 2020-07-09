#pragma once
#include "headers.h"

class Bus
{
private:
    std::string number;
    std::string name;
    double mileage;
public:
    Bus() = default;
    ~Bus() = default;
    
    std::string getNumber() const { return number; }
    std::string getName() const { return name; }
    double getMileage() const { return mileage; }
    friend std::istream& operator>>(std::istream& in, Bus&);
}
