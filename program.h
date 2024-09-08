typedef struct student {
  char *lastname;
  char *firstname;
  long studentID;
  char *year;
  int expectedGraduation;
  struct student *next;
  struct student *prev;
} student;

// For automated valgrind tests using gitlab CI/CD
void AutomatedRunThrough();
char *AskUserInput();
typedef enum {
    FORWARD,
    BACKWARD
}Direction;
student * CreateStudent();
void AppendStudent(student *list, student *addition);
void PrintStudent(student *list, Direction d);
void DeleteLastname(student *list);
void DeallocateStudent(student *stu);
void DeallocateStudentList(student *list);
