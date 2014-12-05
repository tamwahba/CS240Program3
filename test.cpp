#include <iostream>
#include <fstream>

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
	string selection;
	TripAdvisor t;
	if (argc == 2) {
		ifstream in (argv[1]);
		string line;
		if (in.is_open() )
		{
			while (!in.eof() )
			{
				getline (in, line);
				t.addFlight(line);
			}
		}
		if (!in.is_open() )
		{
			cout << "Error opening file " <<endl;
		}
	}
		while (true)
		{
			string c; //char c?
			cout << "Please select one of the following options" << endl;
			cout <<"\t J: Just get me there" << endl;
			cout << "\t F: Fewest Hops" << endl;
			cout << "\t S: Shortest Trip" << endl;
			cout << "\t C: Cheapest" << endl;
			cout << "or press e to end" << endl;
			cin >> c;
			
			if (c== "J" || c== "j") {
                cout << "pressed J" << endl;
            }
				//t.JustGetMeThere();
            else if (c == "F" || c== "f") {
                cout << "selected F" << endl;
            }
					//t.FewestHops();
            else if (c == "S" || c== "s") {
                cout << "selected S" << endl;
            }
						//t.ShortestTrip();
            else if (c == "C" || c== "c") {
                cout << "selected C" << endl;
            }
							//t.Cheapest()
            else if (c == "e" ) {break;}
			else {
				cout << "Error please enter J, F,C, or S" << endl;
			}
		}
	TimeTest();
	DateTest();
    TripAdvisorTest();
    return 0;
}

