/* 5- Escreva uma fun��o que recebe, por par�metro, um valor inteiro e positivo e retorna o somat�rio desse valor. */

#include <stdio.h>
#include<stdlib.h>

int main(void)

{
 int v1, v2, resultado; 
	
	printf("Digite o primeiro valor: ");
	scanf("/d", &v1);
	
	printf("Digite o segundo valor: ");
	scanf("/d", &v2);
	
	resultado =v1 / v2;
	printf("Resultado =%.2d\n", resultado);
	
	return 0;
	
	system("pause");
}

