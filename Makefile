slist: program.c program.h
	gcc -o slist program.c

clean: slist
	rm slist
