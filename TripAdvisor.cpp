#include "TripAdvisor.h"

TripAdvisor::TripAdvisor() {
	
}

void TripAdvisor::addFlight(string flightStr) {
	string originName, destinationName, departT, arriveT;
	int departHour, departMinute, arriveHour, arriveMinute, cost;
	stringstream ss(flightStr);
    ss >> originName;
	ss >> destinationName;
	ss >> departHour;
	ss.ignore(1, ':');
	ss >> departMinute;
    ss >> departT;
	ss >> arriveHour;
	ss.ignore(1, ':');
	ss >> arriveMinute;
    ss >> arriveT;
	ss.ignore(2, '$');
	ss >> cost;
    City* origin = nullptr;
	City* destination = nullptr;
    if (departT == "pm")
        departHour += 12;
    if (arriveT == "pm")
        arriveHour += 12;
    // find departure and origin city in cities
    if (!cities.empty()) {
        for (list<City*>::iterator it = cities.begin(); it != cities.end(); it++) {
		    if ((*it)->getName() == originName) {
		    	origin = *it;
	    	}
    		if ((*it)->getName() == destinationName) {
			    destination = *it;
		    }
		    // stop looping if both found
		    if (origin != nullptr && destination != nullptr) {
                break;
            }
    	}
    }
	// add new city if it's not in the list
	if (origin == nullptr) {
		origin = new City(originName);
		cities.push_back(origin);
	}
	if (destination == nullptr) {
		destination = new City(destinationName);
		cities.push_back(destination);
    }
    // create the flight
	Flight f(cost, Time(departHour, departMinute), Time(arriveHour, arriveMinute), origin, destination);
	origin->addFlight(f);	
}

City* TripAdvisor::getCity(string name) {
    City* ret = nullptr;
    if (!cities.empty()) {
        for (list<City*>::iterator it = cities.begin(); it != cities.end(); it++) {
            if ((*it)->getName() == name) {
                ret = *it;
                break;
            }
        }
    }
    return ret;
}

void TripAdvisor::printCitiesTo(ostream& out) {
	for (list<City*>::iterator cIT = cities.begin(); cIT != cities.end(); cIT++) {
		list<Flight> cityFlights = (*cIT)->getOutboundFlights();
        for (list<Flight>::iterator fIT = cityFlights.begin(); fIT != cityFlights.end(); fIT++) {
            out << *fIT << endl;
        }
	}
}

list<Flight> TripAdvisor::getMeThere(searchParams) {
    list<Flight> flights;
    cout << "getMeThere called" << endl;
    return flights;
}

list<Flight> TripAdvisor::fewestHops(searchParams p) {
    list<Flight> flights;
    cout << endl << "fewestHops called with parameters:" << endl;
    cout << "depart: " << p.departCity->getName() << endl;
    cout << "return: " << p.arriveCity->getName() << endl;
    cout << endl;
    queue<City*> q; // to visit next
    vector<City*> v; // visited
    v.push_back(p.departCity);
    q.push(p.departCity);
    while (!q.empty()) {
        City* c = q.front();
        q.pop();
        cout << "visited node: " << c->getName() << endl;
        if (c == p.arriveCity)
            break;
        list<Flight> fs = c->getOutboundFlights();
        for (list<Flight>::iterator fIT = fs.begin(); fIT != fs.end(); fIT++) {
            bool visitedFIT = false;
            for (int i = 0; i < v.size(); i++) {
                if (v[i] == fIT->getDestination())
                    visitedFIT = true;
            }
            if (!visitedFIT) {
                v.push_back(fIT->getDestination());
                flights.push_back(*fIT);
                q.push(fIT->getDestination());
            }
        }
    }
    // v has all the cities from departure to arrival (or all reachable cities
    //   for now)
    // Does not take into account maintaining time (for now ...).
    return flights;
}

list<Flight> TripAdvisor::shortestTrip(searchParams) {
    cout << "shortestTrip called" << endl;
}
