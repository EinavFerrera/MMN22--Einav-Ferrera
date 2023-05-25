mycomp: mycomp.o input_check.o input_get.o complex.o
	gcc -g -Wall  -pedantic -ansi mycomp.o input_check.o input_get.o complex.o -o mycomp -lm
input_check.o: input_check.c complex.h
	gcc -c input_check.c -Wall -pedantic -ansi -o input_check.o
input_get.o: input_get.c complex.h
	gcc -c input_get.c -Wall -pedantic -ansi -o input_get.o
mycomp.o: mycomp.c complex.h
	gcc -c mycomp.c -Wall -pedantic -ansi -o mycomp.o
complex.o: complex.c complex.h
	gcc -c complex.c -Wall -pedantic -ansi -o complex.o -lm
