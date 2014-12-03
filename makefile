OBJ_FILES = \
  Date.o \
  Time.o \
  Flight.o \
  City.o \
  TripAdvisor.o

CXX = g++
CXXFLAGS = -std=c++11

fly:	$(OBJ_FILES) main.o
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $@
	
test:	$(OBJ_FILES) test.o
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $@

Date.o:	Date.h Date.cpp
Time.o:	Time.h Time.cpp
Flight.o:	Flight.h Flight.cpp
City.o:	City.h City.cpp
TripAdvisor.o:	TripAdvisor.h TripAdvisor.cpp
main.o:	main.cpp
test.o:	test.cpp

clean:
	rm -rf $(OBJ_FILES) fly test
