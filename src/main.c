#include <stdio.h>
#include "esmalte.h"

#define TAM_MAX 100

int main() {
    Esmalte catalogo[TAM_MAX];
    int quantidade_total = 0;
    int escolha;

    do {
        printf("===== Menu =====\n");
        printf("1. Adicionar esmalte ao catálogo.\n");
        printf("2. Listar esmaltes.\n");
        printf("===== Escolha uma opção: ");
        scanf("%d", &escolha);
    }while(escolha!=0);
    
}
