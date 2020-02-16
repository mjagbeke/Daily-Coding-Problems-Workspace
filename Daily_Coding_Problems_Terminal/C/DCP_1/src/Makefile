DCP_1: DCP_1.o customStringUtil.o
	gcc -ansi -pedantic -o DCP_1 DCP_1.o customStringUtil.o
DCP_1.o: DCP_1.c roper.h 
	gcc -ansi -pedantic -c ropes.c
customStringUtil.o: customStringUtil.c customStringUtil.h
	gcc -ansi -pedantic -c customStringUtil.c
run: ropes
	./ropes

clean: 
	rm -f DCP_1 DCP_1.o customStringUtil.o