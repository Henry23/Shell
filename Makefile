clean: shell
		rm *.o

shell: main.o mkdir rmdir rmdirR
		g++ main.o -o shell

main.o: main.cpp 
		g++ -c main.cpp

mkdir: mkdir.o 
		g++ mkdir.cpp -o mkdir

mkdir.o: mkdir.cpp
		 g++ -c mkdir.cpp

rmdir: rmdir.o		 
		g++ rmdir.cpp -o rmdir

rmdir.o: rmdir.cpp
	     g++ -c rmdir.cpp

rmdirR: rmdirR.o
		g++ rmdirR.cpp -o rmdirR

rmdirR.o: rmdirR.cpp
		g++ -c rmdirR.cpp 	     

