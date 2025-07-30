#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>





int main () {
	setlocale(LC_ALL, "");

	
	
	
	int dia;
	
	printf("Digite um numero de 1 a 7   \n");
	scanf("%d", &dia);
	
	
	
	switch (dia){
		
		case 1: 
		printf("segunda-feira \n");
		break;
		
		
		case 2: 
		printf("terça-feira \n");
		break;
		
		
		case 3: 
		printf("quarta-feira \n");
		break;
		
		case 4: 
		printf("quinta-feira \n");
		break;
		
		case 5: 
		printf("sexta-feira \n");
		break;
		
		case 6: 
		printf("sábado \n");
		break;
		
		case 7: 
		printf("Domingo \n");
		break;
	}
	
	

system("pause");
	
	return 0;
}