#include <stdio.h>
#include <string.h>

#include "func.h"

void readFile(tStudent *students, int &n) {
  FILE *file;

  file = fopen("entrada.txt", "r");

  for (int i = n; feof(file) == 0; i++, n++) {
    char rawString[51];
    fscanf(file, "%50[^0123456789] %llu %lf %lf %lf %lf ", rawString,
           &students[i].rga, &students[i].p1, &students[i].p2,
           &students[i].trab, &students[i].po);

    rawString[strlen(rawString) - 1] = '\0';
    strcpy(students[i].nome, rawString);

    calculateGrade(students[i]);
  }

  printf("Número de alunos: %d\n", n);
  fclose(file);
}

void generateApproved(tStudent *students, int n) {

  orderStudents(students, n);

  FILE *file;
  int count = 0;

  file = fopen("aprovados.txt", "w");

  for (int i = 0; i < n; i++) {
    if (students[i].mf >= 6) {
      fprintf(file, "%-50s%-15llu%-5.1f\n", students[i].nome, students[i].rga,
              students[i].mf);
      count++;
    }
  }

  fprintf(file, "Total: %d", count);
  fclose(file);
}

void generateNotApproved(tStudent *students, int n) {

  orderStudents(students, n);

  FILE *file;
  int count = 0;

  file = fopen("reprovados.txt", "w");

  for (int i = 0; i < n; i++) {
    if (students[i].mf < 6) {
      fprintf(file, "%-50s%-15llu%-5.1f\n", students[i].nome, students[i].rga,
              students[i].mf);
      count++;
    }
  }

  fprintf(file, "Total: %d", count);
  fclose(file);
}

void exit(tStudent *students, int n) {

  orderStudents(students, n);

  FILE *file;
  int count = 0;

  file = fopen("atual.txt", "w");

  for (int i = 0; i < n; i++) {
    fprintf(file, "%s %llu %.1f %.1f %.1f %.1f\n", students[i].nome,
            students[i].rga, students[i].p1, students[i].p2, students[i].trab,
            students[i].po);
  }

  fclose(file);
}
