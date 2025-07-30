#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>



void apresentacao(void){
	
	printf("olá, meu caro amigo tudo joia ? /n");
	
	printf("Qual o seu nome ?   /n");
	
	
}

int somar(int a, int b){

return a + b;
}



int main () {
	int a;
	int b;
	int soma;
	
	printf("digite um numero:    \n");
	scanf("%d",& a);
	printf("digite outro numero:    \n");
	scanf("%d",& b);


soma = somar(a,b);


printf("A SOMA DESSES NUMEROS:  %d\n  ", soma);

system("pause");
}