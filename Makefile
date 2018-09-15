main: rps.o main.o
	g++ -o main rps.o main.o

main.o: main.cpp rps.h
	g++ -c main.cpp

rps.o: rps.cpp rps.h
	g++ -c rps.cpp