#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>

#define MAX_CLIENTES 100
#define MAX_QUARTOS 50
#define MAX_RESERVAS 100

typedef struct {
    char nome[50];
    char cpf[15];
    int id;
} Cliente;

typedef struct {
    int numero;
    int ocupado;
} Quarto;

typedef struct {
    int idReserva;
    int idCliente;
    int numeroQuarto;
    char dataInicio[11];
    char dataFim[11];
    char formaPagamento[20];
} Reserva;

Cliente clientes[MAX_CLIENTES];
Quarto quartos[MAX_QUARTOS];
Reserva reservas[MAX_RESERVAS];

int totalClientes = 0, totalQuartos = 0, totalReservas = 0;

void carregarClientes() {
    FILE *arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL) return;

    while (fscanf(arquivo, "%d;%49[^;];%14[^\n]\n", &clientes[totalClientes].id,
                  clientes[totalClientes].nome, clientes[totalClientes].cpf) == 3) {
        totalClientes++;
    }

    fclose(arquivo);
}

void carregarQuartos() {
    FILE *arquivo = fopen("quartos.txt", "r");
    if (arquivo == NULL) return;

    while (fscanf(arquivo, "%d;%d\n", &quartos[totalQuartos].numero, &quartos[totalQuartos].ocupado) == 2) {
        totalQuartos++;
    }

    fclose(arquivo);
}

void carregarReservas() {
    FILE *arquivo = fopen("reservas.txt", "r");
    if (arquivo == NULL) return;

    while (fscanf(arquivo, "%d;%d;%d;%10[^;];%10[^;];%19[^\n]\n",
                  &reservas[totalReservas].idReserva,
                  &reservas[totalReservas].idCliente,
                  &reservas[totalReservas].numeroQuarto,
                  reservas[totalReservas].dataInicio,
                  reservas[totalReservas].dataFim,
                  reservas[totalReservas].formaPagamento) == 6) {
        totalReservas++;
    }

    fclose(arquivo);
}

void salvarClientes() {
    FILE *arquivo = fopen("clientes.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao salvar clientes.\n");
        return;
    }

    for (int i = 0; i < totalClientes; i++) {
        fprintf(arquivo, "%d;%s;%s\n", clientes[i].id, clientes[i].nome, clientes[i].cpf);
    }

    fclose(arquivo);
}

void salvarQuartos() {
    FILE *arquivo = fopen("quartos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao salvar quartos.\n");
        return;
    }

    for (int i = 0; i < totalQuartos; i++) {
        fprintf(arquivo, "%d;%d\n", quartos[i].numero, quartos[i].ocupado);
    }

    fclose(arquivo);
}

void salvarReservas() {
    FILE *arquivo = fopen("reservas.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao salvar reservas.\n");
        return;
    }

    for (int i = 0; i < totalReservas; i++) {
        fprintf(arquivo, "%d;%d;%d;%s;%s;%s\n",
                reservas[i].idReserva,
                reservas[i].idCliente,
                reservas[i].numeroQuarto,
                reservas[i].dataInicio,
                reservas[i].dataFim,
                reservas[i].formaPagamento);
    }

    fclose(arquivo);
}

void cadastrarCliente() {
    if (totalClientes >= MAX_CLIENTES) {
        printf("Máximo de clientes atingido!\n");
        return;
    }

    Cliente *cad = &clientes[totalClientes];
    cad->id = totalClientes + 1;

    fflush(stdin);
    printf("Nome completo: ");
    fgets(cad->nome, sizeof(cad->nome), stdin);
    cad->nome[strcspn(cad->nome, "\n")] = '\0';

    fflush(stdin);
    printf("CPF: ");
    scanf(" %s", cad->cpf);

    totalClientes++;
    printf("Cliente cadastrado com sucesso! ID: %d\n", cad->id);
}

void listarClientes() {
    if (totalClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    system("cls");
    printf("===== LISTA DE CLIENTES =====\n");
    for (int i = 0; i < totalClientes; i++) {
        printf("ID   : %d\n", clientes[i].id);
        printf("Nome : %s\n", clientes[i].nome);
        printf("CPF  : %s\n", clientes[i].cpf);
        printf("---------------------------\n");
    }
    printf("Total: %d clientes listados.\n", totalClientes);
}

void cadastrarQuarto() {
    if (totalQuartos >= MAX_QUARTOS) {
        printf("Limite de quartos atingido.\n");
        return;
    }

    system("cls");
    printf("===== CADASTRAR NOVO QUARTO =====\n");
    printf("Número do quarto: ");
    scanf("%d", &quartos[totalQuartos].numero);
    quartos[totalQuartos].ocupado = 0;
    totalQuartos++;
    printf("Quarto cadastrado com sucesso!\n");
}

void listarQuartos() {
    for (int i = 0; i < totalQuartos; i++) {
        printf("Quarto %d - %s\n", quartos[i].numero, quartos[i].ocupado ? "Ocupado" : "Disponível");
    }
}

void listarQuartosDisponiveis() {
    for (int i = 0; i < totalQuartos; i++) {
        if (!quartos[i].ocupado) {
            printf("Quarto %d está disponível.\n", quartos[i].numero);
        }
    }
}

void fazerReserva() {
    if (totalReservas >= MAX_RESERVAS) {
        printf("Não é possível fazer mais reservas.\n");
        return;
    }

    int idCliente, numeroQuarto;
    char dataInicio[11], dataFim[11], formaPagamento[20];

    printf("ID do cliente: ");
    scanf("%d", &idCliente);
    printf("Número do quarto: ");
    scanf("%d", &numeroQuarto);

    int encontrado = 0;
    for (int i = 0; i < totalQuartos; i++) {
        if (quartos[i].numero == numeroQuarto && !quartos[i].ocupado) {
            quartos[i].ocupado = 1;
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Quarto não disponível.\n");
        return;
    }

    printf("Data de início (ex: 01-01-2025): ");
    scanf(" %10s", dataInicio);
    printf("Data de fim (ex: 05-01-2025): ");
    scanf(" %10s", dataFim);
    printf("Forma de pagamento: ");
    scanf(" %s", formaPagamento);

    Reserva *r = &reservas[totalReservas];
    r->idReserva = totalReservas + 1;
    r->idCliente = idCliente;
    r->numeroQuarto = numeroQuarto;
    strcpy(r->dataInicio, dataInicio);
    strcpy(r->dataFim, dataFim);
    strcpy(r->formaPagamento, formaPagamento);

    totalReservas++;
    printf("Reserva feita com sucesso!\n");
}

void listarReservasAbertas() {
    if (totalReservas == 0) {
        printf("Nenhuma reserva.\n");
        return;
    }

    for (int i = 0; i < totalReservas; i++) {
        printf("Reserva %d | Cliente ID: %d | Quarto: %d | De %s até %s | Pagamento: %s\n",
               reservas[i].idReserva, reservas[i].idCliente, reservas[i].numeroQuarto,
               reservas[i].dataInicio, reservas[i].dataFim, reservas[i].formaPagamento);
    }
}

void listarReservasPorPeriodo() {
    if (totalReservas == 0) {
        printf("Nenhuma reserva.\n");
        return;
    }

    char inicio[11], fim[11];
    printf("Informe a data de início do período (ex: 01-01-2025): ");
    scanf(" %s", inicio);
    printf("Informe a data de fim do período (ex: 10-01-2025): ");
    scanf(" %s", fim);

    int encontrou = 0;
    for (int i = 0; i < totalReservas; i++) {
        if (strcmp(reservas[i].dataInicio, fim) <= 0 && strcmp(reservas[i].dataFim, inicio) >= 0) {
            printf("Reserva %d | Cliente ID: %d | Quarto: %d | De %s até %s | Pagamento: %s\n",
                   reservas[i].idReserva, reservas[i].idCliente, reservas[i].numeroQuarto,
                   reservas[i].dataInicio, reservas[i].dataFim, reservas[i].formaPagamento);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhuma reserva encontrada no período informado.\n");
    }
}

void cancelarReserva() {
    int idReserva;
    printf("Digite o ID da reserva a ser cancelada: ");
    scanf("%d", &idReserva);

    int encontrado = 0;
    for (int i = 0; i < totalReservas; i++) {
        if (reservas[i].idReserva == idReserva) {
            for (int j = 0; j < totalQuartos; j++) {
                if (quartos[j].numero == reservas[i].numeroQuarto) {
                    quartos[j].ocupado = 0;
                    break;
                }
            }

            for (int k = i; k < totalReservas - 1; k++) {
                reservas[k] = reservas[k + 1];
            }
            totalReservas--;
            printf("Reserva cancelada com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Reserva com ID %d não encontrada.\n", idReserva);
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    carregarClientes();
    carregarQuartos();
    carregarReservas();

    int opcao;
    do {
        printf("\n======= HOTEL SENAI =======\n");
        printf("1 - Cadastrar Cliente\n");
        printf("2 - Listar Clientes\n");
        printf("3 - Cadastrar Quarto\n");
        printf("4 - Listar Quartos\n");
        printf("5 - Listar Quartos Disponíveis\n");
        printf("6 - Fazer Reserva\n");
        printf("7 - Listar Reservas em Aberto\n");
        printf("8 - Listar Reservas por Período\n");
        printf("9 - Cancelar Reserva\n");
        printf("0 - Sair e Salvar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

	 system("cls");
        switch (opcao) {
            case 1: cadastrarCliente(); break;
            case 2: listarClientes(); break;
            case 3: cadastrarQuarto(); break;
            case 4: listarQuartos(); break;
            case 5: listarQuartosDisponiveis(); break;
            case 6: fazerReserva(); break;
            case 7: listarReservasAbertas(); break;
            case 8: listarReservasPorPeriodo(); break;
            case 9: cancelarReserva(); break;
            case 0:
                salvarClientes();
                salvarQuartos();
                salvarReservas();
                printf("Dados salvos com sucesso!\n");
                printf("Encerrando o programa...\n");
                Sleep(1000);
                break;
            default:
            printf("Opção inválida!\n");
            
        }
    } while (opcao != 0);
    system("cls");
		
    return 0;
}