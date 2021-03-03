typedef struct {
    char name[30];
    int registration;
}Student;

void SetRegistration(Student* student,int number);
void SetName(Student* student,char* name);
void PrintStudent(Student* student);