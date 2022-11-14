#include "func.h"
#include <stdio.h>

int main() {
  int option, numberOfStudents = 0;
  tStudent students[100];

  do {
    printf("\n[1] Cadastrar novo aluno.\n");
    printf("[2] Buscar aluno. \n");
    printf("[3] Ler arquivo com listagem de alunos. \n");
    printf("[4] Gerar arquivo com dados dos alunos aprovados. \n");
    printf("[5] Gerar arquivo com dados dos alunos reprovados. \n");
    printf("[0] Fechar programa.\n");

    printf("--> ");
    scanf("%d", &option);
    printf("\n");

    if (option == 1) {
      registerStudent(students, numberOfStudents);
      numberOfStudents++;
    }

    else if (option == 2) {
      searchStudent(students, numberOfStudents);
    }

    else if (option == 3) {
      readFile(students, numberOfStudents);
    }

    else if (option == 4) {
      generateApproved(students, numberOfStudents);
    }

    else if (option == 5) {
      generateNotApproved(students, numberOfStudents);
    }

    else if (option == 0) {
      exit(students, numberOfStudents);
    }
  } while (option != 0);

  return 0;
}
