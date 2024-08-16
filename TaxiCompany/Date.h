#ifndef DATE_H
#define DATE_H


class Date {

private:
    int day;
    int month;
    int year;


public:
    Date(int d=1, int m=1, int y=2000);        // Constructor

	bool operator==(const Date& other) const;
   
    // Getters
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Setters
    bool setDay(int d);
    bool setMonth(int m);
    bool setYear(int y);

	static Date ParseDate(const char* date);        
};

#endif // DATE_H
