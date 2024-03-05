#include <stdio.h>

int main(void){

    const int variedadeMaterial = 3;
    const int precoMaterial = 2;

    float estoque[variedadeMaterial][precoMaterial];
    float mediaPreco[variedadeMaterial];
    float media = 0;

    printf("Insira os valores dos materiais 1:\n");

    for (int material = 0; material < variedadeMaterial; ++material){ 
        for (int preco = 0; preco < precoMaterial; ++preco){
            scanf("%f", &estoque[material][preco]);
            media += estoque[material][preco];
        }
        mediaPreco[material] = media / precoMaterial;
        media = 0;
        printf("Insira os valores dos materiais %i:\n", material + 2);

    }

    for (int material = 0; material < variedadeMaterial; ++material){
        printf("A media dos materiais %i e %.2f\n", material + 1, mediaPreco[material]);
    }

    return 0;
}
