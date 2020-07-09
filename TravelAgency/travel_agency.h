#pragma once
#include "headers.h"

class TravelAgency
{
private:
    std::vector<Bus> buses;
    std::vector<Route> routes;
    std::vector<DoneRoutes> doneRoutes;
public:
    TravelAgency() = default;
    ~TravelAgency() = default;
    void readBuses(std::istream&);
    void readRoutes(std::istream&);
};

void TravelAgency:: readBuses(std::istream& file)
{
    while (!file.eof())
    {
        Bus bus;
        file >> bus;
        buses.push_back(bus);
    }
}

void TravelAgency:: readRoutes(std::istream& file)
{
    while (!file.eof())
    {
        Route route;
        file >> route;
        routes.push_back(route);
    }
}
