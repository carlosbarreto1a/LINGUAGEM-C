#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<locale.h>
#define MAX_CLIENTES 100
#define MAX_QUARTOS 50
#define MAX_RESERVAS 200

typedef struct {
    int id;
    char nome[100];
} Cliente;

typedef struct {
    int numero;
    int ocupado;
} Quarto;

typedef struct {
    int idCliente;
    int numeroQuarto;
    int diaInicio;
    int diaFim;
} Reserva;

Cliente clientes[MAX_CLIENTES];
int totalClientes = 0;

Quarto quartos[MAX_QUARTOS];
int totalQuartos = 0;

Reserva reservas[MAX_RESERVAS];
int totalReservas = 0;

int clienteExiste(int id) {
    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].id == id) return 1;
    }
    return 0;
}

int quartoExiste(int numero) {
    for (int i = 0; i < totalQuartos; i++) {
        if (quartos[i].numero == numero) return 1;
    }
    return 0;
}

void cadastrarCliente() {
    if (totalClientes >= MAX_CLIENTES) {
        printf("Limite de clientes atingido.\n");
        return;
    }

    Cliente novo;
    novo.id = totalClientes + 1;
    printf("Nome do cliente: ");
    scanf(" %[^\n]", novo.nome);
    clientes[totalClientes++] = novo;
    printf("Cliente cadastrado com ID %d.\n", novo.id);
}

void listarClientes() {
    for (int i = 0; i < totalClientes; i++) {
        printf("ID: %d | Nome: %s\n", clientes[i].id, clientes[i].nome);
    }
}

void cadastrarQuarto() {
    if (totalQuartos >= MAX_QUARTOS) {
        printf("Limite de quartos atingido.\n");
        return;
    }

    Quarto novo;
    printf("Número do quarto: ");
    scanf("%d", &novo.numero);

    // Evita cadastrar quartos duplicados
    if (quartoExiste(novo.numero)) {
        printf("Quarto já existe.\n");
        return;
    }

    novo.ocupado = 0;
    quartos[totalQuartos++] = novo;
    printf("Quarto %d cadastrado com sucesso.\n", novo.numero);
}

void listarQuartos() {
    for (int i = 0; i < totalQuartos; i++) {
        printf("Quarto %d | Status: %s\n", quartos[i].numero, quartos[i].ocupado ? "Ocupado" : "Disponível");
    }
}

void listarQuartosDisponiveis() {
    for (int i = 0; i < totalQuartos; i++) {
        if (!quartos[i].ocupado) {
            printf("Quarto %d disponível\n", quartos[i].numero);
        }
    }
}

int verificarDisponibilidade(int numero, int inicio, int fim) {
    for (int i = 0; i < totalReservas; i++) {
        if (reservas[i].numeroQuarto == numero &&
            !(fim < reservas[i].diaInicio || inicio > reservas[i].diaFim)) {
            return 0;
        }
    }
    return 1;
}

void efetuarReserva() {
    int idCliente, numero, inicio, fim;
    printf("ID do cliente: ");
    scanf("%d", &idCliente);

    if (!clienteExiste(idCliente)) {
        printf("Cliente com ID %d não encontrado.\n", idCliente);
        return;
    }

    printf("Número do quarto: ");
    scanf("%d", &numero);

    if (!quartoExiste(numero)) {
        printf("Quarto %d não encontrado.\n", numero);
        return;
    }

    printf("Dia de início da reserva: ");
    scanf("%d", &inicio);
    printf("Dia de fim da reserva: ");
    scanf("%d", &fim);

    if (inicio > fim) {
        printf("Data inválida.\n");
        return;
    }

    if (!verificarDisponibilidade(numero, inicio, fim)) {
        printf("Quarto não está disponível nesse período.\n");
        return;
    }

    Reserva nova;
    nova.idCliente = idCliente;
    nova.numeroQuarto = numero;
    nova.diaInicio = inicio;
    nova.diaFim = fim;
    reservas[totalReservas++] = nova;

    printf("Reserva efetuada com sucesso.\n");
}

void listarReservasEmAberto() {
    for (int i = 0; i < totalReservas; i++) {
        printf("Cliente %d | Quarto %d | Dias %d até %d\n",
               reservas[i].idCliente, reservas[i].numeroQuarto,
               reservas[i].diaInicio, reservas[i].diaFim);
    }
}

void listarReservasPorPeriodo() {
    int inicio, fim;
    printf("Dia início: ");
    scanf("%d", &inicio);
    printf("Dia fim: ");
    scanf("%d", &fim);

    for (int i = 0; i < totalReservas; i++) {
        if (!(fim < reservas[i].diaInicio || inicio > reservas[i].diaFim)) {
            printf("Cliente %d | Quarto %d | Dias %d até %d\n",
                   reservas[i].idCliente, reservas[i].numeroQuarto,
                   reservas[i].diaInicio, reservas[i].diaFim);
        }
    }
}

int main() {
	setlocale(LC_ALL,"");
    int opcao;
    

    do {
        printf("\n1 - Cadastrar cliente\n");
        printf("2 - Listar clientes\n");
        printf("3 - Cadastrar quarto\n");
        printf("4 - Listar quartos\n");
        printf("5 - Listar quartos disponíveis\n");
        printf("6 - Efetuar reserva\n");
        printf("7 - Listar reservas em aberto\n");
        printf("8 - Listar reservas por período\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarCliente(); break;
            case 2: listarClientes(); break;
            case 3: cadastrarQuarto(); break;
            case 4: listarQuartos(); break;
            case 5: listarQuartosDisponiveis(); break;
            case 6: efetuarReserva(); break;
            case 7: listarReservasEmAberto(); break;
            case 8: listarReservasPorPeriodo(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}
