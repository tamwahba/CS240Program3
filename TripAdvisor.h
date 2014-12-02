#ifndef TRIPADVISOR
#define TRIPADVISOR

#include <list>
#include <string>
using namespace std;

#include "Flight.h"
#include "City.h"
#include "Time.h"
#include "Date.h"

class TripAdvisor
{
	public:
		TripAdvisor();
		// creates new city and adds it to list of citys if new, 
		//  then adds flight to the list of outbound flights
		//  from departure city.
		void addFlight(sting);
		// return ordered list of flights. take in origin name, destination
		list<Flight> getMeThere(string, string);
		list<Flight> fewestHops(string, string);
		list<Flight> shortestTrip(string, string);


	private:
		list<City*> cities;

	
};

#endif