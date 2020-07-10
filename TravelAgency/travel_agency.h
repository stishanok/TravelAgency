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
    void addDoneRoute(std::string);
    void printBuses(std::ostream&);
    void printRoutes(std::ostream&);
    void printDoneRoute(std::ostream&);
    void findInfo(std::string);
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

void TravelAgency:: addDoneRoute(std::string name)
{
    auto it = std::find_if(routes.begin(), routes.end(), [name] (const Route &route) { return name == route.getName(); });
    
    if (it == routes.end())
    {
        std::cout << "Not found!\n";
        return;
    }
    
    DoneRoutes temp;
    temp.setCost(it->getCost());
    temp.setName(it->getName());
    size_t count = 0;
    
    std::string str;
    std::cout << "Enter date of start: ";
    std::cin >> str;
    temp.setDataStart(str);
    std::cout << "Enter date of finish: ";
    std::cin >> str;
    temp.setDataFinish(str);
    
    goAgain:
    std::cout << "Enter number of bus: ";
    std::for_each(buses.begin(), buses.end(),[&count] (const Bus& temp_bus) { std::cout << count++  << " " << temp_bus; });
    std::cin >> count;
    temp.setNumber(buses[count].getNumber());
    size_t temp_passagers;
    std::cout << "Enter number passagers: ";
    std::cin >> temp_passagers;
    
    if (temp_passagers > buses[count].getMaxPassangers())
    {
        std::cout << "Choose another bus\n";
        goto goAgain;
    }
    
    temp.setCountPassengers(count);
    doneRoutes.push_back(temp);
    
}


void TravelAgency:: printBuses(std::ostream& temp)
{
    std::copy(buses.begin(), buses.end(), std::ostream_iterator<Bus>(std::cout, "\n"));
}

void TravelAgency:: printRoutes(std::ostream& temp)
{
    std::copy(routes.begin(), routes.end(), std::ostream_iterator<Route>(std::cout, "\n"));
}
void TravelAgency:: printDoneRoute(std::ostream&)
{
    std::copy(doneRoutes.begin(), doneRoutes.end(), std::ostream_iterator<DoneRoutes>(std::cout, "\n"));
}

void TravelAgency::findInfo(std::string str)
{
    std::copy_if(routes.begin(), routes.end(), std::ostream_iterator<Route>(std::cout, "\n"), [str] (const Route& route)
    {
        return str == route.getName();
    });
    
    std::vector<Bus> temp_bus = buses;
    std::cout << "All buses which complete this route:\n";
    std::for_each(doneRoutes.begin(), doneRoutes.end(), [str, &temp_bus] (const DoneRoutes temp_done)
    {
        if (temp_done.getName() == str)
        {
            std::copy_if(temp_bus.begin(), temp_bus.end(), std::ostream_iterator<Bus>(std::cout, "\n"), [temp_done] (Bus bus)
            {
                return temp_done.getNumber() == bus.getNumber();
            });
        }
    });
}
