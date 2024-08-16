#include "Payment.h"
const char* OptStr[NofOpt] = { "Credit", "Cash" };

// Constructor
Payment::Payment(PaymentOption opt, int p) : option(opt), price(p) {}

bool Payment::operator==(const Payment& other) const
{
    if (option == other.option && price == other.price)
		return true;
    return false;
}

// Getters
PaymentOption Payment::getOption() const {
    return option;
}

int Payment::getPrice() const {
    return price;
}

// Setters
bool Payment::setOption(const PaymentOption opt) {
    if (opt >= NofOpt) {
        return false;  // Invalid option
    }
    option = opt;
    return true;
}

bool Payment::setPrice(const int p) {
    if (p < 0) {
        return false;  // Price cannot be negative
    }
    price = p;
    return true;
}
