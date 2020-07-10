#pragma once
#include "headers.h"

class Bus
{
private:
    std::string number; //номер
    std::string name; //марка
    double mileage; //пробег
    size_t maxPassengers; //максимальное число пассажиров
public:
    Bus() = default;
    ~Bus() = default;
    
    std::string getNumber() const { return number; }
    std::string getBusName() const { return name; }
    double getMileage() const { return mileage; }
    size_t getMaxPasangers() const { return maxPassengers; }
    void setNumber(std::string n) { number = n; }
    friend std::istream& operator>>(std::istream& in, Bus&);
    friend std::ostream& operator<<(std::ostream& out, const Bus&);
    const bool operator==(const Bus&) const; //дописать
};

std::ostream& operator<<(std::ostream& out, const Bus& bus)
{
    out << "Bus number: "<< bus.getNumber()
    << " Bus name: " << bus.getBusName()
    << " Max passengers: " << bus.getMaxPasangers();
    return out;
}

std::istream& operator>>(std::istream& in, Bus& bus)
{
    in >> bus.number >> bus.name >> bus.mileage>>bus.maxPassengers;
    return in;
}
