#include <string.h>
#include <stdio.h>
#include "Aluno.h"
void SetName(Student* student,char* name){
    strcpy(student->name,name);
}
void SetRegistration(Student* student,int number){
    student->registration = number;
}
void PrintStudent(Student* student){
    printf("Name: %s\nRegistration: %d\n",student->name,student->registration);

}