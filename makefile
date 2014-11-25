OBJ_FILES = \
  Date.o \
  Time.o \
  Flight.o \
  City.o \
  main.o
  
CXX = g++
CXXFLAGS = -std=c++11
  
fly:	$(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $@
	
Date.o:	Date.h Date.cpp
Time.o:	main.cpp
Flight.o:	Flight.h Flight.cpp
City.o:	City.h City.cpp
main.o:	main.cpp
	
clean:
	rm -rf $(OBJ_FILES) fly