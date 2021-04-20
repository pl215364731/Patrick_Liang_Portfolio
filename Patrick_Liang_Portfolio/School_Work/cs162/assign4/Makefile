CC = g++
exe_file = hunt_wumpus
$(exe_file): bat.o gold.o pit.o player.o room.o wumpus.o event.o  driver.o
	$(CC) bat.o gold.o  pit.o player.o room.o wumpus.o event.o driver.o -g -std=c++11 -o $(exe_file)
bat.o: bat.cpp
	$(CC) -c -std=c++11 -g bat.cpp
gold.o: gold.cpp
	$(CC) -c -std=c++11 -g gold.cpp
pit.o: pit.cpp
	$(CC) -c -std=c++11 -g pit.cpp
player.o: player.cpp
	$(CC) -c -std=c++11 -g player.cpp
room.o: room.cpp
	$(CC) -c -std=c++11 -g room.cpp
wumpus.o: wumpus.cpp
	$(CC) -c -std=c++11 -g wumpus.cpp
event.o: event.cpp
	$(CC) -c -std=c++11 -g event.cpp
driver.o: driver.cpp
	$(CC) -c -std=c++11 -g driver.cpp
clean:
	rm -f *.out *.o $(exe_file)

