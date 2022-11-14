#include <stdio.h>
#include "func.h"

int main() {
    int opcao, numAlunos = 0;
    tAluno alunos[100];

    do {
        printf("\n[1] Cadastrar novo aluno.\n");
        printf("[2] Buscar aluno. \n");
        printf("[3] Ler arquivo com listagem de alunos. \n");
        printf("[4] Gerar arquivo com dados dos alunos aprovados. \n");
        printf("[5] Gerar arquivo com dados dos alunos reprovados. \n");
        printf("[0] Fechar programa.\n");

        printf("--> ");
        scanf("%d", &opcao);
        printf("\n");

        if (opcao == 1){
            cadastrarAluno(alunos, numAlunos);
            numAlunos++;
        } 

        else if(opcao == 2){
            buscarAluno(alunos, numAlunos);
        } 

        else if(opcao == 3){
            lerArquivo(alunos, numAlunos);
        } 

        else if (opcao == 4){
            gerarAprovados(alunos, numAlunos);
        } 

        else if (opcao == 5){
            gerarReprovados(alunos, numAlunos);
        }

        else if (opcao == 0){
            sair(alunos, numAlunos);
        }
    } while (opcao != 0);

    return 0;
}
