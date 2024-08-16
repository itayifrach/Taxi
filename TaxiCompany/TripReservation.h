#ifndef TRIPRESERVATION_H
#define TRIPRESERVATION_H

#include "Ride.h"
#include "Date.h"

class TripReservation : public virtual Ride {

protected:
    Date date;

public:
    // Constructors
    TripReservation(int id, int passengers, int time, const Address& origin, const Address& dest, const Payment& pay, Customer& cust, Driver& drv, const Date& date);
    TripReservation(Ride ride=Ride(), const Date& date=Date());

	//Move Constructor
    //TripReservation(TripReservation&& other);
	// Assignment Operator
	//TripReservation& operator=(const TripReservation& other);
	//Destructor

	// == operator
	bool operator==(const TripReservation& other) const;
    // Getters
    Date getDate() const;

    // Setters
    bool setDate(const Date& date);

    int getRidePrice(Ride& ride);

};

#endif // TRIPRESERVATION_H

