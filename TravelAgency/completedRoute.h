#pragma once
#include "headers.h"

class CompletedRoute: public Route, public Bus
{
private:
    std::string DateStart;
    std::string DateFinish;
    size_t CountPassengers;
public:
    CompletedRoute() = default;
    ~CompletedRoute() = default;
    
    std::string getDateStart() const { return DateStart; }
    std::string getDateFinish() const { return DateFinish; }
    size_t getCountPassengers() const { return CountPassengers; }
    void setDateStart(std::string _date) { DateStart = _date; }
    void setDateFinish(std::string _date) { DateFinish = _date; }
    void setCountPassengers(size_t _count) { CountPassengers = _count; }
    const bool operator==(const CompletedRoute&) const;
    friend std::ostream& operator<<(std::ostream&, const CompletedRoute&);
};

std::ostream& operator<<(std::ostream& out, const CompletedRoute& route)
{
    out << "Cost: "<< route.getCost()
    << " Name route: " << route.getName()
    << " Number: " << route.getNumber()
    << " Date start: " << route.getDateStart()
    << " Date finish: " << route.getDateFinish()
    << " Count passengers: " << route.getCountPassengers();
    return out;
}
