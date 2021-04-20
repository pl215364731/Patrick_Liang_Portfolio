CC = g++
exe_file = assign1
$(exe_file): function.o main.o
	$(CC) function.o main.o -g -std=c++11 -o $(exe_file)
function.o: assign1_function.cpp
	$(CC) -c -std=c++11 -g assign1_function.cpp -o function.o
main.o: assign1_main.cpp
	$(CC) -c -std=c++11 -g assign1_main.cpp -o main.o
clean:
	rm -f *.out *.o $(exe_file)
