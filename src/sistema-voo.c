#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSAGEIROS 100
#define MAX_TRIPULANTES 100
#define MAX_VOOS 100
#define MAX_ASSENTOS 100
#define MAX_RESERVAS 100

typedef struct {
    int codigo;
    char nome[50];
    char endereco[100];
    char telefone[20];
    int fidelidade; //Fiel ou Não Fiel
    int pontos_fidelidade;
}Passageiro;

typedef struct {
    int codigo;
    char nome[50];
    char telefone[20];
    char cargo[50]; //Piloto, Copiloto, Comissário
}Tripulacao;

typedef struct {
    int codigo_voo;
    char data_voo[20];
    char hora_voo[20];
    char origem[50];
    char destino[50];
    int codigo_aviao;
    int tarifa;
    //int codigo_piloto;
    //int codigo_copiloto;
    //int codigo_comissario;
    int status; //Ativo ou Inativo
}Voo;

typedef struct {
    int numero_assento;
    int codigo_voo;
    int status; //Ocupado ou Livre
}Assento;

typedef struct {
    int codigo_voo;
    int numero_assento;
    int codigo_passageiro;
}Reserva;

Passageiro passageiros[MAX_PASSAGEIROS];
Tripulacao tripulantes[MAX_TRIPULANTES];
Voo voos[MAX_VOOS];
Assento assentos[MAX_ASSENTOS];
Reserva reservas[MAX_RESERVAS];

int qtd_passageiros = 0;
int qtd_tripulantes = 0;
int qtd_voos = 0;
int qtd_assentos = 0;
int qtd_reservas = 0;

// Função strptime 
char* strptime(const char* s, const char* format, struct tm* tm) {
    sscanf(s, "%4d-%2d-%2d", &tm->tm_year, &tm->tm_mon, &tm->tm_mday);
    tm->tm_year -= 1900;
    tm->tm_mon -= 1;
    tm->tm_hour = 0;
    tm->tm_min = 0;
    tm->tm_sec = 0;
    tm->tm_isdst = -1;
    return (char*)(s + strlen(s));
}

// Funções de utilidade
int gerar_codigo_passageiro() {
    return qtd_passageiros + 1;
}

int gerar_codigo_tripulacao() {
    return qtd_tripulantes + 1;
}

int gerar_codigo_voo() {
    return qtd_voos + 1;
}

int gerar_codigo_assento() {
    return qtd_assentos + 1;
}

void cadastrar_passageiro() {
    Passageiro novo_passageiro;
    novo_passageiro.codigo = gerar_codigo_passageiro();
    printf("Nome: ");
    scanf(" %[^\n]", novo_passageiro.nome);
    printf("Endereço: ");
    scanf(" %[^\n]", novo_passageiro.endereco);
    printf("Telefone: ");
    scanf(" %[^\n]", novo_passageiro.telefone);
    printf("Fidelidade (1) Sim ou (2) Nao): ");
    scanf(" %d", &novo_passageiro.fidelidade);

    novo_passageiro.pontos_fidelidade = 0;
    passageiros[qtd_passageiros] = novo_passageiro;
    qtd_passageiros++;

    printf("Passageiro cadastrado com sucesso! Código: %d\n", novo_passageiro.codigo);
}

void cadastrar_tripulante() {
    Tripulacao novo_tripulante;
    novo_tripulante.codigo = gerar_codigo_tripulacao();
    printf("Nome: ");
    scanf(" %[^\n]", novo_tripulante.nome);
    printf("Telefone: ");
    scanf(" %[^\n]", novo_tripulante.telefone);
    printf("Cargo (Piloto, Copiloto ou Comissário): ");
    scanf(" %[^\n]", novo_tripulante.cargo);

    tripulantes[qtd_tripulantes] = novo_tripulante;
    qtd_tripulantes++;

    printf("Tripulante cadastrado com sucesso! Código: %d\n", novo_tripulante.codigo);
}

void cadastrar_voo() {
    Voo novo_voo;
    novo_voo.codigo_voo = gerar_codigo_voo();
    printf("Data do voo (AAAA-MM-DD): ");
    scanf(" %[^\n]", novo_voo.data_voo);
    printf("Hora do voo (HH:MM): ");
    scanf(" %[^\n]", novo_voo.hora_voo);
    printf("Origem: ");
    scanf(" %[^\n]", novo_voo.origem);
    printf("Destino: ");
    scanf(" %[^\n]", novo_voo.destino);
    printf("Código do avião: ");
    scanf("%d", &novo_voo.codigo_aviao);
    //printf("Código do piloto: ");
    //scanf("%d", &novo_voo.codigo_piloto);
    //printf("Código do copiloto: ");
    //scanf("%d", &novo_voo.codigo_copiloto);
    //printf("Código do comissário: ");
    //scanf("%d", &novo_voo.codigo_comissario);
    printf("Status (1) Ativo ou (2) Inativo): ");
    scanf(" %d", &novo_voo.status);
    printf("Tarifa: ");
    scanf("%d", &novo_voo.tarifa);

    voos[qtd_voos] = novo_voo;
    qtd_voos++;

    printf("Voo cadastrado com sucesso! Código: %d\n", novo_voo.codigo_voo);
}
//
void cadastrar_assento() {
    Assento novo_assento;
    int codigo_voo, numero_assento, status;

    printf("Código do voo: ");
    scanf("%d", &codigo_voo);
    printf("Número do assento: ");
    scanf("%d", &numero_assento);
    printf("Status (1) Ocupado ou (2) Livre: ");
    scanf("%d", &status);
}

void cadastrar_reserva() {
    Reserva nova_reserva;
    int codigo_voo, numero_assento, codigo_passageiro;

    printf("Código do voo: ");
    scanf("%d", &codigo_voo);
    printf("Número do assento: ");
    scanf("%d", &numero_assento);
    printf("Código do passageiro: ");
    scanf("%d", &codigo_passageiro);

    int passageiro_existe = 0;
    for(int i = 0; i < qtd_passageiros; i++) {
        if(passageiros[i].codigo == codigo_passageiro) {
            passageiro_existe = 1;
            break;
        }
    }
    if(!passageiro_existe) {
        printf("Passageiro não encontrado!\n");
        return;
    }

    for (int i = 0; i < qtd_reservas; i++) {
        if (reservas[i].codigo_voo == codigo_voo && reservas[i].numero_assento == numero_assento) {
            printf("Assento já reservado!\n");
            return;
        }
    }
    
    nova_reserva.codigo_voo = codigo_voo;
    nova_reserva.numero_assento = numero_assento;
    nova_reserva.codigo_passageiro = codigo_passageiro;

    reservas[qtd_reservas] = nova_reserva;
    qtd_reservas++;

    for (int i = 0; i < qtd_assentos; i++) {
        if (assentos[i].codigo_voo == codigo_voo && assentos[i].numero_assento == numero_assento) {
            assentos[i].status = 1;
            break;
        }
    }

    printf("Reserva efetuada com sucesso!\n");
    
}


//Pesquisar Passageiro
void pesquisar_passageiro() {
    int codigo;
    char nome[50];
    printf("Pesquisar por (1) Código ou (2) Nome: ");
    int opcao;
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Codigo do passageiro: ");
        scanf("%d", &codigo);
        for(int i = 0; i < qtd_passageiros; i++) {
            if(passageiros[i].codigo == codigo) {
                printf("Passageiro encontrado: %s, %s, %s\n", passageiros[i].nome, passageiros[i].endereco, passageiros[i].telefone);
                return;
            }
        }
    } else if (opcao == 2) {
        printf("Nome do passageiro: ");
        scanf(" %[^\n]", nome);
        for (int i = 0; i < qtd_passageiros; i++) {
            if (strcmp(passageiros[i].nome, nome) == 0) {
                printf("Passageiro encontrado: %s, %s, %s\n", passageiros[i].nome, passageiros[i].endereco, passageiros[i].telefone);
                return;
            }
        }
    }
    printf("Passageiro não encontrado!\n");
}

//Pesquisar Tripulante
void pesquisar_tripulante() {
    int codigo;
    char nome[50];
    printf("Pesquisar por (1) Código ou (2) Nome: ");
    int opcao;
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Codigo do tripulante: ");
        scanf("%d", &codigo);
        for(int i = 0; i < qtd_tripulantes; i++) {
            if(tripulantes[i].codigo == codigo) {
                printf("Tripulante encontrado: %s, %s, %s\n", tripulantes[i].nome, tripulantes[i].telefone, tripulantes[i].cargo);
                return;
            }
        }
    } else if (opcao == 2) {
        printf("Nome do tripulante: ");
        scanf(" %[^\n]", nome);
        for (int i = 0; i < qtd_tripulantes; i++) {
            if (strcmp(tripulantes[i].nome, nome) == 0) {
                printf("Tripulante encontrado: %s, %s, %s\n", tripulantes[i].nome, tripulantes[i].telefone, tripulantes[i].cargo);
                return;
            }
        }
    }
    printf("Tripulante não encontrado!\n");
}

void listar_voos() {
    for(int i = 0; i < qtd_voos; i++) {
        printf("Voo %d: %s, %s, %s, %s, %d, %d\n", voos[i].codigo_voo, voos[i].data_voo, voos[i].hora_voo, voos[i].origem, voos[i].destino, voos[i].codigo_aviao, voos[i].tarifa);
    }
}




void menu_principal() {
    int opcao;
    do {
        printf("\n-----Sistema de Cadastro Voo Seguro-----\n");
        printf("1 - Cadastrar Passageiro\n");
        printf("2 - Cadastrar Tripulante\n");
        printf("3 - Cadastrar Voo\n");
        printf("4 - Cadastrar Assento\n");
        printf("5 - Realizar Reserva\n");
        printf("6 - Pesquisar Passageiros\n");
        printf("7 - Pesquisar Tripulantes\n");
        printf("8 - Listar Voos\n");
        printf("9 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrar_passageiro();
                break;
            case 2:
                cadastrar_tripulante();
                break;
            case 3:
                cadastrar_voo();
                break;
            case 4:
                cadastrar_assento();
                break;
            case 5:
                cadastrar_reserva();
                break;
            case 6:
                pesquisar_passageiro();
                break;
            case 7:
                pesquisar_tripulante();
                break;
            case 8:
                listar_voos();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);
}

int main() {
        menu_principal();
        return 0;
    }
