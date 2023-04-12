#include <stdio.h>

struct tStudent
{
  char name[50];
  unsigned long long int rga;
  double test1, test2, assignment, optionalTest, finalGrade;
  char situacao[10];
};

void orderStudents(tStudent *students, int n);

void calculateGrade(tStudent &students);

void registerStudent(tStudent *students, int i);

void searchStudent(tStudent *students, int n);

void readFile(tStudent *students, int &n);

void generateApproved(tStudent *students, int n);

void generateNotApproved(tStudent *students, int n);

void exit(tStudent *students, int n);
