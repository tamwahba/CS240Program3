#include <iostream>

using namespace std;

#include "Time.h"
#include "Date.h"

void TimeTest() {
	Time first (12,30);
	Time second (22,12);
	Time third (3,48);
	Time fourth = first + second;
	Time fifth = first + third;
	Time sixth = first - third;
	
	cout << first << second << third << endl;
	cout <<"12:30pm + 10:12pm " << fourth << endl;
	cout << "12:30 + 3:48am " << fifth << endl;
	cout << "12:30 - 3:48am " << sixth << endl;
}

void DateTest() {
	Date d1(5, 28, 1994);
	Date d2(5, 28, 2014);
	Date d3(5, 28, 2014);
	Date d4(1, 1, 2001);
	
	cout << d1 << " < " << d2 << ": " << d1 < d2 << '\t' << '1' << endl;
	cout << d1 << " > " << d2 << ": " << d1 > d2 << '\t' << '0' << endl;
	cout << d1 << " == " << d2 << ": " << d1 == d2 << '\t' << '0' << endl;
	cout << d1 << " != " << d2 << ": " << d1 != d2 << '\t' << '1' << endl;
	cout << d2 << " == " << d3 << ": " << d2 == d3 << '\t' << '1' << endl;
	cout << d3 << " < " << d4 << ": " << d3 < d4 << '\t' << '0' << endl;
}

int main(int argc, char const *argv[])
{	
	TimeTest();
	DateTest();
	return 0;
}