#include "Time.h"
#include <iostream>


Time::Time()
{
	hour = minute = 0;
}

// Assumes param h 0-23 hours, m 0-59 minutes
Time::Time (int h, int m)
{
	hour = h;
	minute = m;
}
Time::Time (int m) {
	hour = m / 60;
	minute = m % 60;
}
Time:: Time(const Time & aTime)
{
	hour = minute = 0;
	//Copying via assignment operator
	*this = aTime;
}

int Time::getMinute(){
	return minute;
}
int Time::getHour() {
	return hour;
}
int Time::getAsMinutes() {
	return (hour *60) + minute;
}
bool Time::isNull () const {
	return ( (hour == 0 ) && (minute == 0) );
}

// Return int instead of Time class?
Time Time::operator+ (const Time& rhs) const {
	int newHour = hour +rhs.hour + ((minute + rhs.minute) / 60);
	int newMinute = (minute + rhs.minute) % 60;
	// cout << "newHour " << newHour << "newMinute " << newMinute << endl;
	
	if (newHour >= 24 || newHour < 0 || newMinute <0 || newMinute >= 60) {
		return Time();
	}
	else {
		return Time (newHour, newMinute);
	}
}
Time Time::operator- (const Time & rhs) const {
	
	
	int newHour = hour -rhs.hour - ((minute + rhs.minute) / 60);
	int newMinute = (minute - rhs.minute);
	if ( (minute - rhs.minute) < 0) {
		newMinute = 60+ newMinute;
	}
	if (newHour >= 24 || newHour < 0 || newMinute <0 || newMinute >= 60) {
		return Time();
	}
	else {
		return Time (newHour, newMinute);
	}
}
// Checks out of range hours (above 23:59 time)
// like if two times + =>24 it returns a null time obj


bool Time::operator>(const Time& rhs) const {
	if (hour > rhs.hour)
		return true;
	if (minute > rhs.minute && hour == rhs.hour)
		return true;
	return false;
}

bool Time::operator<(const Time& rhs) const {
	if (hour < rhs.hour)
		return true;
	if (minute < rhs.minute && hour == rhs.hour)
		return true;
	return false;
}

bool Time::operator==(const Time& rhs) const {
	if (hour == rhs.hour && minute == rhs.minute)
		return true;
	return false;
}
Time &Time::operator=(const Time& right) {
	//cout << "Called assignment operator. Time class" << endl;
	
	hour = right.hour;
	minute = right.minute;
	
	return (*this);
}

ostream& operator<<(ostream& out, const Time& time) {
	Time copy = time;
	int twelveHRS, min;
	bool am = true;
	if (time.isNull() ) {
		out << time.hour << ':' << time.minute << endl;
	}
	else {
		if (copy.hour == 0) { twelveHRS = 12; }
		else if (copy.hour < 12 && copy.hour > 0) { twelveHRS = copy.hour; }
		else if (copy.hour == 12) { twelveHRS = 12; am = false; }
		else if (copy.hour > 12 && copy.hour < 24) { twelveHRS = copy.hour %12; am = false; }
		if ( (copy.minute > 0) && (copy.minute < 60) ) { min = copy.minute; }
		else { out << "Error time out of bounds " << endl; }
		
		if (am) {
			out << twelveHRS << ':' <<min << " am ";
		}
		else {
			out << twelveHRS << ':'<< min <<" pm ";
		}
	}
	
	
	return out;
}