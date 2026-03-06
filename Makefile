PJ2: main.o heap.o util.o
	g++ -o PJ2 main.o heap.o util.o

main.o: main.cpp
	g++ -c main.cpp

heap.o: heap.cpp
	g++ -c heap.cpp

util.o: util.cpp
	g++ -c util.cpp

clean:
	rm -f *.o PJ2
