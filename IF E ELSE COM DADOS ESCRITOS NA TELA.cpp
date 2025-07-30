#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>


struct Pessoa {
   char nome, usuario, email ;
   float telefone;
   int idade;
  char senha[30]; 
};

int main () {
   struct Pessoa pessoa;
   
   printf("Informe sua idade:   ");
   scanf("%d", &pessoa.idade);
   
   if ( pessoa.idade <18){
   		printf("Menor de idade, pfvr passe para um maior de idade!   \n");
   }
    else{
  	printf("Maior de idade  \n");
 }
   
   	printf("Informe sua senha: ");
    scanf("%s", pessoa.senha);
   
 	 if (strlen(pessoa.senha) < 8) {
        printf("A senha deve conter pelo menos 8 caracteres\n");
    } else {
        printf("Senha aceita\n");
    }
	
	
	printf(" idade %d   /n/n",pessoa.idade );
	printf("senha %s  /n /n", pessoa.senha);
	
	system ("pause");
	return 0;
}