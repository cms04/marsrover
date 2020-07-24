marsrover: main.o mars.o
	gcc -Wall -std=c99 -o marsrover main.o mars.o

main.o: main.c
	gcc -Wall -std=c99 -c main.c

mars.o: mars.c
	gcc -Wall -std=c99 -c mars.c
