#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "program.h"

#define BUFFERSIZE 1024

int main(int argc, char** argv){
    int option = 0;
    char * temp;
    int len = 0;
    student *list = NULL;
    while (option != 5){
        printf("1: add "
                "2: delete "
                "3: print "
                "4: rprint "
                "5.: exit " );
        printf("Choice: \n");
        temp = AskUserInput();
        option = strtol(temp, NULL, 10);
        free(temp);
        temp = NULL;

        if(option == 1){
            if(list == NULL){
                list = CreateStudent();
            }else{
                AppendStudent(list,CreateStudent());
            }
        }else if (option == 3){
            PrintStudent(list, FORWARD);
        }
    }
}

void AppendStudent(student *list, student *addition){
    if (list->next != NULL){
        return AppendStudent(list->next,  addition);
    }else if (list->next == NULL){
        list->next = addition;
        addition->prev = list;
    }
}
void PrintStudent(student *list, Direction d){
    if(list != NULL){
        printf("%s, %s ID %ld %s Grad in %d\n", list->lastname,list->firstname, list->studentID, list->year, list->expectedGraduation);
        PrintStudent(list->next, d);
    }
}
student * CreateStudent(){
    student *stu = (student*) malloc(sizeof(student));
    char * temp;

    printf("last_name: ");
    stu->lastname = AskUserInput();

    printf("first_name: ");
    stu->firstname = AskUserInput();

    printf("ID: ");
    temp = AskUserInput();
    stu->studentID = strtol(temp, NULL, 10);
    free(temp);
    temp = NULL;

    printf("class: ");
    stu->year = AskUserInput();

    printf("year: ");
    temp = AskUserInput();
    stu->expectedGraduation = strtol(temp, NULL, 10);
    free(temp);
    temp = NULL;

    stu->next = NULL;
    stu->prev = NULL;

    return stu;
}
char *AskUserInput(){
    char *buffer = (char*) malloc(BUFFERSIZE);
    int len;
    if (fgets(buffer, BUFFERSIZE , stdin) != NULL)
    {
      len = (int) strlen(buffer);
      buffer[len-1] = '\0';                 // why minus 1 ???
    }
    return buffer;
}
