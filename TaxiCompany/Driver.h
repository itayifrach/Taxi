#ifndef DRIVER_H
#define DRIVER_H

#include "Person.h"
#include "Taxi.h"

class Ride;

const int LICENSE_NUMBER_SIZE = 7;

class Driver : public Person {

private:
    char licenseNumber[LICENSE_NUMBER_SIZE + 1];
    int  rideCount;
    Ride** rideArr;
    Taxi& taxi;

public:
    // Constructors
    Driver(const char* name, const char* id, const char* licenseNumber, int rideCount, Ride** rideArr, Taxi& taxi);
    Driver(const Driver& other);        // Copy Constructor
    Driver(Driver&& other);             // Move Constructor
    ~Driver();                            // Destructor

    Driver& operator=(const Driver& other);
    Driver& operator=(Driver&& other);

    bool operator==(const Driver& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Driver& driver);

    // Getters
    const char* getName() const;
    const char* getId() const;
    const char* getLicenseNumber() const;
    int         getRideCount() const;
    Ride** getRide() const;
    Taxi& getTaxi() const;

    // Setters
    bool setName(const char* name);
    bool setId(const char* id);
    bool setLicenseNumber(const char* licenseNumber);
    bool setRideCount(int rideCount);
    bool setRide( Ride** ride);
    bool setTaxi(const Taxi& taxi);

    int  getRidePrice(Ride* pRide);
};

#endif // DRIVER_H

