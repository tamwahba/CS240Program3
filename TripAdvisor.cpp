#include "TripAdvisor.h"

TripAdvisor::TripAdvisor() {
	
}

void TripAdvisor::addFlight(string flightStr) {
	string originName, destinationName;
	int departHour, departMinute, arriveHour, arriveMinute, cost;
	stringstream ss(flightStr);
	ss >> originName;
	ss >> destinationName;
	ss >> departHour;
	ss.ignore(1, ':');
	ss >> departMinute;
	ss >> arriveHour;
	ss.ignore(1, ':');
	ss >> arriveMinute;
	ss.ignore(2, '$');
	ss >> cost;
	City* origin;
	City* destination;
	// find departure and origin city in cities
	for (list<City*>::iterator it = cities.begin(); it != cities.end(); it++) {
		if ((*it)->getName() == originName) {
			origin = *it;
		}
		if ((*it)->getName() == destinationName) {
			destination = *it;
		}
		// stop looping if both found
		if (origin != nullptr && destination != nullptr)
			break;
	}
	// add new city if it's not in the list
	if (origin == nullptr) {
		origin = new City(originName);
		cities.push_back(origin);
	}
	if (destination == nullptr) {
		destination = new City(destinationName);
		cities.push_back(origin);
	}
	
	// create the flight
	Flight f(cost, Time(departHour, departMinute), Time(arriveHour, arriveMinute), origin, destination);
	origin->addFlight(f);	
}

void TripAdvisor::printCitiesTo(ostream& out) {
	for (list<City*>::iterator cIT = cities.begin(); cIT != cities.end(); cIT++) {
		list<Flight> cityFlights = (*cIT)->getOutboundFlights();
        for (list<Flight>::iterator fIT = cityFlights.begin(); fIT != cityFlights.end(); fIT++) {
            out << *fIT << endl;
        }
	}
}
