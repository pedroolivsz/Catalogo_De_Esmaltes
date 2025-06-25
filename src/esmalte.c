#include <stdio.h>
#include <string.h>
#include "esmalte.h"

#define TAM_MAX 100

void cadastrarEsmalte(Esmalte catalogo[], int *quantidade_total) {

    int quantidade_aux = *quantidade_total;

    if(*quantidade_total>=TAM_MAX){
        printf("Catálogo cheio! Não foi possível cadastrar o esmalte");
        return;
    }

    getchar();
    printf("=== Adicionar esmaltes ===\n");

    printf("Nome: ");
    fgets(catalogo[quantidade_aux].nome, sizeof(catalogo[quantidade_aux].nome), stdin);
    catalogo[quantidade_aux].nome[strcspn(catalogo[quantidade_aux].nome, "\n")] = '\0';

    printf("Cor: ");
    fgets(catalogo[quantidade_aux].cor, sizeof(catalogo[quantidade_aux].cor), stdin);
    catalogo[quantidade_aux].cor[strcspn(catalogo[quantidade_aux].cor, "\n")] = '\0';

    printf("Tipo: ");
    fgets(catalogo[quantidade_aux].tipo, sizeof(catalogo[quantidade_aux].tipo), stdin);
    catalogo[quantidade_aux].tipo[strcspn(catalogo[quantidade_aux].tipo, "\n")] = '\0';

    printf("Marca: ");
    fgets(catalogo[quantidade_aux].marca, sizeof(catalogo[quantidade_aux].marca), stdin);
    catalogo[quantidade_aux].marca[strcspn(catalogo[quantidade_aux].marca, "\n")] = '\0';

    printf("Validade: ");
    fgets(catalogo[quantidade_aux].validade, sizeof(catalogo[quantidade_aux].validade), stdin);
    catalogo[quantidade_aux].validade[strcspn(catalogo[quantidade_aux].validade, "\n")] = '\0';

    do{
        printf("Preço: ");
        scanf("%f", &catalogo[quantidade_aux].preco);

        while(getchar() != '\n');

        if(catalogo[quantidade_aux].preco < 0) {
            printf("Preço inválido! Tente novamente.\n");
        }
    } while(catalogo[quantidade_aux].preco < 0);
        
    do {
        printf("Quantidade: ");
        scanf("%d", &catalogo[quantidade_aux].quantidade);

        while(getchar() != '\n');

        if(catalogo[quantidade_aux].quantidade < 1) {
            printf("Quantidade invalida! Tente novamente.\n");
        }
    } while(catalogo[quantidade_aux].quantidade < 1);
    
    catalogo[quantidade_aux].id = quantidade_aux + 1;

    (*quantidade_total)++;

    printf("\n=== Esmalte cadastrado com sucesso! ===\n\n");
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
        printf("===========================\n\n");
    }
    return;
}
void editarEmalte(Esmalte catalogo[], int quantidade_total) {
    int id;
    int search_id;
    int edit_id;
    int encontrado = 0;
    printf("Insira o ID do esmalte: ");
    scanf("%d", &id);

    for(search_id=0; search_id<quantidade_total; search_id++) {
        if(search_id == id) {
            encontrado = 1;
            edit_id = search_id;
            break;
        }
    }
    if(encontrado == 0) {
        printf("Erro! Nenhum esmalte no catálogo possui o ID informado.\n");
        return;
    }
    if(encontrado == 1) {
        getchar();
        printf("=== Editar esmalte ===\n");

        printf("Editar nome: ");
        fgets(catalogo[edit_id].nome, sizeof(catalogo[edit_id].nome), stdin);
        catalogo[edit_id].nome[strcspn(catalogo[edit_id].nome, "\n")] = '\0';

        printf("Editar cor: ");
        fgets(catalogo[edit_id].cor, sizeof(catalogo[edit_id].cor), stdin);
        catalogo[edit_id].cor[strcspn(catalogo[edit_id].cor, "\n")] = '\0';

        printf("Editar tipo: ");
        fgets(catalogo[edit_id].tipo, sizeof(catalogo[edit_id].tipo), stdin);
        catalogo[edit_id].tipo[strcspn(catalogo[edit_id].tipo, "\n")] = '\0';

        printf("Editar marca: ");
        fgets(catalogo[edit_id].marca, sizeof(catalogo[edit_id].marca), stdin);
        catalogo[edit_id].marca[strcspn(catalogo[edit_id].marca, "\n")] = '\0';

        printf("Editar data de validade: ");
        fgets(catalogo[edit_id].validade, sizeof(catalogo[edit_id].validade), stdin);
        catalogo[edit_id].validade[strcspn(catalogo[edit_id].validade, "\n")] = '\0';

        do{
            printf("Editar preço: ");
            scanf("%f", &catalogo[edit_id].preco);

            while(getchar() != '\n');

            if(catalogo[edit_id].preco < 0) {
                printf("Preço inválido! Tente novamente.\n");
            }
        } while(catalogo[edit_id].preco < 0);
        
        do {
            printf("Editar quantidade: ");
            scanf("%d", &catalogo[edit_id].quantidade);

            while(getchar() != '\n');

            if(catalogo[edit_id].quantidade < 1) {
                printf("Quantidade invalida! Tente novamente.\n");
            }
        } while(catalogo[edit_id].quantidade < 1);

        printf("\n=== Esmalte editado com sucesso! ===\n\n");
    }
    return;
}