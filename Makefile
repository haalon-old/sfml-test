all: out.exe

main.o: main.cpp
	g++ -c -o main.o main.cpp -O2 -fopenmp

out.exe: main.o
	g++ main.o -lsfml-graphics -lsfml-window -lsfml-system -o out.exe -fopenmp

clean: 
	rm -rf *.o *.exe
