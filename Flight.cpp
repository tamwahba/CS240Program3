#include "Flight.h"

Flight::Flight() {
	cost = 0;
}

Flight::Flight(int c, Time dp, Time arr, City* orig, City* dest) {
	cost = c;
	depart = dp;
	duration = arr - dp;
	origin = orig;
	destination = dest;
}

int Flight::getCost() {
	return cost;
}

Time Flight::getDeparture() {
	return depart;
}

Time Flight::getDuration() {
	return duration;
}

Time Flight::getArrival() {
	return depart + duration;
}

City* Flight::getDestination() {
	return destination;
}

City* Flight::getOrigin() {
	return origin;
}

ostream& operator<<(ostream& out, const Flight& flight) {
	out << flight.origin->getName() << ' ' << flight.origin->getName() << ' ' << flight.depart << ' ' 
		<< flight.depart + flight.duration << " $" << flight.cost << endl;
	return out;
}
