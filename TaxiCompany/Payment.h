#ifndef PAYMENT_H
#define PAYMENT_H


enum PaymentOption { Credit, Cash, NofOpt };

//const char* OptStr[NofOpt] = { "Credit", "Cash" };

class Payment {

private:
    PaymentOption option;
    int price;

public:
    // Constructors
    Payment(PaymentOption opt=Credit, int p=0);

	bool operator==(const Payment& other) const;
    // Getters
    PaymentOption getOption() const;
    int getPrice() const;

    // Setters
    bool setOption(const PaymentOption opt);
    bool setPrice(const int price);
};

#endif // PAYMENT_H

