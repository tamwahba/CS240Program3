#include <iostream>
#include <fstream>
using namespace std;

#include "Time.h"
#include "Date.h"
#include "City.h"
#include "Flight.h"
#include "TripAdvisor.h"

struct searchParams {
    City* departCity;
    City* arriveCity;
    Date departDate;
    Time departTime;
    Date arriveDate;
    Time arriveTime;
};

// returns data for search converted from input strings to proper types
// error checking occurs here, future functions could assume all data 
// returned to be valid. if user chooses to quit, returns null.
searchParams getConstraints(TripAdvisor& t) {
    string departName, arriveName, departDate, departTime;
    string returnDate, returnTime;
    searchParams p;
    cout << "Enter departure city: ";
    getline(cin ,departName);
    // convert to city* by searching in t
    // then p.departCity = result. or keep looping
    cout << "Enter arrival city: ";
    getline(cin, arriveName);
    cout << "Enter departure date (mm/dd/yyy): ";
    getline(cin, departDate);
    cout << "Enter departure time (hh:mm): ";
    getline(cin, departTime);
    cout << "Enter return date (mm/dd/yyy): ";
    getline(cin, returnDate);
    cout << "Enter return time (hh:mm): ";
    getline(cin, returnTime);
    return p;
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
		} else {
			cout << "Error opening file " <<endl;
		}
		while (true)
		{
			string c; //char c?
			cout << "Please select one of the following options" << endl;
			cout <<"\t J: Just get me there" << endl;
			cout << "\t F: Fewest Hops" << endl;
			cout << "\t S: Shortest Trip" << endl;
			cout << "\t C: Cheapest" << endl;
			cout << "or press E to end" << endl;
			
			cin >> c;
			
			if (c== "J" || c== "j") {
				cout << "selected J" << endl;
				//t.JustGetMeThere();
			} else if (c == "F" || c== "f") {
				cout << "selected F" << endl;
				//t.FewestHops();
			} else if (c == "S" || c== "s") {
				cout << "selected S" << endl;
				//t.ShortestTrip();
			} else if (c == "C" || c== "c") {
				cout << "selected C" << endl;
				//t.Cheapest()
			} else if (c == "E" ) {
				break;
			} else {
				cout << "Error please enter J, F,C, or S." << endl;
			}
		}
	} else {
		cout << "Cannot run program without DDFS file as argument." << endl;
	}
	return 0;
}
