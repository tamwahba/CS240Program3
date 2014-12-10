#ifndef TIME
#define TIME

#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
public:
	Time ();
	Time (int, int);
	Time (int);
	Time (const Time&);
	
	int getMinute() const;
	int getHour() const;
	int getAsMinutes() const;
	bool isNull() const;
	
	Time operator+(const Time&) const;
	Time operator-(const Time&) const;
	bool operator>(const Time&) const;
	bool operator<(const Time&) const;
	bool operator==(const Time&) const;
	bool operator>=(const Time&) const;
    bool operator<=(const Time&) const;
    Time& operator+=(const Time&);
    operator bool() const;
    bool operator!() const;
    //Time &operator= (const Time &right);

	
	friend ostream& operator<< (ostream&, const Time&);
    friend istream& operator>> (istream&, Time&);

private:
    int minutes;
	//bool am;
	
};




#endif
