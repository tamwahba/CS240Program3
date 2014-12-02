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

	private:
		int cost;
		Time depart;
		Time duration;
		City* destination;
	
};

#endif