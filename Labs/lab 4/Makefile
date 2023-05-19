main: main.o func.o
	g++ -o main main.o func.o 

main.o: main.cpp func.h 
	g++ -c main.cpp

func.o: func.cpp func.h
	g++ -c func.cpp

clean:
	rm -f main.o func.o 
