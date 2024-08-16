#ifndef ADDRESS_H
#define ADDRESS_H

#include <cstring> 

class Address {

private:
    int num;
    char* street;
    char* city;


public:
    // Constructors
    Address(int n, const char* s, const char* c);
    Address(const Address& other);        // Copy Constructor
    Address(Address&& other);            // Move Constructor
    Address() : num(0), street(nullptr), city(nullptr) {};
    ~Address();                         // Destructor

    Address& operator=(const Address& other);  
    Address& operator=(Address&& other) noexcept;

	bool operator==(const Address& other) const;

    // Getters
    int getNum() const;
    const char* getStreet() const;
    const char* getCity() const;

    // Setters
    bool setNum(int num);
    bool setStreet(const char* street);
    bool setCity(const char* city);

	static Address parseAddress(const char* address);

};

#endif // ADDRESS_H
