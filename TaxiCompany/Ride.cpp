#include "Ride.h"
#include "Address.h"
#include "Payment.h"
#include "Customer.h"
#include "Driver.h"

// Constructor
Ride::Ride(int id, int passengers, int time, const Address& origin, const Address& dest, const Payment& pay, Customer& cust, Driver& drv)
    : rideID(id), numberOfPassengers(passengers), rideTime(time), originAddress(origin),
    destAddress(dest), payment(pay), customer(cust), driver(drv) {}

// Copy Constructor
Ride::Ride(const Ride& other)
    : rideID(other.rideID),
    numberOfPassengers(other.numberOfPassengers),
    rideTime(other.rideTime),
    originAddress(other.originAddress),
    destAddress(other.destAddress),
    payment(other.payment),
    customer(other.customer),
    driver(other.driver) {
    // Note: References (customer and driver) are copied as references.
}

// Move Constructor
Ride::Ride(Ride&& other) noexcept
    : rideID(other.rideID), numberOfPassengers(other.numberOfPassengers), rideTime(other.rideTime),
    originAddress(std::move(other.originAddress)), destAddress(std::move(other.destAddress)),
    payment(std::move(other.payment)), customer(other.customer), driver(other.driver) {
    // Optionally reset the moved-from object's members
    other.rideID = 0;
    other.numberOfPassengers = 0;
    other.rideTime = 0;
}

// Default Constructor
Ride::Ride() : rideID(0), numberOfPassengers(0), rideTime(0),
originAddress(Address()), destAddress(Address()),
payment(Payment()), customer(*(Customer*)nullptr), driver(*(Driver*)nullptr) {}

// Copy Assignment Operator
Ride& Ride::operator=(const Ride& other) {
    if (this != &other) { // Prevent self-assignment
        this->rideID = other.rideID;
        this->numberOfPassengers = other.numberOfPassengers;
        this->rideTime = other.rideTime;
        this->originAddress = other.originAddress;
        this->destAddress = other.destAddress;
        this->payment = other.payment;
        // References can't be reassigned, so they remain as they were initialized
    }
    return *this;
}

// Getters
int Ride::getRideID() const {
    return rideID;
}

int Ride::getNumberOfPassengers() const {
    return numberOfPassengers;
}

int Ride::getRideTime() const {
    return rideTime;
}

Address Ride::getOriginAddress() const {
    return originAddress;
}

Address Ride::getDestAddress() const {
    return destAddress;
}

Payment Ride::getPayment() const {
    return payment;
}

Customer& Ride::getCustomer() const {
    return customer;
}

Driver& Ride::getDriver() const {
    return driver;
}

// Setters
bool Ride::setRideID(int id) {
    rideID = id;
    return true;
}

bool Ride::setNumberOfPassengers(int passengers) {
    if (passengers < 0) return false;  // Validate passenger count
    numberOfPassengers = passengers;
    return true;
}

bool Ride::setRideTime(int time) {
    if (time < 0) return false;  // Validate time
    rideTime = time;
    return true;
}

bool Ride::setOriginAddress(const Address& origin) {
    originAddress = origin;
    return true;
}

bool Ride::setDestAddress(const Address& dest) {
    destAddress = dest;
    return true;
}

bool Ride::setPayment(const Payment& pay) {
    payment = pay;
    return true;
}

// Example Method
int Ride::getRidePrice(Ride& ride) {
    // Example price calculation based on number of passengers
    return ride.getNumberOfPassengers() * 100;
}

// Destructor
Ride::~Ride() {
    // No dynamic memory to clean up since references are managed outside
}

