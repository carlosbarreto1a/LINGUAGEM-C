#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>



struct Produto {
	int codigo;
	float preco;
  	char nome[30];	
};

int main () {
	struct Produto produto[3];
	
  for(int i = 0; i < 3; i++) {
  printf("cadastre o codigos dos produtos: ");
  scanf("%d", &produto[i].codigo);
  
  fflush(stdin);
  
  printf("cadastre os nomes do produtos: ");
  scanf("%s", &produto[i].nome);
  
  printf("cadastre os preco do  produtos: ");
  scanf("%f", &produto[i].preco);
}
   fflush(stdin);
   for(int i = 0; i < 3; i++) {
  printf("\nPRODUTOS CADASTRADOS\n");
  printf("\ncodigo do produto %d",produto[i].codigo);
  printf("\nnome do produto %s" ,produto[i].nome);
  printf("\npreco do produto %.2f", produto[i].preco);
}
}
