#include "Minibus.h"
#include <iostream>

// Constructor
Minibus::Minibus(const char* vehicleNumber, const char* color)
    : Taxi(vehicleNumber, color, 15) {  // Set MaxPassengers to 15
}

// Method to Find a Taxi by Vehicle Number
Taxi* Minibus::findTaxiByTaxiNumber(char* vehicleNumber, Taxi* taxiArr, int count) const {
    for (int i = 0; i < count; ++i) {
        if (strcmp(taxiArr[i].getVehicleNumber(), vehicleNumber) == 0) {
            return &taxiArr[i];
        }
    }
    return nullptr;  // Not found
}


