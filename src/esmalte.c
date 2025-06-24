#include <stdio.h>
#include <string.h>
#include "esmalte.h"

#define TAM_MAX 100

void cadastrarEsmalte(Esmalte catalogo[], int *quantidade_total) {
    if(*quantidade_total>=TAM_MAX){
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

        if(catalogo[*quantidade_total].preco < 0) {
            printf("Preço inválido. Tente novamente\n");
        }

    } while(catalogo[*quantidade_total].preco < 0);

    do{
        printf("Quantidade: ");
        scanf("%d", &catalogo[*quantidade_total].quantidade);

        if(catalogo[*quantidade_total].quantidade < 1) {
            printf("Quantidade inválida. Tente novamente\n");
        }

    } while(catalogo[*quantidade_total].quantidade < 1);
    
    catalogo[*quantidade_total].id = *quantidade_total + 1;

    (*quantidade_total)++;

    printf("\n=== Esmalte cadastrado com sucesso! ===\n");
    return;
}
void listarEsmaltes(Esmalte catalogo[], int quantidade_total) {
    int listar;
    printf("\n=====Lista de Esmaltes =====\n");
    if(quantidade_total==0) {
        printf("Catálogo vazio!\n");
        return;
    }
    for(listar=0; listar<quantidade_total; listar++) {
        printf("\n===== Produto ID:%d =====\n", catalogo[listar].id);
        printf("Nome: %s\n", catalogo[listar].nome);
        printf("Cor: %s\n", catalogo[listar].cor);
        printf("Tipo: %s\n", catalogo[listar].tipo);
        printf("Marca: %s\n", catalogo[listar].marca);
        printf("Data de validade: %s\n", catalogo[listar].validade);
        printf("Preço: R$%.2f\n", catalogo[listar].preco);
        printf("Quantidade em estoque: %d\n", catalogo[listar].quantidade);
        printf("===========================\n");
    }
    return;
}