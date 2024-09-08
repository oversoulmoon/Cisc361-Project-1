#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "program.h"

#define BUFFERSIZE 1024

int main(int argc, char** argv){
    int option = 0;
    char * temp;
    student *list = NULL;
    int len = 0;
    while (option != 5){
        printf("1. add an student to the end of the list after prompting for all the student's data \n"
                "2. delete all students with a given last name from the list (pay particular attention to what happens if you delete the first or last student!) \n"
                "3. print the list from beginning to end \n"
                "4. print the list from end to beginning \n"
                "5. exit the program. \n" );
        temp = AskUserInput();
        option = strtol(temp, NULL, 10);
        free(temp);
        temp = NULL;

        if(option == 1){
            AppendStudent(list, CreateStudent());
        }
    }
}

void AppendStudent(student *list, student *addition){
    if (list == NULL){
        list = addition;
    }else if (list->next != NULL){
        return AppendStudent(list->next,  addition);
    }else if (list->next == NULL){
        list->next = addition;
        addition->prev = list->next;
    }
}

student * CreateStudent(){
    student *stu = (student*) malloc(sizeof(student));
    char * temp;

    printf("Enter Student Last Name: \n");
    stu->lastname = AskUserInput();

    printf("Enter Student First Name: \n");
    stu->firstname = AskUserInput();

    printf("Enter Student ID: \n");
    temp = AskUserInput();
    stu->studentID = strtol(temp, NULL, 10);
    free(temp);
    temp = NULL;

    printf("Enter Student Year Status (freshman, etc...): \n");
    stu->year = AskUserInput();

    printf("Enter Student Expected Gradutation Year: \n");
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
