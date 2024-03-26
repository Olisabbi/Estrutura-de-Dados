#include <stdio.h>
#include <string.h>

#define MAX 40

typedef struct {
char nome[20];
float nota;
char status;
} Aluno;

typedef struct {
Aluno dado[MAX];
int n= 0;
} ListaDisciplina;

ListaDisciplina lista;
Aluno aluno;

//Protótipos das funções
void instancia(Aluno *, char *, float, float, char);
void ordenar(ListaDisciplina *);
int inserir (ListaDisciplina *, int, Aluno);
int remover (ListaDisciplina *, int);
int imprimir (ListaDisciplina *);
void imprimirAtivos(ListaDisciplina *);

//Implementação das funções de acesso à lista
void instancia(Aluno *aluno, char *nome, float nota, char status) {
strcpy(aluno->nome, nome);
aluno->nota= nota;
aluno->status= status;
}

int inserir (ListaDisciplina *L, int pos, Aluno aluno) {
if ((L->n == MAX) || (pos > L->n + 1))
return 0;

int i;
for (i= L->n; i >= pos; i--)
L->dado[i]= L->dado[i-1];

L->dado[pos-1]= aluno;
(L->n)++;
return 1;
}

int remover (ListaDisciplina *L, int pos){
int i;
if ((pos > L->n) || (pos <= 0))
return 0;

for (i= pos; i <= (L->n)-1; i++)
L->dado[i-1]= L->dado[i];

(L->n)--;
return 1;
}

int imprimir (ListaDisciplina *L){
int i;
printf("%-3s %-10s %-5s %-6s \n", "Pos", "Aluno",
"nota", "Status");
printf("%-3s %-10s %-5s %-6s \n", "---", "----------",
"-----", "------");

int total= L->n;
for (i= 0; i < total; i++)
printf("%-3d %-10s %-5.1f %-6c \n", i+1, L->dado[i].nome, L->dado[i].nota, L->dado[i].status);

printf("\n");
}

void imprimirAtivos(ListaDisciplina *L) {
int i;
printf("%-3s %-10s %-5s %-6s \n", "Pos", "Aluno", "nota", "Status");
printf("%-3s %-10s %-5s %-6s \n", "---", "----------",
"-----", "------");
int total= L->n;
for (i= 0; i < total; i++) {
if (L->dado[i].status == 'A')
printf("%-3d %-10s %-5.1f %-6c \n", i+1, L->dado[i].nome, L->dado[i].nota, L->dado[i].status);
}
}

void ordenar(ListaDisciplina *L) {
int i, j, max;
int n= L->n;
Aluno temp;
for (i= 0; i < n-1; i++) {
max= i;
for (j= i+1; j < n; j++) {
if (L->dado[j].nota > L->dado[max].nota)
max= j;

temp= L->dado[max];
L->dado[max]= L->dado[i];
L->dado[i]= temp;
}
}
}

main() {
float m;

instancia(&aluno, "Pedro", 8.9, 'A');
inserir(&lista, 1, aluno);
printf("Pedro adicionado na posicao 1. \n");

instancia(&aluno, "Ana", 8.7, 'A');
inserir(&lista, 2, aluno);
printf("Ana adicionada na posicao 2. \n");

instancia(&aluno, "Maria", 9.3, 'I');
inserir(&lista, 3, aluno);
printf("Maria adicionada na posicao 3. \n\n");

imprimir(&lista);

remover(&lista, 1);
printf("Pedro removido da posicao 1. \n");

imprimir(&lista);

instancia(&aluno, "Paula", 9.1, 'A');
inserir(&lista, 1, aluno);
printf("Paula adicionada na posicao 1. \n");

imprimir(&lista);

instancia(&aluno, "Pedro", 8.9, 'I');
inserir(&lista, 2, aluno);
printf("Pedro adicionado na posicao 2. \n");

instancia(&aluno, "Joao", 9.8, 'A');
inserir(&lista, 5, aluno);
printf("Joao adicionado na posicao 5. \n\n");

imprimir(&lista);

ordenar(&lista);
printf("Lista classificada por nota decrescente. \n");
imprimir(&lista);

ordenar(&lista);
printf("Lista de alunos ativos. \n");
imprimirAtivos(&lista);

}


Pos Aluno nota Status

--- ---------- ----- ------

1 Paula 9.1 A

2 Pedro 8.9 I

3 Ana 8.7 A

4 Maria 9.3 I

5 Joao 9.8 A



Lista classificada por nota decrescente.

Pos Aluno nota Status

--- ---------- ----- ------

1 Joao 9.8 A

2 Maria 9.3 I

3 Paula 9.1 A

4 Pedro 8.9 I

5 Ana 8.7 A



Lista de alunos ativos.

Pos Aluno nota Status

--- ---------- ----- ------

1 Joao 9.8 A

3 Paula 9.1 A

5 Ana 8.7 A

​​