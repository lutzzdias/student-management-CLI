#include <stdio.h>
#include <string.h>

#include "func.h"

void readFile(tStudent *students, int &n)
{
  FILE *file;

  file = fopen("input.txt", "r");

  for (int i = n; feof(file) == 0; i++, n++)
  {
    char rawString[51];
    fscanf(file, "%50[^0123456789] %llu %lf %lf %lf %lf ", rawString,
           &students[i].rga, &students[i].test1, &students[i].test2,
           &students[i].assignment, &students[i].optionalTest);

    rawString[strlen(rawString) - 1] = '\0';
    strcpy(students[i].name, rawString);

    calculateGrade(students[i]);
  }

  printf("Quantity of students: %d\n", n);
  fclose(file);
}

void generateApproved(tStudent *students, int n)
{

  orderStudents(students, n);

  FILE *file;
  int count = 0;

  file = fopen("passed.txt", "w");

  for (int i = 0; i < n; i++)
  {
    if (students[i].finalGrade >= 6)
    {
      fprintf(file, "%-50s%-15llu%-5.1f\n", students[i].name, students[i].rga,
              students[i].finalGrade);
      count++;
    }
  }

  fprintf(file, "Total: %d", count);
  fclose(file);
}

void generateNotApproved(tStudent *students, int n)
{

  orderStudents(students, n);

  FILE *file;
  int count = 0;

  file = fopen("failed.txt", "w");

  for (int i = 0; i < n; i++)
  {
    if (students[i].finalGrade < 6)
    {
      fprintf(file, "%-50s%-15llu%-5.1f\n", students[i].name, students[i].rga,
              students[i].finalGrade);
      count++;
    }
  }

  fprintf(file, "Total: %d", count);
  fclose(file);
}

void exit(tStudent *students, int n)
{

  orderStudents(students, n);

  FILE *file;
  int count = 0;

  file = fopen("actual.txt", "w");

  for (int i = 0; i < n; i++)
  {
    fprintf(file, "%s %llu %.1f %.1f %.1f %.1f\n", students[i].name,
            students[i].rga, students[i].test1, students[i].test2, students[i].assignment,
            students[i].optionalTest);
  }

  fclose(file);
}
