oper: opermain.o operfn.o
	gcc opermain.o operfn.o -o oper

opermain.o: playlife.c lifefunc.h
	gcc -c playlife.c -o opermain.o

operfn.o: playlife.c lifefunc.h
	gcc -c lifefunc.c -o operfn.o

clean:
	rm oper
	rm *.o

