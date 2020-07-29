marsrover: main.o mars.o obstracle.o obstraclelist.o rover.o
	gcc -Wall -std=c99 -o marsrover main.o mars.o obstracle.o obstraclelist.o rover.o

rover.o: objects/rover.c
	gcc -Wall -std=c99 -c objects/rover.c

obstracle.o: objects/obstracle.c
	gcc -Wall -std=c99 -c objects/obstracle.c

obstraclelist.o: objects/obstraclelist.c
	gcc -Wall -std=c99 -c objects/obstraclelist.c

mars.o: objects/mars.c
	gcc -Wall -std=c99 -c objects/mars.c

main.o: main.c
	gcc -Wall -std=c99 -c main.c
