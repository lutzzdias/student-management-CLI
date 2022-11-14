#include <stdio.h>
#include <string.h>

#include "func.h"

void lerArquivo(tAluno *alunos, int &n){
    FILE *arq;

    arq = fopen("entrada.txt", "r");

    for(int i = n; feof(arq) == 0; i++, n++){
        char stringNaoTratada[50];
        fscanf(arq, "%50[^0123456789] %llu %lf %lf %lf %lf ", stringNaoTratada, &alunos[i].rga, &alunos[i].p1, &alunos[i].p2, &alunos[i].trab, &alunos[i].po);

        stringNaoTratada[strlen(stringNaoTratada) - 1] = '\0';
        strcpy(alunos[i].nome, stringNaoTratada);

        calcularNota(alunos[i]);
    }

    printf("Número de alunos: %d\n", n);
    fclose(arq);
}

void gerarAprovados(tAluno *alunos, int n){

    ordenarAlunos(alunos, n);

    FILE *arq;
    int cont=0;

    arq = fopen("aprovados.txt", "w");

    for(int i = 0; i < n; i++){
        if (alunos[i].mf >= 6){
            fprintf(arq, "%-50s%-15llu%-5.1f\n", alunos[i].nome, alunos[i].rga, alunos[i].mf);
            cont++;
        }
    }

    fprintf(arq, "Total: %d", cont);
    fclose(arq);
}

void gerarReprovados(tAluno *alunos, int n){

    ordenarAlunos(alunos, n);

    FILE *arq;
    int cont=0;

    arq = fopen("reprovados.txt", "w");

    for(int i = 0; i < n; i++){
        if (alunos[i].mf < 6){
            fprintf(arq, "%-50s%-15llu%-5.1f\n", alunos[i].nome, alunos[i].rga, alunos[i].mf);
            cont++;
        }
    }

    fprintf(arq, "Total: %d", cont);
    fclose(arq);
}

void sair(tAluno *alunos, int n){

    ordenarAlunos(alunos, n);

    FILE *arq;
    int cont=0;

    arq = fopen("atual.txt", "w");

    for(int i = 0; i < n; i++){
        fprintf(arq, "%s %llu %.1f %.1f %.1f %.1f\n", alunos[i].nome, alunos[i].rga, alunos[i].p1, alunos[i].p2, alunos[i].trab, alunos[i].po);
    }

    fclose(arq);
}
