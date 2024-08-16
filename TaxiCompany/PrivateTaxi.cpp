#include "PrivateTaxi.h"
#include <iostream>

// Constructor
PrivateTaxi::PrivateTaxi(const char* vehicleNumber, const char* color)
    : Taxi(vehicleNumber, color, 4) {  // Set MaxPassengers to 4
}

// Method to Find a Taxi by Vehicle Number
Taxi* PrivateTaxi::findTaxiByTaxiNumber(char* vehicleNumber, Taxi* taxiArr, int count) const {
    for (int i = 0; i < count; ++i) {
        if (strcmp(taxiArr[i].getVehicleNumber(), vehicleNumber) == 0) {
            return &taxiArr[i];
        }
    }
    return nullptr;  // Not found
}
