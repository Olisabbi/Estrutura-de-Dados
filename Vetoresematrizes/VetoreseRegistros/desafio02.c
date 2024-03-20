/*Cadastro de alunos de uma academia, contendo os seguintes atributos: matrícula, nome, número de celular, peso e altura. com no máximo, 500 posições. 
Com os seguintes métodos:
*inicializar o vetor
*incluir alunos
*excluir alunos
*imprimir relação de alunos
*realizar busca de aluno por nome
*imprimir os dados dos alunos */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_ALUNOS 500

struct Aluno {
    long int matricula;
    char nome[50];
    long int celular;
    double peso;
    double altura;
};

void inicializarAlunos(struct Aluno lista[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        lista[i].matricula = 0;
        strcpy(lista[i].nome, "");
        lista[i].celular = 0;
        lista[i].peso = 0.0;
        lista[i].altura = 0.0;
    }
}

void incluirAluno(struct Aluno lista[], int *posicao) {
    printf("Informe a matricula do aluno: ");
    scanf("%ld", &lista[*posicao].matricula);

    printf("Informe o nome do aluno: ");
    scanf("%s", lista[*posicao].nome);

    printf("Informe o celular do aluno: ");
    scanf("%ld", &lista[*posicao].celular);

    printf("Informe o peso do aluno: ");
    scanf("%lf", &lista[*posicao].peso);

    printf("Informe a altura do aluno: ");
    scanf("%lf", &lista[*posicao].altura);

    (*posicao)++;
}

void excluirAluno(struct Aluno lista[], int *posicao) {
    int matricula;
    printf("Informe a matricula do aluno a ser excluido: ");
    scanf("%d", &matricula);

    int i;
    for (i = 0; i < *posicao; i++) {
        if (lista[i].matricula == matricula) {
           
            for (int j = i; j < *posicao - 1; j++) {
                lista[j] = lista[j + 1];
            }
            (*posicao)--;
            printf("Aluno removido com sucesso.\n");
            return;
        }
    }
    printf("Aluno nao encontrado.\n");
}

void imprimirRelacaoAlunos(struct Aluno lista[], int posicao) {
    printf("Lista de Alunos:\n");
    for (int i = 0; i < posicao; i++) {
        printf("%d. %s\n", i + 1, lista[i].nome);
    }
}

void buscarAlunoPorNome(struct Aluno lista[], int posicao) {
    char nome[50];
    printf("Informe o nome do aluno a ser buscado: ");
    scanf("%s", nome);

    int encontrados = 0;
    for (int i = 0; i < posicao; i++) {
        if (strcmp(lista[i].nome, nome) == 0) {
            printf("Matricula: %ld, Nome: %s, Celular: %ld, Peso: %.2lf, Altura: %.2lf\n",
                   lista[i].matricula, lista[i].nome, lista[i].celular, lista[i].peso, lista[i].altura);
            encontrados = 1;
        }
    }

    if (!encontrados) {
        printf("Nenhum aluno encontrado com o nome %s.\n", nome);
    }
}

void imprimirDadosAlunos(struct Aluno lista[], int posicao) {
    printf("Dados dos Alunos:\n");
    for (int i = 0; i < posicao; i++) {
        printf("Matricula: %ld, Nome: %s, Celular: %ld, Peso: %.2lf, Altura: %.2lf\n",
               lista[i].matricula, lista[i].nome, lista[i].celular, lista[i].peso, lista[i].altura);
    }
}

void exibirMenu() {
    printf("\nSelecione uma opcao:\n");
    printf("1. Incluir aluno\n");
    printf("2. Excluir aluno\n");
    printf("3. Imprimir relacao de alunos\n");
    printf("4. Realizar busca de aluno por nome\n");
    printf("5. Imprimir os dados dos alunos\n");
    printf("6. Sair\n");
    printf("Opcao: ");
}

int main() {
    struct Aluno listaAlunos[TAM_MAX_ALUNOS];
    int posicaoAtual = 0;
    int opcao;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                incluirAluno(listaAlunos, &posicaoAtual);
                break;
            case 2:
                excluirAluno(listaAlunos, &posicaoAtual);
                break;
            case 3:
                imprimirRelacaoAlunos(listaAlunos, posicaoAtual);
                break;
            case 4:
                buscarAlunoPorNome(listaAlunos, posicaoAtual);
                break;
            case 5:
                imprimirDadosAlunos(listaAlunos, posicaoAtual);
                break;
            case 6:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida. Por favor, tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}
