#include "Flight.h"

Flight::Flight() {
	cost = 0;
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