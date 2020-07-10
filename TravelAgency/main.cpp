#include "headers.h"

int main()
{
    TourAgency agency;
    std::ifstream in("bus.txt");
    agency.readBuses(in);
    in.close();
    in.open("route.txt");
    agency.readRoutes(in);
    std::string str;
    bool flag=false;
    while (!flag)
    {
        std::cout << "Enter name of rout " << std::endl;
        std::cin >> str;
        agency.addCompletedRoute(str);
        std::cout << "End? " << std::endl;
        std::cin >> flag;
    }
    agency.printCompletedRoutes(std::cout);
    std::cout << "Enter name of  info rout " << std::endl;
    std::cin >> str;
    agency.findInfo(str);
    return 0;
}
