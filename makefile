state.x: State.o main.o
	g++ -ggdb -std=c++11 -std=gnu++0x State.o main.o -o state.x
State.o: States.hpp States.cpp
	g++ -ggdb -std=c++11 -std=gnu++0x States.cpp -o State.o -c
main.o: States.cpp States.hpp Main.cpp
	g++ -ggdb -std=c++11 -std=gnu++0x  Main.cpp -o main.o -c

clean:
	rm -f *.o make.x *~

