#include "func.h"
#include <stdio.h>

int main()
{
  int option, numberOfStudents = 0;
  tStudent students[100];

  do
  {
    printf("\n[1] Register new student.\n");
    printf("[2] Search students.\n");
    printf("[3] Read file with students list.\n");
    printf("[4] Generate file with approved students’ data.\n");
    printf("[5] Generate file with failed students’ data.\n");
    printf("[0] Exit.\n");

    printf("--> ");
    scanf("%d", &option);
    printf("\n");

    if (option == 1)
    {
      registerStudent(students, numberOfStudents);
      numberOfStudents++;
    }

    else if (option == 2)
    {
      searchStudent(students, numberOfStudents);
    }

    else if (option == 3)
    {
      readFile(students, numberOfStudents);
    }

    else if (option == 4)
    {
      generateApproved(students, numberOfStudents);
    }

    else if (option == 5)
    {
      generateNotApproved(students, numberOfStudents);
    }

    else if (option == 0)
    {
      exit(students, numberOfStudents);
    }
  } while (option != 0);

  return 0;
}
