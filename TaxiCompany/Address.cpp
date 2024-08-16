#include "Address.h"
#include <iostream>  // For strlen, strcpy

// Constructor
Address::Address(int n, const char* s, const char* c) : num(n) {
    street = new char[strlen(s) + 1];
    strcpy(street, s);
    city = new char[strlen(c) + 1];
    strcpy(city, c);
}

// Copy Constructor
Address::Address(const Address& other) : num(other.num) {
    street = new char[strlen(other.street) + 1];
    strcpy(street, other.street);
    city = new char[strlen(other.city) + 1];
    strcpy(city, other.city);
}

// Move Constructor
Address::Address(Address&& other)  : num(other.num), street(other.street), city(other.city) {
    other.street = nullptr;
    other.city = nullptr;
}

// Destructor
Address::~Address() {
    delete[] street;
    delete[] city;
}

// Copy Assignment Operator
Address& Address::operator=(const Address& other) {
    if (this != &other) {
        delete[] street;
        delete[] city;

        num = other.num;
        street = new char[strlen(other.street) + 1];
        strcpy(street, other.street);
        city = new char[strlen(other.city) + 1];
        strcpy(city, other.city);
    }
    return *this;
}

// Move Assignment Operator
Address& Address::operator=(Address&& other) noexcept {
    if (this != &other) {
        delete[] street;
        delete[] city;

        num = other.num;
        street = other.street;
        city = other.city;

        other.street = nullptr;
        other.city = nullptr;
    }
    return *this;
}

bool Address::operator==(const Address& other) const
{
	if (num == other.num && strcmp(street, other.street) == 0 && strcmp(city, other.city) == 0) {
		return true;
	}
    return false;
}

// Getters
int Address::getNum() const {
    return num;
}

const char* Address::getStreet() const {
    return street;
}

const char* Address::getCity() const {
    return city;
}

// Setters
bool Address::setNum(int n) {
    num = n;
    return true;
}

bool Address::setStreet(const char* s) {
    delete[] street;
    street = new char[strlen(s) + 1];
    strcpy(street, s);
    return true;
}

bool Address::setCity(const char* c) {
    delete[] city;
    city = new char[strlen(c) + 1];
    strcpy(city, c);
    return true;
}


 Address Address::parseAddress(const char* address)
{
    // Parse the address string and return an Address object
    // The address string is in the format "123 Main St, Springfield" 
    int num;
    char street[100], city[100];  // Assuming maximum lengths
    if (sscanf(address, "%d %99[^,], %99[^\n]", &num, street, city) != 3) {
        throw std::invalid_argument("Invalid address format");
    }
    return Address(num, street, city);

}
