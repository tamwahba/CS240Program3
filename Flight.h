#ifndef FLIGHT
#define FLIGHT

#include <string>
using namespace std;

#include "Time.h"

class Flight;

#include "City.h"

class Flight
{
	public:
		Flight();
		Flight(int, Time, Time, City*, City*);
		int getCost() const;
		Time getDeparture() const;
		Time getDuration() const;
		Time getArrival() const;
		City* getDestination(); // ALLOWS CHANGES TO CITY FROM ANYWHERE
		City* getOrigin();
	
        bool operator==(const Flight&) const;    
		friend ostream& operator<<(ostream&, const Flight&);

	private:
		int cost;
		Time depart;
		Time duration;
		City* origin;
		City* destination;
	
};

bool sumDuration(list<Flight>&);

#endif
