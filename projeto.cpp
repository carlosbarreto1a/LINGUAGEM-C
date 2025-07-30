#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>

#define MAX_CLIENTES 100
#define MAX_QUARTOS 100

typedef struct {
    char nome[50];
    char cpf[15];
    char telefone[15];
} Cadastro;

typedef struct {
    int numQuarto;
    char tipo;
} Quarto;

Cadastro clientes[MAX_CLIENTES];
Quarto quartos[MAX_QUARTOS];
int totalClientes = 0;
int totalQuartos = 0;

void cadastrarCliente() {
    if (totalClientes >= MAX_CLIENTES) {
        printf("Máximo de clientes atingido!\n");
        return;
    }

    printf("Nome completo: ");
    fflush(stdin);
    gets(clientes[totalClientes].nome);

    printf("CPF: ");
    scanf("%s", clientes[totalClientes].cpf);

    printf("Telefone: ");
    scanf("%s", clientes[totalClientes].telefone);

    totalClientes++;
    printf("Cliente cadastrado!\n\n");
}

void listarClientes() {
    if (totalClientes == 0) {
        printf("Nenhum cliente cadastrado.\n\n");
        return;
    }

    for (int i = 0; i < totalClientes; i++) {
        printf("Nome: %s | CPF: %s | Telefone: %s\n", clientes[i].nome, clientes[i].cpf, clientes[i].telefone);
    }
    printf("\n");
}

void cadastrarQuarto() {
    if (totalQuartos >= MAX_QUARTOS) {
        printf("Máximo de quartos atingido!\n");
        return;
    }

    printf("Número do quarto: ");
    scanf("%d", &quartos[totalQuartos].numQuarto);

    printf("Tipo do quarto (SOLTEIRO / CASAL / CASAL COM FILHO): \n");
    fflush(stdin);
    scanf(" %s", &quartos[totalQuartos].tipo); 

    totalQuartos++;
    printf("Quarto cadastrado!\n\n");
}

void listarQuartos() {
    if (totalQuartos == 0) {
        printf("Nenhum quarto cadastrado.\n\n");
        return;
    }

    for (int i = 0; i < totalQuartos; i++) {
        printf("Número: %d | Tipo: %c\n", quartos[i].numQuarto, quartos[i].tipo);
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao;

    do {
        printf("\t======== HOTEL SENAI ==========\n");
        printf("\t1 - Cadastrar Cliente\n");
        printf("\t2 - Listar Clientes\n");
        printf("\t3 - Cadastrar Quarto\n");
        printf("\t4 - Listar Quartos\n");
        printf("\t0 - Sair\n");
        printf("\tEscolha: ");
        scanf("%d", &opcao);
        system("cls");

        switch (opcao) {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                listarClientes();
                break;
            case 3:
                cadastrarQuarto();
                break;
            case 4:
                listarQuartos();
                break;
            case 0:
                printf("Encerrando o programa...\n");
                Sleep(1000);
                printf("Encerrando o programa..\n");
                Sleep(1000);
                printf("Encerrando o programa.\n");
                Sleep(1000);
                printf("\nPrograma Encerrado!");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}