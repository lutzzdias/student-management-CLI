#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "func.h"

void registerStudent(tStudent *students, int i) {
  printf("Nome: ");
  scanf(" %[^\n]", students[i].nome);

  printf("RGA: ");
  scanf("%llu", &students[i].rga);

  printf("Nota da P1: ");
  scanf("%lf", &students[i].p1);

  printf("Nota da P2: ");
  scanf("%lf", &students[i].p2);

  printf("Nota do trabalho: ");
  scanf("%lf", &students[i].trab);

  printf("Nota da PO: ");
  scanf("%lf", &students[i].po);

  calculateGrade(students[i]);
};

void calculateGrade(tStudent &student) {
  int lowestGrade = student.p1;
  if (student.p2 < lowestGrade)
    lowestGrade = student.p2;

  if (student.po > lowestGrade && lowestGrade == student.p1)
    student.mf =
        (0.35 * student.po) + (0.35 * student.p2) + (0.3 * student.trab);
  else if (student.po > lowestGrade && lowestGrade == student.p2)
    student.mf =
        (0.35 * student.p1) + (0.35 * student.po) + (0.3 * student.trab);
  else
    student.mf =
        (0.35 * student.p1) + (0.35 * student.p2) + (0.3 * student.trab);

  if (student.mf < 6)
    strcpy(student.situacao, "Reprovado");
  else
    strcpy(student.situacao, "Aprovado");
};

void orderStudents(tStudent *students, int n) {
  // Insertion Sort
  tStudent student;
  int i, j;

  for (i = 1; i < n; i++) {
    student = students[i];

    for (j = i - 1; j >= 0 && strcmp(students[j].nome, student.nome) > 0 ||
                    strcmp(students[j].nome, student.nome) == 0 &&
                        students[j].rga > student.rga;
         j--) {
      students[j + 1] = students[j];
    }
    students[j + 1] = student;
  }
};

void searchStudent(tStudent *students, int n) {
  char searchString[50], lowerCaseName[50];
  int len, count = 0;

  orderStudents(students, n);

  printf("Digite um nome: ");
  scanf(" %[^\n]", searchString);
  printf("\n");

  for (int i = 0; i < strlen(searchString); i++)
    searchString[i] = tolower(searchString[i]);

  for (int i = 0; i < n; i++) {
    strcpy(lowerCaseName, students[i].nome);

    // Transforma o nome a ser comparado para lowercase
    for (int i = 0; i < strlen(searchString); i++)
      lowerCaseName[i] = tolower(lowerCaseName[i]);

    // Compara o nome buscado (lower case) com o nome do aluno (lower case)
    if (strncmp(searchString, lowerCaseName, strlen(searchString)) == 0) {
      printf("%s, média final: %.1f, situação: %s\n", students[i].nome,
             students[i].mf, students[i].situacao);
      count++;
    }
  }
  printf("\nNúmero de resultados: %d\n", count);
};
