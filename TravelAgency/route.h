#pragma once
#include "headers.h"

class Route
{
private:
    std::string name;
    std::string start;
    std::string finish;
    double km;
    double cost;
public:
    Route() = default;
    ~Route() = default;
    std::string getName() const { return name; }
    std::string getStart() const { return start; }
    std::string getFinish() const { return finish; }
    double getKm() const { return km; }
    double getCost() const {return cost; }
    void setName(std::string _name) { name = _name; }
    void setCost(double _km) { km = _km; }
    friend std::istream& operator>>(std::istream&, Route&);
};

std::istream& operator>>(std::istream& in, Route& route)
{
    in >> route.name >> route.start >> route.finish >> route.km >> route.cost;
    return in;
}
