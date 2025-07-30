#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100

typedef struct {
    int id;
    char nome[50];
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
} Reserva;

int gerarId() {
    return rand() % 100000;
}


void cadastrarCliente() {
    Cliente c;
    FILE *f = fopen("clientes.txt", "a");

    c.id = gerarId();
    printf("Nome do cliente: ");
    scanf(" %[^\n]", c.nome);

    fprintf(f, "%d;%s\n", c.id, c.nome);
    fclose(f);
    printf("Cliente cadastrado com sucesso!\n");
}

void listarClientes() {
    FILE *f = fopen("clientes.txt", "r");
    Cliente c;

    printf("\n--- Lista de Clientes ---\n");
    while (fscanf(f, "%d;%[^;\n]\n", &c.id, c.nome) != EOF) {
        printf("ID: %d | Nome: %s\n", c.id, c.nome);
    }
    fclose(f);
}

void cadastrarQuarto() {
    Quarto q;
    FILE *f = fopen("quartos.txt", "a");

    printf("Número do quarto: ");
    scanf("%d", &q.numero);
    q.ocupado = 0;

    fprintf(f, "%d;%d\n", q.numero, q.ocupado);
    fclose(f);
    printf("Quarto cadastrado com sucesso!\n");
}

void listarQuartos() {
    FILE *f = fopen("quartos.txt", "r");
    Quarto q;

    printf("\n--- Lista de Quartos ---\n");
    while (fscanf(f, "%d;%d\n", &q.numero, &q.ocupado) != EOF) {
        printf("Quarto: %d | Status: %s\n", q.numero, q.ocupado ? "Ocupado" : "Disponível");
    }
    fclose(f);
}


void listarQuartosDisponiveis() {
    FILE *f = fopen("quartos.txt", "r");
    Quarto q;

    printf("\n--- Quartos Disponíveis ---\n");
    while (fscanf(f, "%d;%d\n", &q.numero, &q.ocupado) != EOF) {
        if (!q.ocupado)
            printf("Quarto: %d\n", q.numero);
    }
    fclose(f);
}

void atualizarStatusQuarto(int numeroQuarto, int status) {
    FILE *f = fopen("quartos.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    Quarto q;

    while (fscanf(f, "%d;%d\n", &q.numero, &q.ocupado) != EOF) {
        if (q.numero == numeroQuarto) {
            q.ocupado = status;
        }
        fprintf(temp, "%d;%d\n", q.numero, q.ocupado);
    }

    fclose(f);
    fclose(temp);
    remove("quartos.txt");
    rename("temp.txt", "quartos.txt");
}


void fazerReserva() {
    listarClientes();
    int idCliente, numeroQuarto;
    char dataInicio[11], dataFim[11];

    printf("ID do cliente: ");
    scanf("%d", &idCliente);

    listarQuartosDisponiveis();
    printf("Número do quarto: ");
    scanf("%d", &numeroQuarto);

    printf("Data de início (dd/mm/aaaa): ");
    scanf(" %10s", dataInicio);
    printf("Data de fim (dd/mm/aaaa): ");
    scanf(" %10s", dataFim);

    FILE *f = fopen("reservas.txt", "a");
    Reserva r;
    r.idReserva = gerarId();
    r.idCliente = idCliente;
    r.numeroQuarto = numeroQuarto;
    strcpy(r.dataInicio, dataInicio);
    strcpy(r.dataFim, dataFim);

    fprintf(f, "%d;%d;%d;%s;%s\n", r.idReserva, r.idCliente, r.numeroQuarto, r.dataInicio, r.dataFim);
    fclose(f);

    atualizarStatusQuarto(numeroQuarto, 1);
    printf("Reserva realizada com sucesso!\n");
}


void listarReservasAbertas() {
    FILE *f = fopen("reservas.txt", "r");
    Reserva r;

    printf("\n--- Reservas em Aberto ---\n");
    while (fscanf(f, "%d;%d;%d;%[^;];%[^;\n]\n", &r.idReserva, &r.idCliente, &r.numeroQuarto, r.dataInicio, r.dataFim) != EOF) {
        printf("Reserva ID: %d | Cliente ID: %d | Quarto: %d | De %s até %s\n",
               r.idReserva, r.idCliente, r.numeroQuarto, r.dataInicio, r.dataFim);
    }
    fclose(f);
}


void listarReservasPorPeriodo() {
    char inicio[11], fim[11];
    printf("Data início (dd/mm/aaaa): ");
    scanf(" %10s", inicio);
    printf("Data fim (dd/mm/aaaa): ");
    scanf(" %10s", fim);

    FILE *f = fopen("reservas.txt", "r");
    Reserva r;

    printf("\n--- Reservas no Período ---\n");
    while (fscanf(f, "%d;%d;%d;%[^;];%[^;\n]\n", &r.idReserva, &r.idCliente, &r.numeroQuarto, r.dataInicio, r.dataFim) != EOF) {
        if (strcmp(r.dataInicio, fim) <= 0 && strcmp(r.dataFim, inicio) >= 0) {
            printf("Reserva ID: %d | Cliente ID: %d | Quarto: %d | De %s até %s\n",
                   r.idReserva, r.idCliente, r.numeroQuarto, r.dataInicio, r.dataFim);
        }
    }

    fclose(f);
}

int main() {
    srand(time(NULL));
    int opcao;

    do {
        printf("\n---- MENU ----\n");
        printf("1 - Cadastrar Cliente\n");
        printf("2 - Listar Clientes\n");
        printf("3 - Cadastrar Quarto\n");
        printf("4 - Listar Quartos\n");
        printf("5 - Listar Quartos Disponíveis\n");
        printf("6 - Fazer Reserva\n");
        printf("7 - Listar Reservas em Aberto\n");
        printf("8 - Listar Reservas por Período\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarCliente(); break;
            case 2: listarClientes(); break;
            case 3: cadastrarQuarto(); break;
            case 4: listarQuartos(); break;
            case 5: listarQuartosDisponiveis(); break;
            case 6: fazerReserva(); break;
            case 7: listarReservasAbertas(); break;
            case 8: listarReservasPorPeriodo(); break;
            case 0: printf("Encerrando o programa...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
