typedef struct student {
  char *lastname;
  char *firstname;
  long studentID;
  char *year;
  int expectedGraduation;
  struct student *next;
  struct student *prev;
} student;

student * CreateStudent();
void AppendStudent(student *list, student *addition);
void PrintStudent(student *list, bool foward);
void DeleteLastname(student *list);
void DeallocateStudent(student *stu);
void DeallocateStudentList(student *list);
