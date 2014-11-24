OBJ_FILES = \
  Date.o \
  Time.o \
  Flight.o \
  City.o \
  main.o
  
fly:	$(OBJ_FILES)
	g++ -std=c++11 -o $@
	
Date.o:	Date.h Date.cpp
Time.o:	main.cpp
Flight.o:	Flight.h Flight.cpp
City.o:	City.h City.cpp
main.o:	main.cpp