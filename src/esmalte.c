#include <stdio.h>
#include <string.h>
#include "esmalte.h"

#define TAM_TOTAL 100

void cadastrarEsmaltes(Esmalte catalogo[], int *quantidade_total) {
    if(*quantidade_total>=TAM_TOTAL){
        printf("Catálogo cheio! Não foi possível cadastrar o esmalte");
        return;
    }
    *quantidade_total+=1;
    getchar();
    printf("=== Adicionar esmaltes ===\n");

    printf("Nome: ");
    fgets(catalogo[*quantidade_total].nome, sizeof(catalogo[*quantidade_total].nome), stdin);
    catalogo[*quantidade_total].nome[strcspn(catalogo[*quantidade_total].nome, "\n")] = '\0';

    printf("Cor: ");
    fgets(catalogo[*quantidade_total].cor, sizeof(catalogo[*quantidade_total].cor), stdin);
    catalogo[*quantidade_total].cor[strcspn(catalogo[*quantidade_total].cor, "\n")] = '\0';

    printf("Tipo: ");
    fgets(catalogo[*quantidade_total].tipo, sizeof(catalogo[*quantidade_total].tipo), stdin);
    catalogo[*quantidade_total].tipo[strcspn(catalogo[*quantidade_total].tipo, "\n")] = '\0';

    printf("Marca: ");
    fgets(catalogo[*quantidade_total].marca, sizeof(catalogo[*quantidade_total].marca), stdin);
    catalogo[*quantidade_total].marca[strcspn(catalogo[*quantidade_total].marca, "\n")] = '\0';

    printf("Validade: ");
    fgets(catalogo[*quantidade_total].validade, sizeof(catalogo[*quantidade_total].validade), stdin);
    catalogo[*quantidade_total].validade[strcspn(catalogo[*quantidade_total].validade, "\n")] = '\0';

    do{
        printf("Preço: ");
        scanf("%d", &catalogo[*quantidade_total].preco);
    } while(catalogo[*quantidade_total].preco < 0);

    do{
        printf("Quantidade: ");
        scanf("%d", &catalogo[*quantidade_total].quantidade);
    } while(catalogo[*quantidade_total].quantidade < 1);
    
    catalogo[*quantidade_total].id = *quantidade_total + 1;
    
    (*quantidade_total)++;

    printf("\n=== Esmalte cadastrado com sucesso! ===\n");
    return;
}