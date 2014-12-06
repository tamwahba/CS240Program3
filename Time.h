#ifndef TIME
#define TIME

#include <iostream>
using namespace std;

class Time
{
public:
	Time ();
	Time (int, int);
	Time (int);
	Time (const Time & aTime);
	
	int getMinute();
	int getHour();
	int getAsMinutes();
	bool isNull() const;
	
	Time operator+(const Time&) const;
	Time operator-(const Time&) const;
	bool operator>(const Time&) const;
	bool operator<(const Time&) const;
	bool operator==(const Time&) const;
	Time &operator= (const Time &right);
	
	friend ostream& operator<< (ostream&, const Time&);
    friend istream& operator>> (istream&, Time&);

private:
	int hour;
	int minute;
	//bool am;
	
};




#endif
