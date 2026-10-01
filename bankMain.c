#include <stdio.h>
#include <string.h>

void adicionarCliente(char *nome, char *cpf, double saldo) {
    FILE *arquivo = fopen("clientes.txt", "a");;
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        return;
    }
    
    fprintf(arquivo, "%s,%s,%.2f\n", nome, cpf, saldo);
    fclose(arquivo);
}

void exibirCliente(char *cpf) {
    FILE *arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        return;
    }

    char nome[100], cpf_arquivo[15];
    double saldo;

    while (fscanf(arquivo, "%[^,],%[^,],%lf\n", nome, cpf_arquivo, &saldo) == 3) {
        if (strcmp(cpf, cpf_arquivo) == 0) {
            printf("Nome: %s\n", nome);
            printf("CPF: %s\n", cpf_arquivo);
            printf("Saldo: %.2f\n", saldo);
            break;
        }
    }

    fclose(arquivo);
}

int main() {
    printf("Bem vindo ao Sistema de Gestão Bancária!\n");
    adicionarCliente("João da Silva", "123.456.789-00", 1000.00);
    exibirCliente("123.456.789-00");
    return 0;
}