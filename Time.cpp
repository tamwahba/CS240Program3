#include "Time.h"
#include <iostream>


Time::Time() {
	minutes = -1;
}

Time::Time (int h, int m) {
    if (h < 24 && m < 60)
        minutes = (h * 60) + m;
}

Time::Time (int m) {
    if ((m < (23 * 60) + 59) && m >= 0)
        minutes = m;
}

Time::Time(const Time & aTime) {
	minutes = aTime.minutes;
}

int Time::getMinute() const {
	return minutes % 60;
}

int Time::getHour() const {
    return (((minutes / 60) % 12) == 0 ? 12 : (minutes / 60) % 12);
}

int Time::getAsMinutes() const {
	return minutes;
}

bool Time::isNull () const {
	return !(*this);
}

Time Time::operator+(const Time& rhs) const {
    return Time(minutes + rhs.minutes);
}

Time Time::operator-(const Time & rhs) const {	
    return Time(minutes - rhs.minutes);
}

bool Time::operator>(const Time& rhs) const {
	return minutes > rhs.minutes;
}

bool Time::operator<(const Time& rhs) const {
	return minutes < rhs.minutes;
}

bool Time::operator==(const Time& rhs) const {
	return minutes == rhs.minutes;
}

bool Time::operator>=(const Time& rhs) const {
    return minutes >= rhs.minutes;
}

bool Time::operator<=(const Time& rhs) const {
    return minutes <= rhs.minutes;
}

Time& Time::operator+=(const Time& rhs) {
    minutes += rhs.minutes;
    if (minutes >= (24 * 60))
        minutes = -1;
    return *this;
}

Time::operator bool() const {
    return minutes >= 0;
}

bool Time::operator!() const {
    return minutes < 0;
}

ostream& operator<<(ostream& out, const Time& time) {
    out << time.getHour() << ':' << time.getMinute();
    out << (time < Time(11,59) ? "am" : "pm");
	return out;
}

istream& operator>>(istream& in, Time& time) {
    int hour, min;
    string pm;
    in >> hour;
    in.ignore(1, ':');
    in >> min;
    if (in.good())
        in >> pm;
    if ((pm == "pm" || pm == "pm") && hour > 12)
        hour += 12;
    time = Time(hour, min);
    if (!time) {
        in.setstate(ios::failbit);
    }
    return in;
}
