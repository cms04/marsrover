marsrover: main.o mars.o
	gcc -o marsrover main.o mars.o

main.o: main.c
	gcc -c main.c

mars.o: mars.c
	gcc -c mars.c
