#ifndef FLIGHT
#define FLIGHT

#include <string>
using namespace std;

class Flight;

#include "City.h"

class Flight
{
	public:
		Flight();
		int getCost();
		Time getDeparture();
		Time getDuration();
		Time getArrival();
		City* getDestination(); // ALLOWS CHANGES TO CITY FROM ANYWHERE
		
		friend ostream& operator<<(ostream&, const Flight&);

	private:
		int cost;
		Time depart;
		Time duration;
		City* destination;
	
};

#endif