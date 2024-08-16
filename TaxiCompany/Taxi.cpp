#include "Taxi.h"
#include <cstring>  // For strlen, strcpy

// Constructor
Taxi::Taxi(const char* vehicleNumber, const char* color, int maxPassengers)
    : maxPassengers(maxPassengers) {  // Initialize const member
    strcpy(this->vehicleNumber, vehicleNumber);
    this->color = new char[strlen(color) + 1];
    strcpy(this->color, color);
}

// Copy Constructor
Taxi::Taxi(const Taxi& other)
    : maxPassengers(other.maxPassengers) {  // Copy const member
    strcpy(this->vehicleNumber, other.vehicleNumber);
    this->color = new char[strlen(other.color) + 1];
    strcpy(this->color, other.color);
}

// Move Constructor
Taxi::Taxi(Taxi&& other)
    : maxPassengers(other.maxPassengers) {  // Move const member
    strcpy(this->vehicleNumber, other.vehicleNumber);
    this->color = other.color;
    other.color = nullptr;
}

// Destructor
Taxi::~Taxi() {
    delete[] color;
}

// Copy Assignment Operator
Taxi& Taxi::operator=(const Taxi& other) {
    if (this != &other) {
        delete[] color;

        strcpy(this->vehicleNumber, other.vehicleNumber);
        this->color = new char[strlen(other.color) + 1];
        strcpy(this->color, other.color);
        // maxPassengers is const, so it cannot be reassigned here
    }
    return *this;
}

// Move Assignment Operator
Taxi& Taxi::operator=(Taxi&& other) noexcept {
    if (this != &other) {
        delete[] color;

        strcpy(this->vehicleNumber, other.vehicleNumber);
        this->color = other.color;
        other.color = nullptr;
        // maxPassengers is const, so it cannot be reassigned here
    }
    return *this;
}

bool Taxi::operator==(const Taxi& other) const
{
	if (strcmp(vehicleNumber, other.vehicleNumber) == 0 && strcmp(color, other.color) == 0 && maxPassengers == other.maxPassengers)
		return true;
    return false;
}

// Getters
const char* Taxi::getVehicleNumber() const {
    return vehicleNumber;
}

const char* Taxi::getColor() const {
    return color;
}

const int Taxi::getMaxPassengers() const {
    return maxPassengers;
}

// Setters
bool Taxi::setVehicleNumber(const char* vehicleNumber) {
    if (strlen(vehicleNumber) != VEHICLE_NUMBER_SIZE) {
        return false;  // Invalid vehicle number length
    }
    strcpy(this->vehicleNumber, vehicleNumber);
    return true;
}

bool Taxi::setColor(const char* color) {
    delete[] this->color;
    this->color = new char[strlen(color) + 1];
    strcpy(this->color, color);
    return true;
}
std::ostream& operator<<(std::ostream& os, const Taxi& taxi) {
    os << "Type: " << taxi.getType() << ", Vehicle Number: " << taxi.vehicleNumber
        << ", Color: " << taxi.color << ", Max Passengers: " << taxi.maxPassengers;
    return os;
}   