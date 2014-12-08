#ifndef TRIPADVISOR
#define TRIPADVISOR

#include <list>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
using namespace std;

#include "Flight.h"
#include "City.h"
#include "Time.h"
#include "Date.h"

struct compareDuration {
    bool operator()(list<Flight>*& lhs, list<Flight>*& rhs) {
        int lhsD = 0;
        int rhsD = 0;
        for (list<Flight>::const_iterator it = lhs->begin(); it != lhs->end(); it++) {
            int layover = 0;
            if (next(it) != lhs->end()) {
                if ((next(it))->getDeparture() < it->getArrival()) {
                    layover += (24 * 60);
                }
                layover += ((next(it))->getDeparture() - it->getArrival()).getAsMinutes();
            }
            lhsD += it->getDuration().getAsMinutes() + layover;
        }
        for (list<Flight>::const_iterator it = rhs->begin(); it != rhs->end(); it++) {
            int layover = 0;
            if ((next(it)) != rhs->end()) {
                if ((next(it))->getDeparture() < it->getArrival()) {
                    layover += (24 * 60);
                }
                layover += (next(it)->getDeparture() - it->getArrival()).getAsMinutes();
            }
            rhsD += it->getDuration().getAsMinutes() + layover;
        }
        return lhsD > rhsD;
    }
};

struct searchParams {
    City* departCity;
    City* arriveCity;
    Date departDate;
    Time departTime;
    Date arriveDate;
    Time arriveTime;
};

class TripAdvisor {
	public:
		TripAdvisor();
		
		// creates new city and adds it to list of citys if new, 
		//  then adds flight to the list of outbound flights
		//  from departure city.
		void addFlight(string);

        City* getCity(string);
    
		// return ordered list of flights. if no path found, list is empty
		list<Flight> getMeThere(searchParams);
		list<Flight> fewestHops(searchParams);
		list<Flight> shortestTrip(searchParams);
		
		void printCitiesTo(ostream&);

	private:
		list<City*> cities;

};

pair<int, int> extractMin(vector<pair<int, int>*>&, bool&);

#endif
