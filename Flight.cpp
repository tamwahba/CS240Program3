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

int Flight::getCost() const {
	return cost;
}

Time Flight::getDeparture() const {
	return depart;
}

Time Flight::getDuration() const {
    return duration;
}

Time Flight::getArrival() const {
	return depart + duration;
}

City* Flight::getDestination() {
	return destination;
}

City* Flight::getOrigin() {
	return origin;
}

bool Flight::operator==(const Flight& rhs) const {
    return (cost == rhs.cost) && (depart == rhs.depart) && (duration == rhs.duration)
        && (origin == rhs.origin) && (destination == rhs.destination);
}

ostream& operator<<(ostream& out, const Flight& flight) {
	out << flight.origin->getName() << ' ' << flight.destination->getName() 
        << ' ' << flight.depart << ' ' << flight.depart + flight.duration 
        << " $" << flight.cost;
	return out;
}
