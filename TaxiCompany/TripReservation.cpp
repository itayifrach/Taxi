#include "TripReservation.h"

// Parameterized Constructor
TripReservation::TripReservation(int id, int passengers, int time, const Address& origin, const Address& dest,
    const Payment& pay, Customer& cust, Driver& drv, const Date& date)
    : Ride(id, passengers, time, origin, dest, pay, cust, drv), date(date) {}

TripReservation::TripReservation(Ride ride, const Date& date)
    : Ride(ride), date(date) {}


bool TripReservation::operator==(const TripReservation& other) const
{
	if (rideID == other.rideID && numberOfPassengers == other.numberOfPassengers && rideTime == other.rideTime &&
		originAddress == other.originAddress && destAddress == other.destAddress && payment == other.payment &&
		customer == other.customer && driver == other.driver && date == other.date)
		return true;
    return false;
}

// Getter for Date
Date TripReservation::getDate() const {
    return date;
}

// Setter for Date
bool TripReservation::setDate(const Date& date) {
    this->date = date;
    return true;
}

// Example Method to Calculate Ride Price
int TripReservation::getRidePrice(Ride& ride) {
    // You can implement your own logic to calculate the ride price
    return ride.getNumberOfPassengers() * 150;  // Example: price based on the number of passengers
}
