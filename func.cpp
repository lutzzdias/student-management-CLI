#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "func.h"

void registerStudent(tStudent *students, int i)
{
  printf("Name: ");
  scanf(" %[^\n]", students[i].name);

  printf("RGA: ");
  scanf("%llu", &students[i].rga);

  printf("First test’s grade: ");
  scanf("%lf", &students[i].test1);

  printf("Second test’s grade: ");
  scanf("%lf", &students[i].test2);

  printf("Assignment’s grade: ");
  scanf("%lf", &students[i].assignment);

  printf("Optional test's grade: ");
  scanf("%lf", &students[i].optionalTest);

  calculateGrade(students[i]);
};

void calculateGrade(tStudent &student)
{
  int lowestGrade = student.test1;
  if (student.test2 < lowestGrade)
    lowestGrade = student.test2;

  if (student.optionalTest > lowestGrade && lowestGrade == student.test1)
    student.finalGrade =
        (0.35 * student.optionalTest) + (0.35 * student.test2) + (0.3 * student.assignment);
  else if (student.optionalTest > lowestGrade && lowestGrade == student.test2)
    student.finalGrade =
        (0.35 * student.test1) + (0.35 * student.optionalTest) + (0.3 * student.assignment);
  else
    student.finalGrade =
        (0.35 * student.test1) + (0.35 * student.test2) + (0.3 * student.assignment);

  if (student.finalGrade < 6)
    strcpy(student.situacao, "Failed");
  else
    strcpy(student.situacao, "Passed");
};

void orderStudents(tStudent *students, int n)
{
  // Insertion Sort
  tStudent student;
  int i, j;

  for (i = 1; i < n; i++)
  {
    student = students[i];

    for (j = i - 1; j >= 0 && strcmp(students[j].name, student.name) > 0 ||
                    strcmp(students[j].name, student.name) == 0 &&
                        students[j].rga > student.rga;
         j--)
    {
      students[j + 1] = students[j];
    }
    students[j + 1] = student;
  }
};

void searchStudent(tStudent *students, int n)
{
  char searchString[50], lowerCaseName[50];
  int len, count = 0;

  orderStudents(students, n);

  printf("Type student name: ");
  scanf(" %[^\n]", searchString);
  printf("\n");

  for (int i = 0; i < strlen(searchString); i++)
    searchString[i] = tolower(searchString[i]);

  for (int i = 0; i < n; i++)
  {
    strcpy(lowerCaseName, students[i].name);

    // Transforma o nome a ser comparado para lowercase
    for (int i = 0; i < strlen(searchString); i++)
      lowerCaseName[i] = tolower(lowerCaseName[i]);

    // Compara o nome buscado (lower case) com o nome do aluno (lower case)
    if (strncmp(searchString, lowerCaseName, strlen(searchString)) == 0)
    {
      printf("%s, final grade: %.1f, situation: %s\n", students[i].name,
             students[i].finalGrade, students[i].situacao);
      count++;
    }
  }
  printf("\nNumber of results: %d\n", count);
};
