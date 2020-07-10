#pragma once
#include "headers.h"

class TourAgency
{
private:
    std::vector<Bus> buses;
    std::vector<Route> routes;
    std::vector<CompletedRoute>completedRouts;
public:
    TourAgency() = default;
    ~TourAgency() = default;
    
    void readBuses(std::istream&);
    void readRoutes(std::istream&);
    void printBuses(std::ostream&);
    void printRoutes(std::ostream&);
    void printCompletedRoutes(std::ostream&);
    void addCompletedRoute(std::string);
    void findInfo(std::string);
};

void TourAgency:: readBuses(std::istream& file)
{
    if (!file)
    {
        std::cout << "Error open file bus.txt\n";
        exit(0);
    }
    
    while (!file.eof())
    {
        Bus bus;
        file >> bus;
        buses.push_back(bus);
    }
}

void TourAgency:: readRoutes(std::istream& file)
{
    if (!file)
    {
        std::cout << "Error open file route.txt\n";
        exit(0);
    }
    
    while (!file.eof())
    {
        Route route;
        file >> route;
        routes.push_back(route);
    }
}

void TourAgency:: printBuses(std::ostream& out)
{
    std::copy(buses.begin(), buses.end(), std::ostream_iterator<Bus>(out, "\n"));
}

void  TourAgency:: printRoutes(std::ostream& out)
{
    std::copy(routes.begin(), routes.end(), std::ostream_iterator<Route>(out, "\n"));
}

void  TourAgency:: printCompletedRoutes(std::ostream& out)
{
    std::copy(completedRouts.begin(), completedRouts.end(), std::ostream_iterator<CompletedRoute>(out, "\n"));
}

void TourAgency:: addCompletedRoute(std::string name)
{
    auto it = std::find_if(routes.begin(), routes.end(), [name](const Route& route)
    {
        return name == route.getName();
    });
    
    if (it == routes.end())
    {
        std::cout << "Route not found\n";
        return;
    }
    
    CompletedRoute compRoute;
    compRoute.setCost(it->getCost());
    compRoute.setName(it->getName());
    size_t count = 0, index, countPass;
    std::string str;
    std::cout << "Enter date start: ";
    std::cin >> str;
    compRoute.setDateStart(str);
    std::cout << "Enter date finish: ";
    std::cin >> str;
    compRoute.setDateFinish(str);
    std::cout << "All buses:\n";
    std::for_each(buses.begin(), buses.end(), [&count](const Bus &bus)
                  {
        std::cout << "[" << count++ << "] " << bus << "\n";
    });
    
    while (true)
    {

        while (true)
        {
            std::cout << "Enter number of bus: ";
            std::cin >> index;
            
            if (index > count)
            {
                std::cout << "Error index bus!\n";
            }
            else
            {
                break;
            }
        }
        
        compRoute.setNumber(buses[count].getNumber());
        std::cout << "Enter count of pasangers: ";
        std::cin >> countPass;
        
        if (countPass > buses[count].getMaxPasangers())
        {
            std::cout << "Choose another bus!\n";
            continue;
        }
        else
        {
            break;
        }
    }
    
    compRoute.setCountPassengers(countPass);
    completedRouts.push_back(compRoute);
}



void TourAgency:: findInfo(std::string str)
{
    std::copy_if(routes.begin(), routes.end(), std::ostream_iterator<Route>(std::cout, "\n"), [str] (const Route& route) { return str == route.getName(); });
    std::cout << "All buses which complete this rout:\n";
    
    std::for_each(completedRouts.begin(), completedRouts.end(), [this, &str](CompletedRoute compRoute)
    {
        if (compRoute.getName()==str)
        {
            std::copy_if(buses.begin(), buses.end(), std::ostream_iterator<Bus>(std::cout, "\n"), [compRoute](Bus bus) { return compRoute.getNumber() == bus.getNumber(); });
        }
    });
    
    
    
    
    
}




