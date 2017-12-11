#jfuncs of makefile


jfuncs: jfuncs.o libjfuncs.a
	gcc -o jfuncs -L. jfuncs.o -ljfuncs
jfuncs.o: jfuncs.c
	gcc -c jfuncs.c
libjfuncs.a: func1.o func2.o
	ar rv libjfuncs.a func1.o func2.o
func1.o: func1.c
	gcc -c func1.c
func2.o: func2.c
	gcc -c func2.c
clean:
	rm *.o
