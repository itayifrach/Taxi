#include "Delivery.h"
#include <iostream>
#include <cstring>  // for strlen and strcpy

// Constructor
Delivery::Delivery(int id, int passengers, int time, const Address& origin, const Address& dest, const Payment& pay,
    Customer& cust, Driver& drv, const Date& date, const char* product, double weight)
    : Ride(id, passengers, time, origin, dest, pay, cust, drv),
    TripReservation(id, passengers, time, origin, dest, pay, cust, drv, date),
    weight(weight), product(nullptr) {
    setProduct(product);
}

// Copy Constructor for Delivery
Delivery::Delivery(const Delivery& other)
    : Ride(other), TripReservation(other), weight(other.weight), product(nullptr) {
    setProduct(other.product);  // Deep copy of the product string
}

// Move Constructor
Delivery::Delivery(Delivery&& other) noexcept
    : Ride(std::move(other)), TripReservation(std::move(other)), product(other.product), weight(other.weight) {
    other.product = nullptr;
}

// Destructor
Delivery::~Delivery() {
    delete[] product;
}

// Copy Assignment Operator
Delivery& Delivery::operator=(const Delivery& other) {
    if (this != &other) {
        Ride::operator=(other);
        TripReservation::operator=(other);

        delete[] product;
        setProduct(other.product);
        weight = other.weight;
    }
    return *this;
}

// Move Assignment Operator
Delivery& Delivery::operator=(Delivery&& other) noexcept {
    if (this != &other) {
        Ride::operator=(std::move(other));
        TripReservation::operator=(std::move(other));

        delete[] product;
        product = other.product;
        weight = other.weight;

        other.product = nullptr;
    }
    return *this;
}

// Getters
const char* Delivery::getProduct() const {
    return product;
}

double Delivery::getWeight() const {
    return weight;
}

// Setters
bool Delivery::setProduct(const char* product) {
    if (product == nullptr) {
        return false;
    }
    delete[] this->product;
    this->product = new char[strlen(product) + 1];
    strcpy(this->product, product);
    return true;
}

bool Delivery::setWeight(double weight) {
    if (weight < 0) {
        return false;  // Invalid weight
    }
    this->weight = weight;
    return true;
}

// Method to Calculate Ride Price based on weight
int Delivery::getRidePrice(Ride& ride) {
    return static_cast<int>(weight * 10);
}
