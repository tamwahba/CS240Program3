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
