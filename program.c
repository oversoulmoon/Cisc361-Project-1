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
        printf("1:add \t"
                "2:del \t"
                "3:prnt\t"
                "4:rprt\t"
                "5:exit\n" );
        temp = AskUserInput();
        option = strtol(temp, NULL, 10);
        free(temp);
        temp = NULL;

        if(option == 1){
            printf("choice:Appending\n");
            AppendStudent(&list,CreateStudent());
        }else if(option ==2){
            printf("choice:last name to delete: ");
            char* lastname = AskUserInput();
            DeleteLastname(&list, lastname);
            printf("Deleting: %s\n", lastname);
            free(lastname);
            lastname = NULL;
        }else if (option == 3){
            printf("choice:Printing\n");
            PrintStudent(list, FORWARD);
        }else if (option == 4){
            printf("choice:Reverse printing\n");
            PrintStudent(list, BACKWARD);
        }
    }
    printf("choice:Exiting\n");
    if(list != NULL){
        DeallocateStudentList(&list);
    }
}

void DeallocateStudentList(student **list){
    if (*list != NULL){
        student* temp = *list;
        *list = (*list)->next;
        DeallocateStudent(temp);
        temp = NULL;
        DeallocateStudentList(list);
    }
}
void DeleteLastname(student **list, char* lastname){
    if((*list) != NULL){
        if(strcmp((*list)->lastname, lastname) == 0){

            student *temp = *list;
            int isLast = (*list)->prev == NULL;
            student *next = (*list)->next;
            DeallocateStudent(temp);
            temp = NULL;

            if (isLast){
                *list = next;
                DeleteLastname(list, lastname);
            }else{
                DeleteLastname(&next, lastname);
            }
        }else{
            student *next = (*list)->next;
            DeleteLastname(&next, lastname);
        }
    }
}
void DeallocateStudent(student *stu){
    // printf("%s", stu->firstname);
    free(stu->firstname);
    free(stu->lastname);
    free(stu->year);
    if (stu->prev == NULL && stu->next == NULL){

    }else if(stu->prev == NULL){
        stu->next->prev = NULL;
    }else if (stu->next == NULL ){
        stu->prev->next = NULL;
    }else{
        stu->prev->next = stu->next;
        stu->next->prev = stu->prev;
    }
    free(stu);
}

void AppendStudent(student **list, student *addition){
    if (*list == NULL){
        *list = addition;
    }else if ((*list)->next != NULL){
        return AppendStudent(&(*list)->next,  addition);
    }else if ((*list)->next == NULL){
        (*list)->next = addition;
        addition->prev = *list;
    }
}

void PrintStudent(student *list, Direction d){
    if(list != NULL){
        if (d == FORWARD){
            printf("%s, %s\tID %ld\t%s\tGraduating in %d\n", list->lastname,list->firstname, list->studentID, list->year, list->expectedGraduation);
            PrintStudent(list->next, d);
        }else{
            PrintStudent(list->next, d);
            printf("%s, %s\tID %ld\t%s\tGraduating in %d\n", list->lastname,list->firstname, list->studentID, list->year, list->expectedGraduation);
        }
    }
}

student * CreateStudent(){
    student *stu = (student*) malloc(sizeof(student));
    char * temp;
    int len;

    printf("last name: ");
    temp = AskUserInput();
    len = strlen(temp) + 1;
    stu->lastname = (char*) malloc(len);
    strcpy(stu->lastname, temp);
    free(temp);
    temp = NULL;

    printf("first name: ");
    temp = AskUserInput();
    len =strlen(temp) + 1;
    stu->firstname = (char*) malloc(len);
    strcpy(stu->firstname, temp);
    free(temp);
    temp = NULL;

    printf("id number: ");
    temp = AskUserInput();
    stu->studentID = strtol(temp, NULL, 10);
    free(temp);
    temp = NULL;

    printf("classification: ");
    temp = AskUserInput();
    len =strlen(temp) + 1;
    stu->year = (char*) malloc(len);
    strcpy(stu->year, temp);
    free(temp);
    temp = NULL;

    printf("grad year: ");
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
      buffer[len-1] = '\0';
    }
    return buffer;
}
