FLAGS=

fisimula: fisimula.o menu.o calcnode.o libfisimula.o calcdata.o calc.o libcalc.o calcsyn.o calclex.o calcsolver.o
	g++ $(FLAGS) menu.o calcnode.o libfisimula.o calcdata.o calc.o fisimula.o calcsyn.o calclex.o calcsolver.o libcalc.o -o ../fisimula

fisimula.o: fisimula.cpp calc.hpp menu.hpp
	g++ $(FLAGS) -c fisimula.cpp -o fisimula.o

menu.o: menu.hpp menu.cpp
	g++ $(FLAGS) -c menu.cpp -o menu.o

calcnode.o: calcnode.cpp calcnode.hpp
	g++ $(FLAGS) -c calcnode.cpp -o calcnode.o

libfisimula.o: libfisimula.cpp
	g++ $(FLAGS) -o libfisimula.o -c libfisimula.cpp 

libcalc.o: libcalc.cpp
	g++ $(FLAGS) -c libcalc.cpp -o libcalc.o

calcdata.o: calcnode.hpp calcdata.hpp calcdata.cpp
	g++ $(FLAGS) -c calcdata.cpp -o calcdata.o

calc.o: calc.cpp calc.hpp calcdata.hpp libfisimula.hpp libcalc.hpp calclex.hpp calcsolver.hpp calcsyn.hpp
	g++ $(FLAGS) -c calc.cpp -o calc.o

calclex.o: calclex.cpp
	g++ $(FLAGS) -c calclex.cpp -o calclex.o

calcsolver.o: calcsolver.cpp
	g++ $(FLAGS) -c calcsolver.cpp -o calcsolver.o

calcsyn.o: calcsyn.hpp calcsyn.cpp calcdata.hpp
	g++ $(FLAGS) -c calcsyn.cpp -o calcsyn.o

clean:	
	-rm src/*.o
