#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>

int code = 0;
#define TAM 100

void limparBuffer() {
	fflush(stdout);
	printf("\n");
	system("pause");
	system("cls");
}

struct Pedido {
	char nome[50];
	int codigoPedido;
	float valores[3];
};

struct Pedido pedido[TAM];
	
void cadastrarPedido() {
	int qntdPratos;
	float valor;
		
	if(code == TAM - 1) {
		printf("Cadastro lotado!!");
		return;
	} 
	else {
		printf("Qual seu nome? ");
  		scanf("%s", &pedido[code].nome);

		pedido[code].codigoPedido = code;	  
  
  		do{
  			printf("\nQual a quantidade de pratos?(1-3) ");
	  		scanf("%d", &qntdPratos);
	  		
	  		if (qntdPratos < 1 || qntdPratos > 3) {
	  			printf("\nQuantidade inválida!");
			  }
		} while (qntdPratos < 1 || qntdPratos > 3);
		
		for (int i = 0; i < qntdPratos; i++) {
			printf("\nDigite o valor do prato %d: R$", i+1);
			scanf("%f", &pedido[code].valores[i]);
		}
		
		printf("\nCadastro realizado!");
		code++;
		limparBuffer();
	}										 						
}


float calcularTotalPedido(int codigoBusca) {
	float valorTotal = 0.0;
	for (int i = 0; i < 3; i++) {
		valorTotal += pedido[codigoBusca].valores[i];
	}
	return valorTotal;
}

void classificarPedidos(){
 	int valorFiltro;
 	int achou = 0;
 	
 	printf("Filtrar Pedidos\n");
 	
 	if (strcmp(pedido[0].nome, "") == 0) {
		printf("\nSem cadastros no sistema!\n");
	} else {
		printf("Qual o valor do filtro? R$");
		scanf("%d", &valorFiltro);													 

		for(int i = 0; i < code; i++) {
			if(valorFiltro < calcularTotalPedido(i)){
				printf("\nNome do cliente: ");
				printf("%s", pedido[i].nome);
		
				printf("\nCódigo do pedido: ");
				printf("%d", pedido[i].codigoPedido);
			 
			 	printf("\nValor total: R$");
				printf("%.2f\n", calcularTotalPedido(i));	
				
				achou = 1;	 	
	 		}
	 	}
	 	
	 	if (achou == 0) printf("\nNenhum pedido encontrado!\n");
	}
	
	limparBuffer();	
}

void exibirValoresTotais() {
	printf("Contas dos pedidos\n");
	
	if (strcmp(pedido[0].nome, "") == 0) {
		printf("\nSem cadastros no sistema!\n");
	} else {
		for(int i = 0; i < code; i++) {
			printf("\nNome do cliente: ");
			printf("%s", pedido[i].nome);
	
			printf("\nCódigo do pedido: ");
			printf("%d", pedido[i].codigoPedido);
		 
		 	printf("\nValor total: R$");
			printf("%.2f\n", calcularTotalPedido(i));		 	
 		}	
	}
 	
 	limparBuffer();
}

void gerarRelatorio() {
	float clienteCaro = 0.0;
	float clienteBarato = 9999.0;
	float total;
	printf("Relatorio\n");
	
	for (int i = 0; i < code; i++) {
		total = calcularTotalPedido(i);
		if (clienteCaro < total) clienteCaro = total;
		if (clienteBarato > total) clienteBarato = total;
	}
	
	printf("\nQuantidade total de pedidos cadastrados: %d\n\nCliente com pedido mais caro: R$%.2f\n\nCliente com pedido mais barato: R$%.2f\n", code, clienteCaro, clienteBarato);
	limparBuffer();
}

void opcao(int escolha) {
	switch(escolha) {
		case 1:
			cadastrarPedido();
			break;
		case 2:
			exibirValoresTotais();
			break;
		case 3:
			classificarPedidos();
			break;
		case 4:
			gerarRelatorio();
			break;
		case 5:
			printf("Encerrando o programa...\n");
			Sleep(1000);
			printf("Encerrando o programa..\n");
			Sleep(1000);
			printf("Encerrando o programa.\n");
			Sleep(1000);
			printf("\nPrograma Encerrado!");
			break;
		default:
			return;
	} 
}

int main() {
	int escolha = 0;
	setlocale(LC_ALL, "portuguese");
	while (escolha != 5) {
		do {
			printf("Menu Principal\n");
			printf("1- Cadastrar pedido\n2- Exibir valores totais dos pedidos\n3- Exibir clientes com pedidos acima de um valor determinado\n4- Relatório final\n5- Sair");
			printf("\nDigite a opcao desejada: ");
			scanf("%d", &escolha);
			
			if (escolha < 1 || escolha > 5) {
				printf("Opção Inválida!");
				limparBuffer();
			} else {
				system("cls");
				opcao(escolha);
			}
		} while (escolha < 1 || escolha > 5);	
	}
}