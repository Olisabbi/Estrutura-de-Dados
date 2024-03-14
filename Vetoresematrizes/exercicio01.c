
/* Exercicio 01 Escreva programa em C que leta Ign vetor de 10 elementos mtetros e exiba
a sorna de todos os elementos*/

int main(void){

    int numero[10];
    int soma = 0;

    printf("Digite 10 valores para somar no vetor:\n");
    
    for(int i = 0; i < 10; i++){
        scanf("%d", &numero[i]);
    }

    for (int i = 0; i < 10; i++)
        soma += numero[i];
    {
    
    printf("A soma dos numeros eh: %d\n", soma);

    }
    
 
    return 0;
}

