#ifndef MINIBUS_H
#define MINIBUS_H

#include "Taxi.h"



class Minibus : public Taxi {

public:

    // Constructors
    Minibus(const char* vehicleNumber, const char* color);

    // Setters
    bool setVehicleNumber(const char* vehicleNumber);
    bool setColor(const char* color);
    // Override the getType function
    std::string getType() const override {
        return "Minibus";
    }
    virtual Taxi* findTaxiByTaxiNumber(char* vehicleNumber, Taxi* taxiArr, int count) const override;
};

#endif // MINIBUS_H

