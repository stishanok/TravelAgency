#pragma once
#include "headers.h"

class DoneRoutes: public Route, public Bus
{
private:
    std::string dateStart;
    std::string dateFinish;
    size_t countPassengers;
public:
    DoneRoutes() = default;
    ~DoneRoutes() = default;
    std::string getDataStart() const { return dateStart; }
    std::string getDataFinish() const { return dateFinish; }
    size_t getCountPassengers() const { return countPassengers; }
    void setDataStart(std::string date) { dateStart = date; }
    void setDataFinish(std::string date) { dateFinish = date; }
    void setCountPassengers(size_t count) { countPassengers = count; }
    bool operator==(const DoneRoutes&) const;
    friend std::ostream& operator<<(std::ostream& out, const DoneRoutes& done);
};

std::ostream& operator<<(std::ostream& out, const DoneRoutes& temp)
{
    out << "Cost: " << temp.getCost() << " Name of route: " << temp.getName() << " Number: " << temp.getNumber() << " Date start: " << temp.dateStart << " Date finish: " << temp.dateFinish << " Count passengers: " << temp.getCountPassengers();
    return out;
}
