#include <iostream>
#include <fstream>
using namespace std;

#include "Time.h"
#include "Date.h"
#include "City.h"
#include "Flight.h"
#include "TripAdvisor.h"

int main(int argc, char const *argv[])
{
	string selection;
	TripAdvisor t;
	if (argc == 2) {
		ifstream in (argv[1]);
		string line;
		if (in.is_open() )
		{
			while (!in.eof() )
			{
				getline (in, line);
				t.addFlight(line);
			}
		} else {
			cout << "Error opening file " <<endl;
		}
		while (true)
		{
			string c; //char c?
			cout << "Please select one of the following options" << endl;
			cout <<"\t J: Just get me there" << endl;
			cout << "\t F: Fewest Hops" << endl;
			cout << "\t S: Shortest Trip" << endl;
			cout << "\t C: Cheapest" << endl;
			cout << "or press E to end" << endl;
			
			cin >> c;
			
			if (c== "J" || c== "j") {
				cout << "selected J" << endl;
				//t.JustGetMeThere();
			} else if (c == "F" || c== "f") {
				cout << "selected F" << endl;
				//t.FewestHops();
			} else if (c == "S" || c== "s") {
				cout << "selected S" << endl;
				//t.ShortestTrip();
			} else if (c == "C" || c== "c") {
				cout << "selected C" << endl;
				//t.Cheapest()
			} else if (c == "E" ) {
				break;
			} else {
				cout << "Error please enter J, F,C, or S." << endl;
			}
		}
	} else {
		cout << "Cannot run program without DDFS file as argument." << endl;
	}
	return 0;
}
