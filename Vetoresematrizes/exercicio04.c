/*exercicio 04 Escreva um programa em C que leia duas matrizes 3x3 de inteiros e realize a
mulüphcaçao dessas matnzes. O resultado da multiplicação deve ser
armazenado em uma terceira matriz e exibido na tela. Lembre-se de que para
realizar a multiplicação de matrues. o nignero de colunas da prime•ra matriz
deve ser qual ao número de linhas da segunda matnz.*/

int main(){

    int matrizA[3][3], matrizB[3][3], matrizResultado[3][3];
    int j, i, k, soma;
    
    printf("Popule a matriz para multiplicacao:\n");

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++) {
            scanf("%d", &matrizA[i][j]);
        }
    }

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            scanf("%d", &matrizB[i][j]);
        }    
    }
    
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
           soma = 0;
           for(k = 0; k < 3; k++){
            soma += matrizA[i][k] * matrizB[k][j];
           }
           matrizResultado[i][j] = soma;
        }    
    }

    printf("Matriz resultante da multiplicacao: \n");
      for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
          printf("%d\n", matrizResultado[i][j]);
        }
        printf("\n");    
    }
    
        
    return 0;
}
