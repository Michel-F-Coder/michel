#include <stdio.h>
#include <stdbool.h>

int menu;
int retornara = 1;
float saldo;
float deposito;
float saque;
FILE *saldo_da_conta;

void consulta();
void depositar();
void sacar();

int banco()
{

    printf("=========== BANCO SENAI ==========\n\n");
    printf("1 - CONSULTAR SALDO\n");
    printf("2 - DEPOSITAR\n");
    printf("3 - SACAR\n");
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:
        consulta();
        break;

    case 2:
        depositar();
        break;

    case 3:
        sacar();
        break;
    }
}

void consulta()
{

    printf("============ CONSULTA SALDO=============\n\n");

    saldo_da_conta = fopen("arquivos/banco/conta.txt", "r");

    if (saldo_da_conta == NULL)
    {
        printf("\nErro ao abrir o arquivo\n");
    }

    fscanf(saldo_da_conta, "Saldo atual: R$ %f\n", &saldo);

    printf("Saldo atual: R$ %.2f\n\n", saldo);

    fclose(saldo_da_conta);
}

void depositar()
{
    printf("=============== DEPOSITO ============\n\n");

    saldo_da_conta = fopen("arquivos/banco/conta.txt", "r");

    if (saldo_da_conta == NULL)
    {
        printf("\nErro ao abrir o arquivo\n");
    }

    fscanf(saldo_da_conta, "Saldo atual: R$ %f\n", &saldo);

    fclose(saldo_da_conta);

    saldo_da_conta = fopen("arquivos/banco/conta.txt", "w");

    if (saldo_da_conta == NULL)
    {
        printf("\nErro ao abrir o arquivo\n");
    }

    printf("SALDO: R$ %.2f\n\n", saldo);
    printf("Qual o valor do deposito?\n\n");
    scanf("%f", &deposito);

    saldo = (deposito + saldo);

    fprintf(saldo_da_conta, "Saldo atual: R$ %f\n", saldo);

    printf("Deposito realizado com sucesso!\n\n");

    fclose(saldo_da_conta);
}

void sacar()
{
    printf("========== SAQUE ===========\n\n");

    saldo_da_conta = fopen("arquivos/banco/conta.txt", "r");

    if (saldo_da_conta == NULL)
    {
        printf("\nErro ao abrir o arquivo\n");
    }

    fscanf(saldo_da_conta, "Saldo atual: R$ %f\n", &saldo);

    fclose(saldo_da_conta);

    saldo_da_conta = fopen("arquivos/banco/conta.txt", "w");

    if (saldo_da_conta == NULL)
    {
        printf("\nErro ao abrir o arquivo\n");
    }

    printf("SALDO: R$ %.2f\n\n", saldo);
    printf("Qual valor voce deseja sacar?");
    scanf("%f", &saque);

    saldo = (saldo - saque);

    fprintf(saldo_da_conta, "Saldo atual: R$ %f\n", saldo);

    printf("Saque realizado com sucesso!\n\n");

    fclose(saldo_da_conta);
}