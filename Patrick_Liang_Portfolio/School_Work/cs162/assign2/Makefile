CC = g++
exe_file = crazy_eights
$(exe_file): card.o deck.o hand.o player.o game.o  driver.o
	$(CC) card.o deck.o  hand.o player.o game.o driver.o -g -o $(exe_file)
card.o: card.cpp
	$(CC) -c -g card.cpp
deck.o: deck.cpp
	$(CC) -c -g deck.cpp
hand.o: hand.cpp
	$(CC) -c -g hand.cpp
player.o: player.cpp
	$(CC) -c -g player.cpp
game.o: game.cpp
	$(CC) -c -g game.cpp
driver.o: driver.cpp
	$(CC) -c -g driver.cpp
clean:
	rm -f *.out *.o $(exe_file)

