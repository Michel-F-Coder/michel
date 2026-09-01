#include <stdio.h>
#include <stdbool.h>

float faturamento;
float taxa_de_ocupacao;
int i;
int retornar1 = 1;
int menu1;
int totalvagas = 20;
int vagas = 20;
char placa_do_veiculo[8];
float quantidade_de_horas;
int quantidade_motos;
int quantidade_carros;
int tipo_de_veiculo;
float valor_carro = 8.00;
float valor_moto = 5.00;
float valor_a_pagar_moto;
float valor_a_pagar_carro;
FILE *arquivo;
FILE *temporario;
FILE *caixa;

void exibir_faturamento();
void registrar_saida();
void registro_entrada();
void consultar_situacao();

void estacionamento()
{
    int totalvagas = 20;
    int vagas = 20;
    int quantidade_motos = 0;
    int quantidade_carros = 0;
    retornar1 = 0;

    printf("================ ESTACIONAMENTO SENAI ====================\n\n");
    printf("1 - Registrar entrada\n");
    printf("2 - Registrar saída\n");
    printf("3 - Consultar situação\n");
    printf("4 - Exibir faturamento\n");
    printf("5 - Encerrar sistema\n");
    scanf("%d", &menu1);

    printf("%d", menu1);

    switch (menu1)
    {
    case 1:
        registro_entrada();
        break;

    case 2:
        registrar_saida();
        break;

    case 3:
        consultar_situacao();
        break;

    case 4:
        exibir_faturamento();
        break;

    case 5:
        printf("Fechando sistema...\n");
        exit(0);
        break;
    }
}

void registro_entrada()
{
    printf("============ REGISTRO DE ENTRADA ==============\n\n");

    caixa = fopen("arquivos/estacionamento/caixa.txt", "a");

    arquivo = fopen("arquivos/estacionamento/cadastros.txt", "a");

    if (arquivo == NULL)
    {
        printf("\nErro ao abrir o arquivo cadastro\n");
    }
    if (caixa == NULL)
    {
        printf("\nErro ao abrir o arquivo caixa\n");
    }

    for (i = 0; i < 1; i++)
    {
        printf("\n======================\n");
        printf("Dados do veiculo\n");
        printf("========================\n");

        
        printf("Placa do veiculo: \n\n");
        scanf("%s", placa_do_veiculo);    

        printf("Tipo do veiculo: \n\n1 - CARRO\n2 - MOTO");
        scanf("%d", &tipo_de_veiculo);

        printf("Quantidade de horas: ");
        scanf("%f", &quantidade_de_horas);

        fprintf(arquivo, "Placa do veiculo: %7s / Tipo de veiculo: %d / Total de horas: %.2f\n", placa_do_veiculo, tipo_de_veiculo, quantidade_de_horas);

        fprintf(caixa, "Placa do veiculo: %7s / Tipo de veiculo: %d / Total de horas: %.2f\n", placa_do_veiculo, tipo_de_veiculo, quantidade_de_horas);

        printf("\nVeiculo salvo com sucesso!\n");

        vagas--;
    }

    fclose(arquivo);
    fclose(caixa);
}

void registrar_saida()
{
    printf("============ REGISTRO DE SAIDA ==============\n\n");

    int placa_encontrada = 0;
    char buscador_de_placa[6];

    temporario = fopen("arquivos/estacionamento/temporario.txt", "w");

    arquivo = fopen("arquivos/estacionamento/cadastros.txt", "r");

    if (arquivo == NULL)
    {
        printf("\nErro ao abrir o arquivo\n");
    }

    printf("Digite a placa do veiculo: ");
    scanf(" %7s", buscador_de_placa);

    while (fscanf(arquivo, "Placa do veiculo: %s / Tipo de veiculo: %d / Total de horas: %f\n", placa_do_veiculo, &tipo_de_veiculo, &quantidade_de_horas) == 3)
    {

        if (buscador_de_placa[0] == placa_do_veiculo[0] && buscador_de_placa[1] == placa_do_veiculo[1] && buscador_de_placa[2] == placa_do_veiculo[2] && buscador_de_placa[3] == placa_do_veiculo[3] && buscador_de_placa[4] == placa_do_veiculo[4] && buscador_de_placa[5] == placa_do_veiculo[5] && buscador_de_placa[6] == placa_do_veiculo[6])
        {
            placa_encontrada = 1;

            printf("======== DADOS DE SAIDA =========\n\n");

            printf("Placa: %s\n", placa_do_veiculo);
            printf("Tipo de Veiculo: %d\n", tipo_de_veiculo);
            printf("Quantidade de horas: %.2f\n", quantidade_de_horas);

            switch (tipo_de_veiculo)
            {
            case 1:
                valor_a_pagar_carro = quantidade_de_horas * valor_carro;
                printf("Valor a pagar: %.2f\n\n", valor_a_pagar_carro);
                break;

            case 2:
                valor_a_pagar_moto = quantidade_de_horas * valor_moto;
                printf("Valor a pagar: %.2f\n\n", valor_a_pagar_moto);
                break;
            }
        }
        else
        {
            fprintf(temporario, "Placa do veiculo: %s / Tipo de veiculo: %d / Total de horas: %.2f\n", placa_do_veiculo, tipo_de_veiculo, quantidade_de_horas);
        }
    }

    fclose(arquivo);
    fclose(temporario);

    if (placa_encontrada == 1)
    {
        remove("arquivos/estacionamento/cadastros.txt");

        rename("arquivos/estacionamento/temporario.txt", "arquivos/estacionamento/cadastros.txt");
    }
}

void consultar_situacao()
{
    printf("============ SITUAÇÃO DO ESTACIONAMENTO ==============\n\n");

    int totalvagas = 20;
    int vagas = 20;
    int quantidade_motos = 0;
    int quantidade_carros = 0;

    arquivo = fopen("arquivos/estacionamento/cadastros.txt", "r");

    if (arquivo == NULL)
    {
        printf("\nErro ao abrir o arquivo\n");
    }

    while (fscanf(arquivo, "Placa do veiculo: %s / Tipo de veiculo: %d / Total de horas: %f\n", placa_do_veiculo, &tipo_de_veiculo, &quantidade_de_horas) == 3)
    {
        switch (tipo_de_veiculo)
        {
        case 1:
            quantidade_carros++;
            vagas--;
            break;

        case 2:
            quantidade_motos++;
            vagas--;
            break;
        }
    }

    printf("Vagas totais: %d\n", totalvagas);
    printf("Quantidade de vagas disponiveis: %d\n", vagas);
    printf("Quantidade de carros: %d\n", quantidade_carros);
    printf("Quantidade de motos: %d\n", quantidade_motos);

    taxa_de_ocupacao = (((quantidade_carros + quantidade_motos) / 20.0) * 100);

    printf("Taxa de ocupação %.2f %%\n\n\n", taxa_de_ocupacao);
}

void exibir_faturamento()
{
    printf("============ $ FATURAMENTO $ ==============\n\n");

    caixa = fopen("arquivos/estacionamento/caixa.txt", "r");

    if (caixa == NULL)
    {
        printf("\nErro ao abrir o arquivo\n");
    }

    while (fscanf(caixa, "Placa do veiculo: %s / Tipo de veiculo: %d / Total de horas: %f\n", placa_do_veiculo, &tipo_de_veiculo, &quantidade_de_horas) == 3)
    {
        switch (tipo_de_veiculo)
        {
        case 1:
            valor_a_pagar_carro = quantidade_de_horas * 8;
            break;

        case 2:
            valor_a_pagar_moto = quantidade_de_horas * 5;
            break;
        }
    }
    fclose(caixa);

    faturamento = valor_a_pagar_carro + valor_a_pagar_moto;

    printf("Faturamento: R$ %.2f\n\n", faturamento);
}
