#include <stdio.h>
#include <string.h>

#define MAX_ESMALTES 100
#define ARQUIVO "esmaltes.txt"

typedef struct{
   int id;
   char nome[50];
   char cor[50];
   char marca[50];
   float preco;
} Esmalte;

void salvarEsmalte(Esmalte catalogo[], int total);

int carregarEsmaltes(Esmalte catalogo[]);

void adicionarEsmalte(Esmalte catalogo[], int *total); //Ja foi

void listarEsmaltes(Esmalte catalogo[], int total); // Ja foi

void buscarPorCor(Esmalte catalogo[], int total);

void buscarPorMarca(Esmalte catalogo[], int total);

void buscarPorPreco(Esmalte catalogo[], int total);

void editarEsmalte(Esmalte catalogo[], int total);

void excluirEsmalte(Esmalte catalogo[], int *total);

int main(){

   Esmalte catalogo[MAX_ESMALTES];
   int totalEsmaltes = carregarEsmaltes(catalogo);
   int opcao;
   
   do{
      printf("\n====| Catálogo de Esmaltes |====\n");
      printf("[1]. Adicionar esmalte\n");
      printf("[2]. Listar esmaltes\n");
      printf("[3]. Buscar por cor\n");
      printf("[4]. Buscar por marca\n");
      printf("[5]. Buscar por faixa de preço\n");
      printf("[6]. Editar esmalte\n");
      printf("[7]. Excluir esmalte\n");
      printf("[0]. Sair\n");
      printf("Escolha: ");
      scanf("%d", &opcao);
      
      switch (opcao) {

         case 0:
            printf("Encerrando programa...\n");
            break;

         case 1:
            adicionarEsmalte(catalogo, &totalEsmaltes);
            break;

         case 2:
            listarEsmaltes(catalogo, totalEsmaltes);
            break;
      
         case 3:
            buscarPorCor(catalogo, totalEsmaltes);
            break;
      
         case 4:
            buscarPorMarca(catalogo, totalEsmaltes);
            break;
      
         case 5:
            buscarPorPreco(catalogo, totalEsmaltes);
            break;
      
         case 6:
            editarEsmalte(catalogo, totalEsmaltes);
            break;
   
         case 7:
            excluirEsmalte(catalogo, &totalEsmaltes);
            break;
         
         default:
            printf("Opção inválida! Tente novamente!");
      }
   } while(opcao != 0);
   return 0;
}
void salvarEsmalte(Esmalte catalogo[], int total) {
   FILE *fp = fopen (ARQUIVO, "w");
   if (fp == NULL){
      printf("Erro ao salvar o arquivo\n");
      return;
   }
   for (int i = 0; i < total; i++) {
      fprintf(fp, "%d |%s |%s |%s |%.2f\n",
      catalogo[i].id,
      catalogo[i].nome,
      catalogo[i].cor,
      catalogo[i].marca,
      catalogo[i].preco);
   } fclose(fp);
}
int carregarEsmaltes(Esmalte catalogo[]) {
   FILE *fp = fopen(ARQUIVO, "r");
   if(fp == NULL)return 0;
   
   int total = 0;
      while(fscanf(fp, "%d | %49[^|] | %29[^|] | %29[^|] | %f\n",
      &catalogo[total].id,
      catalogo[total].nome,
      catalogo[total].cor,
      catalogo[total].marca,
      &catalogo[total].preco) == 5) {
         total++;
      }
      
      fclose(fp);
      return total;
}
void adicionarEsmalte(Esmalte catalogo[], int *total) {
   if (*total >= MAX_ESMALTES) {
      printf("Catalogo cheio!\n");
      return;
   }
   
   printf("\n===-| Adicionar esmalte |-===\n");
   
   getchar();
   
   printf("Nome: ");
   fgets(catalogo[*total].nome, sizeof(catalogo[*total].nome), stdin);
   catalogo[*total].nome[strcspn(catalogo[*total].nome, "\n")] = '\0';
   
   printf("Cor: ");
   fgets(catalogo[*total].cor, sizeof(catalogo[*total].cor), stdin);
   catalogo[*total].cor[strcspn(catalogo[*total].cor, "\n")] = '\0';
   
   printf("Marca: ");
   fgets(catalogo[*total].marca, sizeof(catalogo[*total].marca), stdin);
   catalogo[*total].marca[strcspn(catalogo[*total].marca, "\n")] = '\0';
   
   do{ printf("Preço: ");
       scanf("%f", &catalogo[*total].preco);
       if (catalogo[*total].preco < 0)
           printf("Valor inválido. Tente novamente!\n");
       }while (catalogo[*total].preco < 0);
   
   catalogo[*total].id = *total + 1;
   
   (*total)++;
   salvarEsmalte(catalogo, *total);
   printf("Esmalte adicionado com sucesso!\n");
}
void listarEsmaltes(Esmalte catalogo[], int total) {
   printf("\n=== Lista de Esmaltes ===\n");
   if(total == 0) {
      printf("Nenhum esmalte cadastrado.\n");
      return;
   }
   
   for (int i = 0;i<total;i++){
      printf("ID: %d\n", catalogo[i].id);
      printf("Nome: %s\n", catalogo[i].nome);
      printf("Cor: %s\n", catalogo[i].cor);
      printf("Marca: %s\n", catalogo[i].marca);
      printf("Preço: %.2f\n", catalogo[i].preco);
      printf("================\n");
   }
}
void buscarPorCor(Esmalte catalogo[], int total){

   char cor[30];
   
   printf("Digite a cor para buscar: ");
   getchar();
   fgets(cor, sizeof(cor), stdin);
   cor[strcspn(cor, "\n")] = '\0';
   
   int encontrados = 0;
   for (int i = 0;i<total;i++){
      if(strcasecmp(catalogo[i].cor, cor) == 0){
         printf("ID: %d|%s|%s|%.2f \n",
          catalogo[i].id,
          catalogo[i].nome,
          catalogo[i].cor,
          catalogo[i].preco);
         encontrados ++;
      }
   }
   
   if (encontrados == 0) {
      printf("Nenhum esmalte com essa cor foi encontrado.\n");
   }
}
void buscarPorMarca(Esmalte catalogo[], int total){

   char marca[50];
   
   printf("Digite o nome da marca a se encontrada: ");
   getchar();
   fgets(marca, sizeof(marca), stdin);
   marca[strcspn(marca, "\n")] = '\0';
   
   int encontrados = 0;
   
   for (int i = 0;i<total;i++){
      if(strcasecmp(catalogo[i].marca, marca) == 0) {
         printf("ID: %d|%s|%s|%.2f\n", catalogo[i].id, catalogo[i].nome, catalogo[i].cor, catalogo[i].preco);
         encontrados++;
         }
      }
      if (encontrados == 0){
         printf("Nenhum esmalte dessa marca foi encontrado.\n");
      }
}
void buscarPorPreco(Esmalte catalogo[], int total){

   float min, max;
   
   printf("Digite o preço mínimo: ");
   scanf("%f", &min);
   printf("Digite o preço maximo: ");
   scanf("%f", &max);
   
   int encontrados = 0;
   
   for (int i=0;i<total;i++){
      if (catalogo[i].preco >= min && catalogo[i].preco <= max) {
         printf("ID: %d | %s | %s | %s | %.2f\n",
          catalogo[i].id, 
          catalogo[i].nome,
          catalogo[i].cor, 
          catalogo[i].marca,
          catalogo[i].preco);
         encontrados++;
      }
   }
   if(encontrados == 0){
      printf("Nenhum esmalte encontrado nessa faixa de preço.\n");
   }
}
void editarEsmalte(Esmalte catalogo[], int total) {

    int id;
    
    printf("Digite o ID do esmalte: ");
    scanf("%d", &id);
    
    for(int i = 0; i<total; i++){
        if(catalogo[i].id == id) {
            printf("Atualizar nome: ");
            getchar();
            fgets(catalogo[i].nome, sizeof(catalogo[i].nome), stdin);
            catalogo[i].nome[strcspn(catalogo[i].nome, "\n")] = '\0';
        
            printf("Atualizar cor: ");
            fgets(catalogo[i].cor, sizeof(catalogo[i].cor), stdin);
            catalogo[i].cor[strcspn(catalogo[i].cor, "\n")] = '\0';
            
            printf("Atualizar marca: ");
            fgets(catalogo[i].marca, sizeof(catalogo[i].marca), stdin);
            catalogo[i].marca[strcspn(catalogo[i].marca, "\n")] = '\0';
            
            printf("Atualizar preço: ");
            scanf("%f", &catalogo[i].preco);
            
            salvarEsmalte(catalogo, total);
            printf("O esmalte de ID: %d foi atualizado com sucesso! \n", id);
            return;
        }
    }
}
void excluirEsmalte(Esmalte catalogo[], int *total) {
    int id, i, encontrados = 0;
    
    printf("Digite o ID do esmalte a ser excluído: ");
    scanf("%d", &id);
    
    for(i = 0; i < *total; i++){
        if(catalogo[i].id == id){
            encontrados = 1;
            break;
        }
    }    
    if(!encontrados) {
        printf("O ID: %d não foi localizado no catálogo.\n", id);
        return;
    }
    for(int j = i; j < *total - 1; j++){
        catalogo[j] = catalogo[j + 1];
    }
    
    (*total)--;
    
    for(int k = 0; k < *total; k++){
        catalogo[k].id = k + 1;
    }
    salvarEsmalte(catalogo, *total);
    printf("Esmalte de id: %d excluído com sucesso!\n", id);
    return;
}