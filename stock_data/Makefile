#jfuncs of makefile
libjfuncs.a: func1.o func2.o
	ar rv libjfuncs.a func1.o func2.o
func1.o: func1.c
	gcc -c func1.c
func2.o: func2.c
	gcc -c func2.c
jfuncs: jfuncs.o
	gcc jfuncs.c –L. -ljfuncs -o jfuncs
jfuncs.o: jfuncs.c
	gcc -c jfuncs.c

