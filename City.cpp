#include "City.h"

City::City() {
	
}

string City::getName() {
	return name;
}

list<Flight> City::getOutboundFlights() {
	return outbound;
}

void City::addFlight(Flight flight) {
	outbound.push_back(flight);
}
