#pragma once
#include "headers.h"

class Bus
{
private:
    std::string number;
    std::string name;
    double mileage;
    size_t maxPassangers;
public:
    Bus() = default;
    ~Bus() = default;
    
    std::string getNumber() const { return number; }
    std::string getName() const { return name; }
    double getMileage() const { return mileage; }
    size_t getMaxPassangers() const { return maxPassangers; }
    void setNumber(std::string _number) { number = _number; }
    friend std::istream& operator>>(std::istream&, Bus&);
    bool operator==(const Bus&) const;
};

std::istream& operator>>(std::istream& in, Bus& bus)
{
    in >> bus.number >> bus.name >> bus.mileage >> bus.maxPassangers;
    return in;
}


