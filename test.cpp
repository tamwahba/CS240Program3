#include <iostream>

using namespace std;

#include "Time.h"

void TimeTest() {
	Time first (12,30);
	Time second (22,12);
	Time third (3,48);
	Time fourth = first + second;
	Time fifth = first + third;
	Time sixth = first - third;
	
	cout << first << second << third << endl;
	cout <<"12:30pm + 10:12pm " << fourth << endl;
	cout << "12:30 + 3:48am " << fifth << endl;
	cout << "12:30 - 3:48am " << sixth << endl;
}

int main(int argc, char const *argv[])
{	
	TimeTest();
	return 0;
}