compile: objects
	gcc -Wall -std=c99 -o marsrover obj/main.o obj/mars.o obj/obstracle.o obj/rover.o -g

objects: src/main.c src/mars.h src/obstracle.h src/rover.h src/mars.c src/obstracle.c src/rover.c
	mkdir -p obj
	gcc -Wall -std=c99 -c src/main.c -o obj/main.o -g
	gcc -Wall -std=c99 -c src/obstracle.c -o obj/obstracle.o -g
	gcc -Wall -std=c99 -c src/rover.c -o obj/rover.o -g
	gcc -Wall -std=c99 -c src/mars.c -o obj/mars.o -g

clean:
	rm -rf obj
	rm marsrover
