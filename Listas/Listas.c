#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


#define MAX 40

typedef struct {
    char nome[20];
    float nota;
    char status;
} Aluno;

typedef struct {
    Aluno alunos[MAX];
    int tamanho;
} Lista;

void incluirAluno(Lista* lista, Aluno aluno) {
    if (lista->tamanho < MAX) {
        lista->alunos[lista->tamanho++] = aluno;
    } else {
        printf("Lista cheia!\n");
    }
}

void excluirAluno(Lista* lista, char* nome) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (strcmp(lista->alunos[i].nome, nome) == 0) {
            for (int j = i; j < lista->tamanho - 1; j++) {
                lista->alunos[j] = lista->alunos[j + 1];
            }
            lista->tamanho--;
            return;
        }
    }
    printf("Aluno não encontrado!\n");
}

void ordenarLista(Lista* lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        for (int j = i + 1; j < lista->tamanho; j++) {
            if (lista->alunos[i].nota < lista->alunos[j].nota) {
                Aluno temp = lista->alunos[i];
                lista->alunos[i] = lista->alunos[j];
                lista->alunos[j] = temp;
            }
        }
    }
}

void apresentarLista(Lista* lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        printf("Nome: %s, Nota: %.2f, Status: %c\n", lista->alunos[i].nome, lista->alunos[i].nota, lista->alunos[i].status);
    }
}

void apresentarAlunosAtivos(Lista* lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->alunos[i].status == 'A') {
            printf("Nome: %s, Nota: %.2f, Status: %c\n", lista->alunos[i].nome, lista->alunos[i].nota, lista->alunos[i].status);
        }
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese"); 
    Lista lista;
    lista.tamanho = 0;

    int opcao;
    char nome[20];
    float nota;
    char status;
    Aluno aluno;

    do {
        printf("\n1. Incluir aluno\n2. Excluir aluno\n3. Ordenar lista\n4. Apresentar lista\n5. Apresentar alunos ativos\n6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Nome do aluno: ");
                scanf("%s", aluno.nome);
                printf("Nota do aluno: ");
                scanf("%f", &aluno.nota);
                printf("Status do aluno (A para ativo, C para cancelado): ");
                scanf(" %c", &aluno.status);
                incluirAluno(&lista, aluno);
                break;
            case 2:
                printf("Nome do aluno a excluir: ");
                scanf("%s", nome);
                excluirAluno(&lista, nome);
                break;
            case 3:
                ordenarLista(&lista);
                break;
            case 4:
                apresentarLista(&lista);
                break;
            case 5:
                apresentarAlunosAtivos(&lista);
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 6);

    return 0;
}





