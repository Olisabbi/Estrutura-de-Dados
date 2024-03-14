/*Exercicio 03 Escreva um programa em C que leia uma matriz 3x3 de inteiros e calcule a
sorna de todos os elementos da matnz. Em seguida, exiba o resultado da
soma na tela. */

int main(){

    int matriz[3][3];
    int soma = 0;
    printf("Popule a matriz para soma:\n");

    for (int  i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            soma += matriz[i][j];
        }
        
    }
    

    printf("A soma dos elementos da matriz eh: %d\n", soma);
        
    return 0;
}
