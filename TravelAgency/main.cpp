#include "headers.h"

int main()
{
    TravelAgency agency;
    std::ifstream file1("bus.txt");
    std::ifstream file2("route.txt");
    agency.readBuses(file1);
    agency.readRoutes(file2);
    agency.printBuses(std::cout);
    agency.printRoutes(std::cout);
    agency.addDoneRoute("name2");
    
    
    std::string str;
    bool flag = true;
    
    while (true)
    {
        std::cout << "Enter name of route: ";
        std::cin >> str;
        agency.addDoneRoute(str);
        
        std::cin >> flag;
    }
    
    agency.printDoneRoute(std::cout);
    std::cin >> str;
    agency.findInfo(str);
    system("pause");
    return 0;
}
