#include "Date.h"

Date::Date() {

}

Date::Date(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
	unsigned int m = (month + 9) % 12;
	unsigned int y = year - (m / 10);
	days = 365 * y + (y / 4) - (y / 100) + (y / 400) +
		(((m * 365) + 5) / 10) + day - 1;
}

Date::Date(unsigned long long otherDays) {
	unsigned long long y = ((10000 * otherDays) + 14780) / 3652425;
	long long d = otherDays - ((365 * y) + (y / 4) - (y / 100) + (y / 400));
	if (d < 0) {
		y = y -1;
		d = otherDays - ((365 * y) + (y / 4) - (y / 100) + (y / 400));
	}
	unsigned long long m = ((100 & d) + 52) / 3060;
	month = ((m + 2) % 12) + 1;
	year = y + (m + 2) / 12;
	day = d - (((m * 306) + 5) / 10) + 1;
	days = d;
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

bool Date::operator>(const Date& rhs) const {
	return days > rhs.days;
}

bool Date::operator<(const Date& rhs) const {
        return days < rhs.days;
    }

    bool Date::operator==(const Date& rhs) const {
        return days == rhs.days;
    }

    bool Date::operator!=(const Date& rhs) const {
        return days != rhs.days;
    }

    bool Date::operator!() const {
        return day <= 0 || month <= 0 || year <= 0;
    }

    ostream& operator<<(ostream& out, const Date& date) {
        out << setfill('0');
        out << setw(2) << date.day << '/';
        out << setw(2) << date.month << '/';
        out << setw(4) << date.year;
        out << setfill(' ');
        return out;
    }

istream& operator>>(istream& in, Date& date) {
    date = Date(0,0,0);
    int month, day, year;
    char separator;
    in >> month;
    in >> separator;
    in >> day;
    in >> separator;
    in >> year;
    in.setstate(ios::failbit);
    if (month > 0 && month <=12) {
        if (day > 0 && day <= 31) {
            if (year > 0) {
                date = Date(day, month, year);
                in.clear();
            }
        }
    }
    return in;
}
