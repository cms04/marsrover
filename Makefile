marsrover: main.o mars.o obstracle.o obstraclelist.o
	gcc -Wall -std=c99 -o marsrover main.o mars.o obstracle.o obstraclelist.o

obstracle.o: obstracle.c
	gcc -Wall -std=c99 -c obstracle.c

obstraclelist.o: obstraclelist.c
	gcc -Wall -std=c99 -c obstraclelist.c

mars.o: mars.c
	gcc -Wall -std=c99 -c mars.c

main.o: main.c
	gcc -Wall -std=c99 -c main.c
