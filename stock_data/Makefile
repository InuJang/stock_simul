#jfuncs of makefile
func1.o: func1.c
	gcc -c func1.c
func2.o: func2.c
	gcc -c func2.c
libjfuncs.so.1: libjfuncs.so.1.0
	ln -s libjfuncs.so.1.0 libjfuncs.so.1
libjfuncs.so.1.0: libjfuncs.so
	ln -s libjfuncs.so.1.0 libjfuncs.so
libjfuncs.so.1.0:
	gcc -fPIC -shared -Wl,-soname=libjfuncs.so.1 *.o -o libjfuncs.so.1.0 -lc
jfuncs: jfuncs.o
	gcc -o jfuncs jfuncs.c -L . -ljfuncs
jfuncs.o: jfuncs.c
	gcc -c jfuncs.c

