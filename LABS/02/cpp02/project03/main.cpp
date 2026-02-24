#include "simple_mc2.h"
#include <iostream>

int main()
{
    double expiry;
    double strike;
    double spot;
    double vol;
    double r;
    unsigned long number_of_paths;

    std::cout << "\nEnter expiry\n";
    std::cin >> expiry;

    std::cout << "\nEnter strike\n";
    std::cin >> strike;

    std::cout << "\nEnter spot\n";
    std::cin >> spot;

    std::cout << "\nEnter vol\n";
    std::cin >> vol;

    std::cout << "\nEnter r\n";
    std::cin >> r;

    std::cout << "\nNumber of paths\n";
    std::cin >> number_of_paths;

    PayOffCall payOffCall(strike);
    PayOffPut payOffPut(strike);

    double resultCall = simple_monte_carlo2(payOffCall,
                                            expiry,
                                            spot,
                                            vol,
                                            r,
                                            number_of_paths);

    double resultPut = simple_monte_carlo2(payOffPut,
                                           expiry,
                                           spot,
                                           vol,
                                           r,
                                           number_of_paths);

    std::cout << "the prices are " << resultCall << " for the call and "
              << resultPut << " for the put\n";

    return 0;
}
