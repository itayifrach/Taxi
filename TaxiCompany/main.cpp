#include <iostream>
#include <string>
#include "TaxiCompany.h"

enum eMenuOptions
{
    eAddDriver, eAddTaxi, eAddCustomer, eAddTripReservation, eAddRide, eAddDelivery, ePrintCompany, ePrintRides,
    ePrintDeliveries, ePrintTripReservation, eCalculateIncome, eCalculateOutcome, eNofOptions
};

const std::string str[eNofOptions] = { "Add Driver","Add Taxi", "Add Customer", "Add Trip Reservation", "Add ride", "Add delivery"
                                     , "Print Taxi Company", "Print all Rides",
                                      "Print all deliveries", "Print all Trip Reservations", "Calculate income",
                                      "Calculate outcome"};

#define EXIT -1
Address companyAddress(123, "Tel Aviv", "Stam");
TaxiCompany company("My Taxi Company", companyAddress);

int menu();

int main()
{
    int option;
    bool stop = false;

    do
    {
        option = menu();
        switch (option)
        {
        case eAddDriver:
            company.addDriver();
            break;

        case eAddTaxi:
			company.addTaxi();
            break;

        case eAddCustomer:
            break;

        case eAddTripReservation:
            break;

        case eAddRide:
            break;

        case eAddDelivery:
            break;

        case ePrintCompany:
            break;

        case ePrintRides:
            break;

        case ePrintDeliveries:
            break;

        case ePrintTripReservation:
            break;

        case eCalculateIncome:
            break;

        case eCalculateOutcome:
            break;

        case EXIT:
            std::cout << "Bye bye" << std::endl;
            stop = true;
            break;

        default:
            std::cout << "Wrong option" << std::endl;
            break;
        }
    } while (!stop);

    return 0;
}

int menu()
{
    int option;
    std::cout << "\n\n";
    std::cout << "Please choose one of the following options" << std::endl;
    for (int i = 0; i < eNofOptions; i++)
        std::cout << i << " - " << str[i] << std::endl;
    std::cout << EXIT << " - Quit" << std::endl;
    std::cin >> option;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clean buffer
    return option;
}
