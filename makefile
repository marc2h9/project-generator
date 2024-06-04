compile:
	g++ -c src/source.cpp
	g++ -c src/scripts/makeprojects.cpp
	g++ source.o makeprojects.o -o main
	rm source.o
	rm makeprojects.o
	mv main ~/Test/
