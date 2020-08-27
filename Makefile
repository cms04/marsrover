marsrover: main.o mars.o obstracle.o obstraclelist.o rover.o
	gcc -Wall -std=c99 -o marsrover main.o mars.o obstracle.o obstraclelist.o rover.o

rover.o: src/objects/rover.c
	gcc -Wall -std=c99 -c src/objects/rover.c

obstracle.o: src/objects/obstracle.c
	gcc -Wall -std=c99 -c src/objects/obstracle.c

obstraclelist.o: src/objects/obstraclelist.c
	gcc -Wall -std=c99 -c src/objects/obstraclelist.c

mars.o: src/objects/mars.c
	gcc -Wall -std=c99 -c src/objects/mars.c

main.o: src/main.c
	gcc -Wall -std=c99 -c src/main.c

clean:
	rm -f *.o marsrover
	rm -f obstracletest 

check:
	checkmk test/obstracle_test.ts > test/obstracle_test.c

build: check
	gcc -Wall -std=c99 -o obstracletest test/obstracle_test.c src/objects/obstracle.c `pkg-config --cflags --libs check`

test: build
	./obstracletest
