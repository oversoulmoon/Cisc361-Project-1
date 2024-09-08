make slist: program.c program.h
	gcc -o slist program.c

make clean: slist
	rm slist
