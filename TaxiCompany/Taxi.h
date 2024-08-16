#ifndef TAXI_H
#define TAXI_H
#include <iostream>

const int VEHICLE_NUMBER_SIZE = 8;

class Taxi {// abstract 

protected:
    char vehicleNumber[VEHICLE_NUMBER_SIZE + 1];
    char* color;
    const int maxPassengers;

public:

    // Constructors
    Taxi(const char* vehicleNumber, const char* color, const int maxPassengers);
    Taxi(const Taxi& other);        // Copy Constructor
    Taxi(Taxi&& other);            // Move Constructor
    Taxi() : vehicleNumber{ "" }, color(nullptr), maxPassengers(0) {} //Default
    virtual ~Taxi();               // Destructor

    Taxi& operator=(const Taxi& other);
    Taxi& operator=(Taxi&& other) noexcept;

	bool operator==(const Taxi& other) const;

    // Getters
    const char* getVehicleNumber() const;
    const char* getColor() const;
    const int getMaxPassengers() const;

    // Setters
    bool setVehicleNumber(const char* vehicleNumber);
    bool setColor(const char* color);

    // Virtual function to return the type of the taxi
    virtual std::string getType() const;
    // Overload << operator
    friend std::ostream& operator<<(std::ostream& os, const Taxi& taxi);

    virtual Taxi* findTaxiByTaxiNumber(char* vehicleNumber, Taxi* taxiArr, int count) const = 0;
};

#endif // TAXI_H

