#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

#include "Time.h"
#include "Date.h"
#include "City.h"
#include "Flight.h"
#include "TripAdvisor.h"

// returns data for search converted from input strings to proper types
// error checking occurs here, future functions could assume all data 
// returned to be valid. if user chooses to quit, returns null.
bool getConstraints(TripAdvisor& t, searchParams& p) {
    // t.printCitiesTo(cout);
    string departName, arriveName;
    City* departCity = nullptr;
    City* returnCity = nullptr;
    Time departTime, returnTime;
    Date departDate, returnDate;

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (cin.good()) {
        cout << "Enter departure city: ";
        getline(cin, departName);
        // cout << "you entered: " << departName << endl; // temporary for testing
        departCity = t.getCity(departName);
        if (departCity != nullptr) {
            p.departCity = departCity;
            break;
        } else {
            if (cin.eof()) {
                cout << "break" << endl;
                break;
            }
            cout << "City not in schedule. Please try again." << endl;
            //cin.clear();
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // convert to city* by searching in t
    // then p.departCity = result. or keep looping
    while (cin.good()) {
        cout << "Enter arrival city: ";
        getline(cin, arriveName);
        // cout << "you entered: " << arriveName << endl;
        returnCity = t.getCity(arriveName);
		if (arriveName == departName) {
			cout << "Must depart and arrive at two different cities " << endl;
			break;
		}else if (returnCity != nullptr) {
            p.arriveCity = returnCity;
            break;
		}else {
            if (cin.eof())
                break;
            cout << "City not in schedule. Please try again." << endl;
            //cin.clear();
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    while (cin.good()) {
        cout << "Enter departure date (mm/dd/yyyy): ";
        if (cin >> departDate) {
            p.departDate = departDate;
            // cout << "you entered: " << departDate << endl;
            break;
        } else {
            if (cin.eof())
                break;
            cout << "Invalid date. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    
    while (cin.good()) {
        cout << "Enter departure time (hh:mm): ";
        if( cin >> departTime) {
            p.departTime = departTime;
            // cout << "you entered: " << departTime << endl;
            break;
        } else {
            if (cin.eof())
                break;
            cout << "Invalid time. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    
    while (cin.good()) {
        cout << "Enter return date (mm/dd/yyyy): ";
        if (cin >> returnDate) {
            p.arriveDate = returnDate;
            // cout << "you entered: " << returnDate << endl;
            break;
        } else {
            if (cin.eof())
                break;
            cout << "Invalid date. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    
    while (cin.good()) {
        cout << "Enter return time (hh:mm): ";
        if (cin >> returnTime) {
            p.arriveTime = returnTime;
            // cout << "you entered: " << returnTime << endl;
            break;
        } else {
            if (cin.eof())
                break;
            cout << "Invalid time. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    if (!cin.good())
        return false;

    return true;
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
            while (in.good()) {
                getline(in, line, '\n');
                if (line != "") {
                    t.addFlight(line);
                }
            }
		} else {
			cout << "Error opening file " <<endl;
		}
		while (cin.good())
		{
			string c; //char c?
			cout << "Please select one of the following options" << endl;
			cout <<"\t J: Just get me there" << endl;
			cout << "\t F: Fewest Hops" << endl;
			cout << "\t S: Shortest Trip" << endl;
			cout << "\t C: Cheapest" << endl;
			cout << "or press E to end" << endl;
			
            searchParams p;
            list<Flight> itinerary, itineraryB;
			cin >> c;
            if (c == "J" || c == "j") {
				// cout << "selected J" << endl;
				if (getConstraints(t, p))
                    itinerary = t.getMeThere(p);
					//t.getMeThere(p);
			} else if (c == "F" || c == "f") {
				// cout << "selected F" << endl;
				if(getConstraints(t, p)) {
                    // cout << endl << "calling fewest hops with params:" << endl;
                    // cout << "depart: " << p.departCity->getName() << endl;
                    // cout << "arrive: " << p.arriveCity->getName() << endl;
                    itinerary = t.fewestHops(p);
                    City* tempC = p.departCity;
                    p.departCity = p.arriveCity;
                    p.arriveCity = tempC;
                    itineraryB = t.fewestHops(p);
                }
			} else if (c == "S" || c == "s") {
				// cout << "selected S" << endl;
                if (getConstraints(t, p)) {
                    itinerary = t.shortestTrip(p);
                    City* tempC = p.departCity;
                    p.departCity = p.arriveCity;
                    p.arriveCity = tempC;
                    itineraryB = t.shortestTrip(p);
                }
			} else if (c == "C" || c == "c") {
                // cout << "selected C" << endl;
                cout << "Not implemented!" << endl;
                //t.cheapest(" ", " ");
			} else if (c == "E" ) {
                // cout << "selected E" << endl;
				break;
			} else {
				cout << "Error please enter J, F,C, or S." << endl;
			}
            cin.clear();
			if (!itinerary.empty() ) {
            cout << "Your itinerary is:" << endl;
			/*
			if (itinerary.empty() ) {
				cout << "No flights available " << endl;
				if (!itineraryB.empty() ) {
					cout << "We did find return flights available, please try again with new outbound flight information " << endl;
					for (list<Flight>::iterator fIT = itineraryB.begin(); fIT != itineraryB.end(); fIT++)
						cout << *fIT << endl;
				}
			}else if (itineraryB.empty() ) {
				if (!itinerary.empty () ) {
					cout << "We did find outbound flights that work, please try again with different return information. " << endl;
					for (list<Flight>::iterator fIT = itinerary.begin(); fIT != itinerary.end(); fIT++)
						cout << *fIT << endl;
				}
				cout << "No return flights available " <endl;
			}*/
				//else {
			for (list<Flight>::iterator fIT = itinerary.begin(); fIT != itinerary.end(); fIT++)
					cout << *fIT << endl;
			if (!itineraryB.empty() ) {
				cout << "Return flights: " << endl;
				
				for (list<Flight>::iterator fIT = itineraryB.begin(); fIT != itineraryB.end(); fIT++)
					cout << *fIT << endl;
				}
				//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		}
	} else {
		cout << "Cannot run program without DDFS file as argument." << endl;
	}
	return 0;
}
