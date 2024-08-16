#ifndef PRIVATE_TAXI_H
#define PRIVATE_TAXI_H
#include "Taxi.h"

class PrivateTaxi : public Taxi {

public:

    // Constructors
    PrivateTaxi(const char* vehicleNumber , const char* color);
   

    // Getters
    const char* getVehicleNumber() const;
    const char* getColor() const;

    // Setters
    bool setVehicleNumber(const char* vehicleNumber);
    bool setColor(const char* color);
    // Override the getType function
    std::string getType() const override {
        return "Private Taxi";
    }
    virtual Taxi* findTaxiByTaxiNumber(char* vehicleNumber, Taxi* taxiArr, int count) const override;
};

#endif // PRIVATE_TAXI_H
