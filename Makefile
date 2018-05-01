all: rng.o global.o usefulfunctions.o gpnode.o gpoperators.o gpprogram.o gppopulation.o mainprog.o
	g++ -O3 mainprog.o gpoperators.o gppopulation.o gpprogram.o gpnode.o usefulfunctions.o global.o rng.o -o bin/gpsr

clean:
	rm -f *.o *~ bin/gpsr bin/gpsr.exe bin/runtests bin/runtests.exe

mainprog.o: src/mainprog.cpp
	g++ -c -O3 src/mainprog.cpp

gpoperators.o: src/gpoperators.cpp src/gpoperators.h 
	g++ -c -O3 src/gpoperators.cpp

gppopulation.o: src/gppopulation.cpp src/gppopulation.h 
	g++ -c -O3 src/gppopulation.cpp

gpprogram.o: src/gpprogram.cpp src/gpprogram.h 
	g++ -c -O3 src/gpprogram.cpp

usefulfunctions.o: src/usefulfunctions.cpp src/usefulfunctions.h
	g++ -c -O3 src/usefulfunctions.cpp

gpnode.o: src/gpnode.cpp src/gpnode.h
	g++ -c -O3 src/gpnode.cpp

global.o: src/global.cpp src/global.h
	g++ -c -O3 src/global.cpp

rng.o: src/rng.cpp src/rng.h
	g++ -c -O3 src/rng.cpp
