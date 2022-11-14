#include <stdio.h>

struct tAluno {
    char nome[50];
    unsigned long long int rga;
    double p1, p2, trab, po, mf;
    char situacao[10];
};

void ordenarAlunos(tAluno *alunos, int n);

void calcularNota(tAluno &aluno);

void cadastrarAluno(tAluno *vetor, int i);

void buscarAluno(tAluno *alunos, int n);

void lerArquivo(tAluno *alunos, int &n);

void gerarAprovados(tAluno *alunos, int n);

void gerarReprovados(tAluno *alunos, int n);

void sair(tAluno *alunos, int n);
