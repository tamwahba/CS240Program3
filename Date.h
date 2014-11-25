#ifndef DATE
#define DATE

#include <ostream>
using namespace std;

class Date
{
public:
	Date(int, int, int);
	
	int getDay();
	int getMonth();
	int getYear();
	
	Date operator+(const Date&) const;
	bool operator>(const Date&) const;
	bool operator<(const Date&) const;
	bool operator==(const Date&) const;
	
	friend ostream& operator<<(ostream&, const Date&);
	
private:
	int day;
	int month;
	int year;	
};

#endif