typedef struct student {
  char *lastname;
  char *firstname;
  long studentID;
  char *year;
  int expectedGraduation;
  struct student *next;
  struct student *prev;
} student_t;
