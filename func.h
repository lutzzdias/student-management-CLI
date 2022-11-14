#include <stdio.h>

struct tStudent {
  char nome[50];
  unsigned long long int rga;
  double p1, p2, trab, po, mf;
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
