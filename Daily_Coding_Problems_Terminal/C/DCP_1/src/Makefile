DCP_1: DCP_1.o customStringUtil.o
	gcc -ansi -pedantic -Wall -o DCP_1 DCP_1.o customStringUtil.o
DCP_1.o: DCP_1.c customStringUtil.h 
	gcc -ansi -pedantic -Wall -c DCP_1.c
customStringUtil.o: customStringUtil.c customStringUtil.h
	gcc -ansi -pedantic -Wall -c customStringUtil.c
run: DCP_1
	./DCP_1

clean: 
	rm -f DCP_1 DCP_1.o customStringUtil.o