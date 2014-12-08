OBJ_FILES = \
  Date.o \
  Time.o \
  Flight.o \
  City.o \
  TripAdvisor.o

CXX = g++
CXXFLAGS = -std=c++11

fly:	$(OBJ_FILES) main.o
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) main.o -o $@
	
test:	$(OBJ_FILES) test.o
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) test.o -o $@

Date.o:	Date.h Date.cpp
Time.o:	Time.h Time.cpp
Flight.o:	Flight.h Flight.cpp
City.o:	City.h City.cpp
TripAdvisor.o:	TripAdvisor.h TripAdvisor.cpp
main.o:	main.cpp
test.o:	test.cpp

clean:
	rm -rf *.o fly test

tar:
	tar cvzf Program3.tar.gz TripAdvisor.cpp TripAdvisor.h main.cpp City.h City.cpp Date.cpp Date.h Flight.cpp Flight.h test.cpp Time.h Time.cpp testDDFS.txt README.md makefile

