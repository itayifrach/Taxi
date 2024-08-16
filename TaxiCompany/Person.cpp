#include "Person.h"
#include <iostream> 

// Constructor
Person::Person(const char* name, const char* id) : name(name) {
    strcpy(this->id, id);
}

// Copy Constructor
Person::Person(const Person& other) : name(other.name) {
    strcpy(this->id, other.id);
}

// Move Constructor
Person::Person(Person&& other) : name(other.name) {
    strcpy(this->id, other.id);
    other.name = nullptr;  // Move constructor should not touch the const part
}

// Destructor
Person::~Person() {
    // No need to delete name since we don't own the memory
}

// Copy Assignment Operator
Person& Person::operator=(const Person& other) {
    if (this != &other) {
        name = other.name;
        strcpy(this->id, other.id);
    }
    return *this;
}

// Move Assignment Operator
Person& Person::operator=(Person&& other) {
    if (this != &other) {
        name = other.name;
        strcpy(this->id, other.id);
        other.name = nullptr;  // Move assignment should not touch the const part
    }
    return *this;
}

// Getters
const char* Person::getName() const {
    return name;
}

const char* Person::getId() const {
    return id;
}

// Setters
bool Person::setName(const char* name) {
    this->name = name;  // Direct assignment
    return true;
}

bool Person::setId(const char* id) {
    strcpy(this->id, id);
    return true;
}
