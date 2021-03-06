#ifndef DATE
#define DATE

#include <iostream>
#include <iomanip>
using namespace std;

class Date
{
public:
    Date();
    Date(int, int, int);
	Date(unsigned long long);
	
	int getDay();
	int getMonth();
	int getYear();
	
	bool operator>(const Date&) const;
	bool operator<(const Date&) const;
	bool operator==(const Date&) const;
	bool operator!=(const Date&) const;
    bool operator!() const;

	friend ostream& operator<<(ostream&, const Date&);
    friend istream& operator>>(istream&, Date&); 

private:
	int day;
	int month;
	int year;
	unsigned long long days; // reprents days since year 0000. 
	// formulas from: http://alcor.concordia.ca/~gpkatch/gdate-algorithm.html
	
};

#endif
