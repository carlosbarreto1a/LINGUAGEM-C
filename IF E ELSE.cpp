#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main() {
	int num1;
	int resto;
	
	printf("DIGITE UM NUMERO INTEIRO AI VA: \n");
	scanf("%D", &num1);
	
	resto =  num1 % 2;
	
	printf("Resto da divisao: = %d\n", resto);
	
	if(resto == 0 )
	printf("Numero par!\n");
	
	else {
		   printf("Numero impar!!!!!!!!!!!!!!!!!!!");
		 
		
	}
 
	}
	
	
	