#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
 
//void apresentacao(void) (função sem retorno);
//{
//	int num1;
	
//	printf("Ola, este eh o curso de C \n");
//	scanf("%d", &num1);
//	printf("Espero que gostem....  \n");
//}



 int mutiplicacao ( int num1, int num2){
 	
 	int resultado;
 	
 	resultado =  num1 * num2;
 	return (resultado);
 }
 
 
int main () {
//	apresentacao();
	
	int v1, v2, resultado;
	
	printf("Digite um numero ai:  \n");
	scanf("%d", &v1);
	
	printf("Digite outro numero ai:  \n");
	scanf("%d", &v2);
	
	resultado = mutiplicacao(v1, v2);  //pegando a funcao aqu
	printf(" A somatoria dos numeros sao essa:  %d\n", resultado);
	
	
	printf("Digite um numero ai:  \n");
	scanf("%d", &v1);
	
	printf("Digite outro numero ai:  \n");
	scanf("%d", &v2);



	
	system("pause");
	return 0;
}
