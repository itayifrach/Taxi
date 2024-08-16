#include "TaxiCompany.h"
#include <iostream>
#include <cstring>

#include "TaxiCompany.h"
#include <stdexcept>  // For std::runtime_error
#include <cstring>    // For strcpy

// Constructor
TaxiCompany::TaxiCompany(const char* name, Address& address, int driversCount, Driver** driversArr, int taxiCount,
    Taxi** taxiArr, int customerCount, Customer* customerArr, int tripReservationCount,
    TripReservation* tripReservationArr, int deliverysCount, Delivery* deliverysArr)
    : address(address), driversCount(driversCount), taxiCount(taxiCount),
    customerCount(customerCount), tripReservationCount(tripReservationCount),
    DeliverysCount(deliverysCount) {

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    // Deep copy of arrays
    if (driversCount > 0) {
        this->driversArr = new Driver * [driversCount];
        for (int i = 0; i < driversCount; ++i) {
            this->driversArr[i] = new Driver(*driversArr[i]);
        }
    }

    if (taxiCount > 0) {
        this->taxiArr = new Taxi * [taxiCount];
        for (int i = 0; i < taxiCount; ++i) {
            if (Minibus* minibus = dynamic_cast<Minibus*>(taxiArr[i])) {
                this->taxiArr[i] = new Minibus(*minibus);
            }
            else if (PrivateTaxi* privateTaxi = dynamic_cast<PrivateTaxi*>(taxiArr[i])) {
                this->taxiArr[i] = new PrivateTaxi(*privateTaxi);
            }
            else {
                throw std::runtime_error("Unknown Taxi type");
            }
        }
    }

    if (customerCount > 0) {
        this->customerArr = new Customer[customerCount];
        for (int i = 0; i < customerCount; ++i) {
            this->customerArr[i] = customerArr[i];
        }
    }

    if (tripReservationCount > 0) {
        this->tripReservationArr = new TripReservation[tripReservationCount];
        for (int i = 0; i < tripReservationCount; ++i) {
            this->tripReservationArr[i] = tripReservationArr[i];
        }
    }

    if (DeliverysCount > 0) {
        this->DeliverysArr = new Delivery[DeliverysCount];
        for (int i = 0; i < DeliverysCount; ++i) {
            this->DeliverysArr[i] = deliverysArr[i];
        }
    }
}

// Copy Constructor (similar update for copying Taxi objects)
TaxiCompany::TaxiCompany(const TaxiCompany& other)
    : address(other.address), driversCount(other.driversCount), taxiCount(other.taxiCount),
    customerCount(other.customerCount), tripReservationCount(other.tripReservationCount),
    DeliverysCount(other.DeliverysCount) {

    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    if (driversCount > 0) {
        this->driversArr = new Driver * [driversCount];
        for (int i = 0; i < driversCount; ++i) {
            this->driversArr[i] = new Driver(*other.driversArr[i]);
        }
    }

    if (taxiCount > 0) {
        this->taxiArr = new Taxi * [taxiCount];
        for (int i = 0; i < taxiCount; ++i) {
            if (Minibus* minibus = dynamic_cast<Minibus*>(other.taxiArr[i])) {
                this->taxiArr[i] = new Minibus(*minibus);
            }
            else if (PrivateTaxi* privateTaxi = dynamic_cast<PrivateTaxi*>(other.taxiArr[i])) {
                this->taxiArr[i] = new PrivateTaxi(*privateTaxi);
            }
            else {
                throw std::runtime_error("Unknown Taxi type");
            }
        }
    }

    if (customerCount > 0) {
        this->customerArr = new Customer[customerCount];
        for (int i = 0; i < customerCount; ++i) {
            this->customerArr[i] = other.customerArr[i];
        }
    }

    if (tripReservationCount > 0) {
        this->tripReservationArr = new TripReservation[tripReservationCount];
        for (int i = 0; i < tripReservationCount; ++i) {
            this->tripReservationArr[i] = other.tripReservationArr[i];
        }
    }

    if (DeliverysCount > 0) {
        this->DeliverysArr = new Delivery[DeliverysCount];
        for (int i = 0; i < DeliverysCount; ++i) {
            this->DeliverysArr[i] = other.DeliverysArr[i];
        }
    }
}


// Move Constructor
TaxiCompany::TaxiCompany(TaxiCompany&& other) noexcept
    : address(other.address), driversCount(other.driversCount), driversArr(other.driversArr),
    taxiCount(other.taxiCount), taxiArr(other.taxiArr), customerCount(other.customerCount),
    customerArr(other.customerArr), tripReservationCount(other.tripReservationCount),
    tripReservationArr(other.tripReservationArr), DeliverysCount(other.DeliverysCount),
    DeliverysArr(other.DeliverysArr), name(other.name) {

    // Nullify the moved-from object's pointers
    other.name = nullptr;
    other.driversArr = nullptr;
    other.taxiArr = nullptr;
    other.customerArr = nullptr;
    other.tripReservationArr = nullptr;
    other.DeliverysArr = nullptr;
}

// Destructor
TaxiCompany::~TaxiCompany() {
    delete[] name;
    for (int i = 0; i < driversCount; ++i) {
        delete driversArr[i];
    }
    delete[] driversArr;

    for (int i = 0; i < taxiCount; ++i) {
        delete taxiArr[i];
    }
    delete[] taxiArr;

    delete[] customerArr;
    delete[] tripReservationArr;
    delete[] DeliverysArr;
}

// Copy Assignment Operator
TaxiCompany& TaxiCompany::operator=(const TaxiCompany& other) {
    if (this != &other) {
        // Clean up existing resources
        delete[] name;
        for (int i = 0; i < driversCount; ++i) {
            delete driversArr[i];
        }
        delete[] driversArr;
        for (int i = 0; i < taxiCount; ++i) {
            delete taxiArr[i];
        }
        delete[] taxiArr;
        delete[] customerArr;
        delete[] tripReservationArr;
        delete[] DeliverysArr;

        // Copy the simple members
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        address = other.address;
        driversCount = other.driversCount;
        taxiCount = other.taxiCount;
        customerCount = other.customerCount;
        tripReservationCount = other.tripReservationCount;
        DeliverysCount = other.DeliverysCount;

        // Deep copy of drivers array
        if (driversCount > 0) {
            this->driversArr = new Driver * [driversCount];
            for (int i = 0; i < driversCount; ++i) {
                this->driversArr[i] = new Driver(*other.driversArr[i]);
            }
        }

        // Deep copy of taxi array
        if (taxiCount > 0) {
            this->taxiArr = new Taxi * [taxiCount];
            for (int i = 0; i < taxiCount; ++i) {
                if (Minibus* minibus = dynamic_cast<Minibus*>(other.taxiArr[i])) {
                    this->taxiArr[i] = new Minibus(*minibus);
                }
                else if (PrivateTaxi* privateTaxi = dynamic_cast<PrivateTaxi*>(other.taxiArr[i])) {
                    this->taxiArr[i] = new PrivateTaxi(*privateTaxi);
                }
                else {
                    throw std::runtime_error("Unknown Taxi type");
                }
            }
        }

        // Deep copy of customer array
        if (customerCount > 0) {
            this->customerArr = new Customer[customerCount];
            for (int i = 0; i < customerCount; ++i) {
                this->customerArr[i] = other.customerArr[i];
            }
        }

        // Deep copy of trip reservation array
        if (tripReservationCount > 0) {
            this->tripReservationArr = new TripReservation[tripReservationCount];
            for (int i = 0; i < tripReservationCount; ++i) {
                this->tripReservationArr[i] = other.tripReservationArr[i];
            }
        }

        // Deep copy of deliveries array
        if (DeliverysCount > 0) {
            this->DeliverysArr = new Delivery[DeliverysCount];
            for (int i = 0; i < DeliverysCount; ++i) {
                this->DeliverysArr[i] = other.DeliverysArr[i];
            }
        }
    }
    return *this;
}


// Move Assignment Operator
TaxiCompany& TaxiCompany::operator=(TaxiCompany&& other) noexcept {
    if (this != &other) {
        delete[] name;
        for (int i = 0; i < driversCount; ++i) {
            delete driversArr[i];
        }
        delete[] driversArr;
        for (int i = 0; i < taxiCount; ++i) {
            delete taxiArr[i];
        }
        delete[] taxiArr;
        delete[] customerArr;
        delete[] tripReservationArr;
        delete[] DeliverysArr;

        name = other.name;
        address = other.address;
        driversCount = other.driversCount;
        taxiCount = other.taxiCount;
        customerCount = other.customerCount;
        tripReservationCount = other.tripReservationCount;
        DeliverysCount = other.DeliverysCount;

        // Set the other object to a valid state
        other.name = nullptr;
        other.driversArr = nullptr;
        other.taxiArr = nullptr;
        other.customerArr = nullptr;
        other.tripReservationArr = nullptr;
        other.DeliverysArr = nullptr;
    }
    return *this;
}