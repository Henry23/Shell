clean: shell
		rm *.o

shell: main.o mkDir
		g++ main.o -o shell

main.o: main.cpp 
		g++ -c main.cpp

mkDir: mkDir.o 
		g++ mkDir.cpp -o mkDir

mkDir.o: mkDir.cpp
		 g++ -c mkDir.cpp

