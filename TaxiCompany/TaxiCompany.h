#ifndef TAXI_COMPANY_H
#define TAXI_COMPANY_H

#include "Address.h"
#include "Taxi.h"
#include "Customer.h"
#include "TripReservation.h"
#include "Delivery.h"
#include "PrivateTaxi.h"
#include "Minibus.h"
#include "Ride.h"

class TaxiCompany {

private:
    char* name;
    Address address;
    int driversCount;
    Driver** driversArr;
    int taxiCount;
    Taxi** taxiArr;
    int customerCount;
    Customer* customerArr;
    int tripReservationCount;
    TripReservation* tripReservationArr;
    int DeliverysCount;
    Delivery* DeliverysArr;

public:

    // Constructors
    TaxiCompany(const char* name, Address& address,
        int driversCount = 0, Driver** driversArr = nullptr,
        int taxiCount = 0, Taxi** taxiArr = nullptr,
        int customerCount = 0, Customer* customerArr = nullptr,
        int tripReservationCount = 0, TripReservation* tripReservationArr = nullptr,
        int DeliverysCount = 0, Delivery* DeliverysArr = nullptr);
    TaxiCompany(const TaxiCompany& other);         // Copy Constructor
    TaxiCompany(TaxiCompany&& other) noexcept;     // Move Constructor
    ~TaxiCompany();                                // Destructor

    TaxiCompany& operator=(const TaxiCompany& other);
    TaxiCompany& operator=(TaxiCompany&& other) noexcept;

    // Getters
    const char*      getName() const;
    Address          getAddress() const;
    int              getDriversCount() const;
    Driver**         getDriversArr() const;
    int              getTaxiCount() const;
    Taxi*            getTaxiArr() const;
    int              getCustomerCount() const;
    Customer*        getCustomerArr() const;
    int              getTripReservationCount() const;
    TripReservation* getTripReservationArr() const;
    int              getDeliverysCount() const;
    Delivery*        getDeliverysArr() const;

    // Setters
    bool setName(const char* name);
    bool setAddress(const Address& address);
    bool setDriversCount(int driversCount);
    bool setDriversArr(const Driver** driversArr);
    bool setTaxiCount(int taxiCount);
    bool setTaxiArr(const Taxi* taxi);
    bool setCustomerCount(int customerCount);
    bool setCustomerArr(const Customer* customerArr);
    bool setTripReservationCount(int TripReservationCount);
    bool setTripReservationAr(const TripReservation* TripReservationArr);
    bool setDeliverysCount(int deliverysCount);
    bool setDeliverysArr(const Delivery* deliverysArr);

	int addTaxi();
    int addTaxi(const Taxi* newTaxi);
    
    int addDriver();
    int addDriver(const Driver* newDriver);

    int addCustomer();
	int addCustomer(const Customer* newCustomer);

    Ride* addRide();
	int addRide(const Ride* newRide, Driver* driver);

    int addTripReservation();
	int addTripReservation(const TripReservation* newTR);

    int addDelivery();
	int addDelivery(const Delivery* newDelivery);

    int calculateIncome(TaxiCompany* pComp);
    int calculateOutcome(TaxiCompany* pComp);

    void printTaxiCompany(TaxiCompany* pComp);
    void printAllTripReservation(TaxiCompany* pComp);
    void printAllDelivery(TaxiCompany* pComp);
    Customer* findCustomer(const char* id);
    Driver* findDriver(const char* id);
	Taxi* findTaxi(const char* id);

};

#endif // TAXI_COMPANY_H

