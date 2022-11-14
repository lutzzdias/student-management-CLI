#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "func.h"

void cadastrarAluno(tAluno *alunos, int i){
    printf("Nome: ");
    scanf(" %[^\n]", alunos[i].nome);

    printf("RGA: ");
    scanf("%llu", &alunos[i].rga);

    printf("Nota da P1: ");
    scanf("%lf", &alunos[i].p1);

    printf("Nota da P2: ");
    scanf("%lf", &alunos[i].p2);

    printf("Nota do trabalho: ");
    scanf("%lf", &alunos[i].trab);

    printf("Nota da PO: ");
    scanf("%lf", &alunos[i].po);

    calcularNota(alunos[i]);
};

void calcularNota(tAluno &aluno){
    int menorNota = aluno.p1;
    if (aluno.p2 < menorNota)
        menorNota = aluno.p2;

    if (aluno.po > menorNota && menorNota == aluno.p1)
        aluno.mf = (0.35 * aluno.po) + (0.35 * aluno.p2) + (0.3 * aluno.trab);
    else if (aluno.po > menorNota && menorNota == aluno.p2)
        aluno.mf = (0.35 * aluno.p1) + (0.35 * aluno.po) + (0.3 * aluno.trab);
    else
        aluno.mf = (0.35 * aluno.p1) + (0.35 * aluno.p2) + (0.3 * aluno.trab);

    if (aluno.mf < 6)
	    strcpy(aluno.situacao, "Reprovado");
    else
	    strcpy(aluno.situacao, "Aprovado");
};

void ordenarAlunos(tAluno *alunos, int n){
    // Insertion Sort - Ordenação por Inserção
    tAluno x;
    int i, j;

    for (i = 1; i < n; i++){
        x = alunos[i];
        
        for (j = i-1; j >= 0 && strcmp(alunos[j].nome, x.nome) > 0 || strcmp(alunos[j].nome, x.nome) == 0 && alunos[j].rga > x.rga; j--) {
                alunos[j+1] = alunos[j];
        }
	    alunos[j+1] = x;
    }
};

void buscarAluno(tAluno *alunos, int n){
    char busca[50], nomeLower[50];
    int len, count = 0;

    ordenarAlunos(alunos, n);

    printf("Digite um nome: ");
    scanf(" %[^\n]", busca);
    printf("\n");

    for (int i = 0; i < strlen(busca); i++)
        busca[i] = tolower(busca[i]);

    for (int i = 0; i < n; i++){
        strcpy(nomeLower, alunos[i].nome);

        // Transforma o nome a ser comparado para lowercase
        for (int i = 0; i < strlen(busca); i++)
            nomeLower[i] = tolower(nomeLower[i]);

        // Compara o nome buscado (lower case) com o nome do aluno (lower case)
        if (strncmp(busca, nomeLower, strlen(busca)) == 0){
            printf("%s, média final: %.1f, situação: %s\n", alunos[i].nome, alunos[i].mf, alunos[i].situacao);
            count++;
        } 
    }
    printf("\nNúmero de resultados: %d\n", count);
};
