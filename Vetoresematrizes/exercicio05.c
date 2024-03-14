/* 5) Escreva um programa em C que declare uma vanável tntetra e pontetro
para essa variável, e atnbua valor à vanavel utihzando o ponteiro. */

int main(){

    int numero;
    int *ponteiro;

ponteiro = &numero;

*ponteiro = 10;
printf("O valor da variavel eh: %d\n", numero);

    return 0;
}