#include "Driver.h"
#include "Ride.h"
#include <iostream>  // For strlen, strcpy

// Constructor
Driver::Driver(const char* name, const char* id, const char* licenseNumber, int rideCount, Ride** rideArr, Taxi& taxi) :
    Person(name, id), rideCount(rideCount), taxi(taxi),rideArr(rideArr) {   
	setLicenseNumber(licenseNumber);
}

// Copy Constructor
Driver::Driver(const Driver& other)
    : Person(other), rideCount(other.rideCount), taxi(other.taxi) {
    setLicenseNumber(other.licenseNumber);
}

// Move Constructor
Driver::Driver(Driver&& other) 
    : Person(std::move(other)), rideCount(other.rideCount), rideArr(other.rideArr), taxi(other.taxi) {
    other.rideArr = nullptr;
}

// Destructor
Driver::~Driver() {
    delete[] rideArr;
}

// Copy Assignment Operator
Driver& Driver::operator=(const Driver& other) {
    if (this != &other) {
        Person::operator=(other);
        rideCount = other.rideCount;
        taxi = other.taxi;

        setLicenseNumber(other.licenseNumber);
    }
    return *this;
}

// Move Assignment Operator
Driver& Driver::operator=(Driver&& other) {
    if (this != &other) {
        Person::operator=(std::move(other));
        rideCount = other.rideCount;
        taxi = other.taxi;

        delete[] rideArr;
        rideArr = other.rideArr;
        other.rideArr = nullptr;
    }
    return *this;
}

bool Driver::operator==(const Driver& other) const
{
	if (strcmp(licenseNumber, other.licenseNumber) == 0 && rideCount == other.rideCount && taxi == other.taxi)
    return true;
    return false;
}

// Getters
const char* Driver::getLicenseNumber() const {
    return licenseNumber;
}

int Driver::getRideCount() const {
    return rideCount;
}

Ride** Driver::getRide() const {
    return rideArr;
}

Taxi& Driver::getTaxi() const {
    return taxi;
}

// Setters
bool Driver::setLicenseNumber(const char* licenseNumber) {
    if (strlen(licenseNumber) != LICENSE_NUMBER_SIZE) {
        return false;  // Invalid license number length
    }
    strcpy(this->licenseNumber, licenseNumber);
    return true;
}

bool Driver::setRide( Ride** ride) {
    delete[] rideArr;
    rideArr = new Ride * [rideCount];
    for (int i = 0; i < rideCount; ++i) {
        rideArr[i] = ride[i]; 
    }
    return true;
}

bool Driver::setRideCount(int rideCount) {
    this->rideCount = rideCount;
    return true;
}

bool Driver::setTaxi(const Taxi& taxi) {
    this->taxi = taxi;
    return true;
}

// Example Method
int Driver::getRidePrice(Ride* pRide) {
    return pRide->getRidePrice(*pRide);  // Dummy implementation assuming Ride has getRidePrice
}

std::ostream& operator<<(std::ostream& os, const Driver& driver)
{
	os << "Driver Name: " << driver.getName() << std::endl;
	os << "Driver ID: " << driver.getId() << std::endl;
	os << "Driver License Number: " << driver.getLicenseNumber() << std::endl;
	os << "Driver Ride Count: " << driver.getRideCount() << std::endl;
	os << "Driver Taxi: " << driver.getTaxi() << std::endl;
	return os;
}
