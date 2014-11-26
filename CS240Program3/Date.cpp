#include "Date.h"

Date::Date(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

int Date::getDay() {
	return day;
}

int Date::getMonth() {
	return month;
}

int Date::getYear() {
	return year;
}

Date Date::operator+(const Date& rhs) const {
	//assumes all months have 30 days;
	int newDay = (day + rhs.day) % 30;
	int newMonth = month + ((day + rhs.day) / 30) % 12;
	int newYear = year + (month + (day + rhs.day) / 30) / 12;
	return Date(newDay, newMonth, newYear);
}

bool Date::operator>(const Date& rhs) const {
	if (year > rhs.year)
		return true;
	if (month > rhs.month && year == rhs.year)
		return true;
	if (day > rhs.day && month == rhs.month && year == rhs.year)
		return true;
	return false;
}

bool Date::operator<(const Date& rhs) const {
	if (year < rhs.year)
		return true;
	if (month < rhs.month && year == rhs.year)
		return true;
	if (day < rhs.day && month == rhs.month && year == rhs.year)
		return true;
	return false;
}

bool Date::operator==(const Date& rhs) const {
	if (day == rhs.day && month == rhs.month && year == rhs.year)
		return true;
	return false;
}

ostream& operator<<(ostream& out, const Date& date) {
	out << date.day << '/' << date.month << '/' << date.year << endl;
	return out;
}