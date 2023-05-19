main: main.o profile.o network.o 
	g++ -o main main.o profile.o funcs.o

main.o: main.cpp profile.h funcs.h
	

profile.o: profile.cpp profile.h
	

funcs.o: funcs.cpp funcs.h
	

tests: tests.o profile.o funcs.o
	g++ -o tests tests.o profile.o funcs.o 

tests.o: tests.cpp profile.h funcs.h doctext.h
	
	
clean: 
	rm -f main main.o tests.o profile.o funcs.o
