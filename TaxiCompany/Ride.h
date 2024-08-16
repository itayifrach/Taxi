#ifndef RIDE_H
#define RIDE_H

#include "Address.h"
#include "Payment.h"
#include "Customer.h"
#include "Driver.h"

class Ride {
protected:
    int rideID;
    int numberOfPassengers;
    int rideTime;
    Address originAddress;
    Address destAddress;
    Payment payment;
    Customer& customer;
    Driver& driver;

public:
    // Constructors
    Ride(int id, int passengers, int time, const Address& origin, const Address& dest, const Payment& pay, Customer& cust, Driver& drv);
    Ride(Ride&& other) noexcept; // Move Constructor
    Ride(); // Default Constructor
    Ride(const Ride& other);  // Copy constructor
    // Assignment Operators
    Ride& operator=(const Ride& other);

    // Getters
    int getRideID() const;
    int getNumberOfPassengers() const;
    int getRideTime() const;
    Address getOriginAddress() const;
    Address getDestAddress() const;
    Payment getPayment() const;
    Customer& getCustomer() const;
    Driver& getDriver() const;

    // Setters
    bool setRideID(int id);
    bool setNumberOfPassengers(int passengers);
    bool setRideTime(int time);
    bool setOriginAddress(const Address& origin);
    bool setDestAddress(const Address& dest);
    bool setPayment(const Payment& pay);

    // Example Method
    int getRidePrice(Ride& ride);
};

#endif // RIDE_H
