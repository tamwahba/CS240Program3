#include "TripAdvisor.h"

TripAdvisor::TripAdvisor() {
	
}

TripAdvisor::~TripAdvisor() {
    for (auto it = cities.begin(); it != cities.end(); it++) {
        delete *it;
    }
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
    if (departT == "pm" && departHour < 12)
        departHour += 12;
    if (arriveT == "pm" && arriveHour < 12)
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

list<Flight> TripAdvisor::getMeThere(searchParams p) {
    list<Flight> flights, fls, flsBack;
    cout << "getMeThere called" << endl;
    fls = shortestTrip(p);
    if (sumDuration(fls)) {
        cout << "forward trip valid" << endl;
        City* temp = p.departCity;
        p.departCity = p.arriveCity;
        p.arriveCity = temp;
        flsBack = shortestTrip(p);
        //fls.splice(fls.end(), flsBack);
        if (sumDuration(fls)) {
            cout << "total trip valid" << endl;
            return fls;
        }
    }
    cout << "trip too long" << endl;
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
                cout << "adding flight: " << *fIT << endl;
                q.push(fIT->getDestination());
            }
        }
    }
    City* o = flights.back().getDestination();
    // empty flights if no path is found
    if (flights.back().getDestination() != p.arriveCity) {
        flights.clear();
    }
    list<Flight> finalF;
    for (list<Flight>::reverse_iterator it = flights.rbegin(); it != flights.rend(); it++) {
    	if (it->getDestination() == o) {
    		finalF.push_front(*it);
    		o = it->getOrigin();
    	}
    }
    return finalF;
}

list<Flight> TripAdvisor::shortestTrip(searchParams p) {
    cout << "shortestTrip called" << endl;
    vector<City*> v;
    vector<list<Flight>> flights(cities.size());
    vector<pair<int, int>*> q(cities.size());
    vector<City*> c(cities.size()); // completely and utterly redundant. but no choice
    int i = 0;
    for (list<City*>::iterator it = cities.begin(); it != cities.end(); it++) {
        q[i] = new pair<int, int>(i, numeric_limits<int>::max());
        c[i] = *it;
        if (*it == p.departCity) {
            q[i]->second = 0;
            cout << "setting origin dist to 0" << endl;
        }
        i++;
    }
    cout << "initializied. q has " << i << " items"  << endl;
    for (int i = 0; i < q.size(); i++) {
        cout << "\t<" << q[i]->first << " " << q[i]->second << ">" << endl;
    }
    bool empty = false;
    while (!empty) {
        cout << "looping" << endl;
        pair<int, int> current  = extractMin(q, empty);
        int currentIdx = current.first;
        int currentDist = current.second;
        if (empty || c[currentIdx] == p.arriveCity) {
            cout << "cleaning up" << endl;
            //cleanup
            for (int i = 0; i < q.size(); i++) {
                if (q[i] != nullptr)
                    delete q[i];
            }
		    list<Flight> l;
		    cout << "returning shortestTrip" << endl;
            return empty ? l : flights[currentIdx];
        }
        list<Flight> neighbors = c[currentIdx]->getOutboundFlights();
        for (list<Flight>::iterator it = neighbors.begin();
                it != neighbors.end(); it++) {
            int layover = 0;
            if (!flights[currentIdx].empty()) {
                if (flights[currentIdx].back().getArrival() > it->getDeparture()) {
                    layover += (24 * 60);
                }
                layover += (it->getDeparture() - flights[currentIdx].back().getArrival()).getAsMinutes();
            }
            int alt = currentDist + it->getDuration().getAsMinutes() + layover;
            int neighborIdx = -1;
            for (int i = 0; i < c.size(); i++) {
                if (c[i] == it->getDestination()) {
                    neighborIdx = i;
                    break;
                }
            }
            int neighborqIdx = -1;
            for (int i = 0; i < q.size(); i++) {
                if (neighborIdx != -1 && q[i] != nullptr && q[i]->first == neighborIdx) {
                    neighborqIdx = i;
                    break;
                }
            }
            if (neighborqIdx != -1 && q[neighborqIdx] != nullptr && alt < q[neighborqIdx]->second) {
                q[neighborqIdx]->second = alt;
                list<Flight> temp = flights[currentIdx];
                temp.push_back(*it);
                flights[neighborIdx] = temp;
            }
        }
        cout << "end of loop" << endl;
    }
}


pair<int, int> extractMin(vector<pair<int, int>*>& v, bool& empty) {
    cout << "extract min called" << endl;
    pair<int, int> min(-1, numeric_limits<int>::max());
    int minIdx = -1;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != nullptr && v[i]->second < min.second){
            min = *v[i];
            minIdx = i;
            cout << "found smaller: <" << min.first << ' ' << min.second << '>' << endl;
        }
    }
    cout << "smallest: <" << min.first << ' ' << min.second << '>' << endl;
    if (minIdx == -1){
        empty = true;
    } else {
        delete v[minIdx];
        v[minIdx] = nullptr;
        if (v[minIdx] == nullptr)
            cout << "deleted" << endl;
    }
    cout << "exiting extract min. empty: " << empty  << endl;
    return min;
}
