#include "Date.h"
#include <iostream>
// Constructor
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

bool Date::operator==(const Date& other) const
{
	if (day == other.day && month == other.month && year == other.year)
		return true;
    return false;
}

// Getters
int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

// Setters
bool Date::setDay(int d) {
    if (d < 1 || d > 31) {
        return false;  // Invalid day
    }
    day = d;
    return true;
}

bool Date::setMonth(int m) {
    if (m < 1 || m > 12) {
        return false;  // Invalid month
    }
    month = m;
    return true;
}

bool Date::setYear(int y) {
    year = y;
    return true;
}

Date Date::ParseDate(const char* date)
{
	// Parse the date string
	// The date string is in the format "dd/mm/yyyy"
	int day, month, year;
	if (sscanf(date, "%d/%d/%d", &day, &month, &year) != 3) {
		throw std::invalid_argument("Invalid date format");
	}
	return Date(day, month, year);
}
