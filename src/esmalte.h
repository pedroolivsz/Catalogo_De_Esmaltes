#ifndef ESMALTE_H
#define ESMALTE_H

typedef struct{
    int id;
    char nome[50];
    char cor[40];
    char tipo[40];
    char marca[50];
    char validade[20];
    float preco;
    int quantidade;
} Esmalte;
void cadastrarEsmalte(Esmalte catalogo[], int *quantidade_total);
void listarEsmaltes(Esmalte catalogo[], int quantidade_total);
void editarEsmalte(Esmalte catalogo[], int quantidade_total);

#endif