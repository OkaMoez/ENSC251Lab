#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o and student.o to executable main
main: main.o student.o functions.o studentlists.o
	g++ -std=c++11 -g -o main main.o student.o functions.o studentlists.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -std=c++11 -g -c main.cpp

#compile the student.cpp to student.o
student.o: student.cpp
	g++ -std=c++11 -g -c student.cpp

#compile the functions.cpp to functions.o
functions.o: functions.cpp
	g++ -std=c++11 -g -c functions.cpp

#compile the studentlists.cpp to studentlists.o
studentlists.o: studentlists.cpp
	g++ -std=c++11 -g -c studentlists.cpp

#remove built files
clean:
	rm -rf main main.o student.o functions.o studentlists.o *~
