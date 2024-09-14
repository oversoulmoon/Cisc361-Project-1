slist: program.c program.h
	gcc -o slist program.c

clean:
	rm slist ./tests/results/*

tests: slist
	echo "test1: add a bunch of students, then print"
	./slist < ./tests/test1 > ./tests/results/test1.stdout
	echo "test2: delete one from the middle, then the end, then the start"
	./slist < ./tests/test2 > ./tests/results/test2.stdout
	echo "test2: delete multiple from the middle, the the end, then the start, then the rest"
	./slist < ./tests/test3 > ./tests/results/test3.stdout
	diff ./tests/results/test1.stdout ./tests/actual_results/test1.out
	diff ./tests/results/test2.stdout ./tests/actual_results/test2.out
	diff ./tests/results/test3.stdout ./tests/actual_results/test3.out
