CC = gcc
CFLAGS = -Wall -std=c99 -g
OUTPUT = marsrover
VALGRINDOPTIONS = --leak-check=full --track-origins=yes -s

$(OUTPUT): objects
	$(CC) -o $(OUTPUT) obj/main.o obj/mars.o obj/obstracle.o obj/rover.o $(CFLAGS)

objects: src/main.c src/mars.h src/obstracle.h src/rover.h src/mars.c src/obstracle.c src/rover.c
	mkdir -p obj
	$(CC) -c src/main.c -o obj/main.o $(CFLAGS)
	$(CC) -c src/obstracle.c -o obj/obstracle.o $(CFLAGS)
	$(CC) -c src/rover.c -o obj/rover.o $(CFLAGS)
	$(CC) -c src/mars.c -o obj/mars.o $(CFLAGS)

clean:
	rm -rf obj
	rm marsrover

run: $(OUTPUT)
	./$(OUTPUT)

valgrind: $(OUTPUT)
	valgrind $(VALGRINDOPTIONS) ./$(OUTPUT)
