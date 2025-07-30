//4. Crie uma STRUCT chamada Data com os campos dia, mes e ano. Escreva um programa em Cque solicita ao usuário que insira duas datas e determine qual delas ocorreu primeiro.

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>



struct Data {
	
	int dia, mes, ano;	
};

int main () {
	
	struct Data data1, data2;
		
	printf("Informe uma data (dd/mm/aaaa :  \n");
	scanf("%d %d %d",&data1.dia, &data1.mes, &data1.ano);
		
	printf("Informe outra data (dd/mm/aaaa :  \n");
	scanf("%d %d %d",&data2.dia, &data2.mes, &data2.ano);
	
		  
	if(data1.ano < data2.ano) {
		printf("A data 1 ocorreu primeiro!!!");
	} else if(data1.ano > data2.ano) {
		printf("A data 2 ocorreu primeiro!!!");
	} else if(data1.mes < data2.mes) {
		printf("A data 1 ocorreu primeiro!!!");
	} else if(data1.mes > data2.mes) {
		printf("A data 2 ocorreu primeiro!!!");
	} else if(data1.dia < data2.dia) {
		printf("A data 1 ocorreu primeiro!!!");
	} else if(data1.dia > data2.dia) {
		printf("A data 2 ocorreu primeiro!!!");
	} else {
		printf("As datas sao iguais!!");
	}
	return 0;
	system("pause");
}