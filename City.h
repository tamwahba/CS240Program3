#ifndef CITY
#define CITY

#include <string>
#include <list>
using namespace std;

class City;

#include "Flight.h"

class City
{
	public:
		City();
		string getName();
		list<Flight> getOutboundFlights();
		
		void addFlight(Flight);

	private:
		string name;
		list<Flight> outbound;
	
};

#endif