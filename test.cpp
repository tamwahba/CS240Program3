#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include "Time.h"
#include "Date.h"
#include "TripAdvisor.h"

void TimeTest() {
	cout << "TIME TEST" << endl;
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
	cout << "END TIME" << endl;
}

void DateTest() {
	cout << "DATE TEST" << endl;
	Date d1(5, 28, 1994);
	Date d2(5, 28, 2014);
	Date d3(5, 28, 2014);
	Date d4(1, 1, 2001);
    Date d5(2, 1, 2001);
	
	cout << d1 << " <  " << d2 << ": " << (d1 < d2) << " " << '1' << endl;
    cout << d1 << " >  " << d2 << ": " << (d1 > d2) << " " << '0' << endl;
	cout << d1 << " == " << d2 << ": " << (d1 == d2) << " " << '0' << endl;
	cout << d1 << " != " << d2 << ": " << (d1 != d2) << " " << '1' << endl;
    cout << d2 << " == " << d3 << ": " << (d2 == d3) << " " << '1' << endl;
	cout << d3 << " <  " << d4 << ": " << (d3 < d4) << " " << '0' << endl;
    cout << d5 << " >  " << d4 << ": " << (d5 > d4) << " " << '1' << endl;
	
    Date d6;
    Date d7;

    stringstream ss6("ewr23oij");
    stringstream ss7("12/12/2014");

    ss6 >> d6;
    ss7 >> d7;

    cout << d6 << " !(" << d6 << "): " << !d6 << " " << '1' << endl;
    cout << d7 << " !(" << d7 << "): " << !d7 << " " << '0' << endl;
    
    cout << "END DATE" << endl;
}

void TripAdvisorTest() {
    cout << "TRIPADVISOR TEST" << endl;
    TripAdvisor ta;
    ifstream fs;
    fs.open("testDDFS.txt");
    string flightStr;
    while (fs.good()) {
        getline(fs, flightStr, '\n');
        if (flightStr != "") {
            ta.addFlight(flightStr);
        }
    }
    ta.printCitiesTo(cout);
    cout << "END TRIPADVISOR" << endl;
}

int main(int argc, char const *argv[])
{
	TimeTest();
	DateTest();
    TripAdvisorTest();
    return 0;
}

