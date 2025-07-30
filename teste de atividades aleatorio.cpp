#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

struct Pessoa1{
	int num1, num2;	
	
};

void soma(int a, int b){
	int resultado;
	
	resultado = a + b; 
	
	printf("resultado  %d\n");
}


int main () {
	struct Pessoa1 pessoa1;
	
	
	printf("DIGITE UM NUMERO AI VA VEY   \n");
	scanf("%d",&pessoa1.num1);
	
	
	printf("DIGITE OUTRO NUMERO AI VA VEY   \n");
	scanf("%d", &pessoa1.num2);
	
	
	soma(pessoa1.num1, pessoa1.num2);
	
	system("pause");
	return 0;
}