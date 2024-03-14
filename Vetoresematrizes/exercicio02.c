/*Exercicio  2 Escreva um programa em C que leta um vetor de 5 elementos nteros e exiba
o manr elemento e a sua posçao no vetor */

int main(void){

    int numeros[5];
    int maior, posicao;

    scanf("%d", &numeros[0]);
    maior = numeros[0];
    posicao = 0;

     for (int i = 1; i < 5; i++){
        scanf("%d", &numeros[i]);

        if(numeros[i] > maior){
            maior = numeros[i];
            posicao= i;
        }
    }

    printf("O maior eh: %d\n", maior);
    printf("A posicao do meu maior eh: %d\n", posicao);

    return 0;

}
