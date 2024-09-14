# CISC361 Project 1

The primary objective of this assignment is to practice/review C coding, including the use of C structs and pointers for later use in the programming assignments. You will write a C program that will allow the user to enter Student data into a doubly linked list, remove student entries and view the contents of the list. Your program will be scored based on its correctness, code structure, and documentation. In particular, you should use Valgrind Links to an external site. to ensure that you are correctly allocating and freeing memory!

## Getting started

Download the repository using git:
```
$ git clone https://gitlab.eecis.udel.edu/trungtng/cisc361-project-1.git
$ cd cisc361-project-1
```

## Installation
Build
```
$ make slist
```
Run tests:
```
$ make tests
```

## Usage
```
$ ./slist
```
And follow the prompts
## Options
1- Add a student (append to list), input last name, first name, id, classification and graduation year. \
2- Delete all student in list with matching last name, input last name \
3- Printing all students from first to last\
4- Print all students from last to first \
5- exit
