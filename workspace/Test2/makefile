newtest2:main.o fun.o fun2.o
	gcc main.o fun.o fun2.o -o newtest2
main.o:main.c
	gcc main.c -c
fun.o:fun.c 
	gcc fun.c -c
fun2.o:fun2.c 
	gcc fun2.c -c
clean:
	rm -f *.o
