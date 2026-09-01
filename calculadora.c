#include <stdio.h>  
#include <stdbool.h>

float num1, num2, resultado;
int retornar = 1;
int operacao;


int calculadora()
{
    while(retornar == 1)
    {   

    printf("=========== CALCULADORA ==============\n\n");

    printf("Digite o primeiro numero: ");
    scanf("%f", &num1);

    printf("Esolha a operação: \n\n");
    printf("1 - DIVIDIR\n");
    printf("2 - MULTIPLICAR\n");
    printf("3 - SUBTRAIR\n");
    printf("4 - SOMAR\n");
    scanf("%d", &operacao);

    printf("Digite o segundo numero: ");
    scanf("%f", &num2);


        switch(operacao)
        {
            case 1:
            resultado = (num1 / num2);
            break;
            
            case 2:
            resultado = (num1 * num2);
            break;

            case 3:
            resultado = (num1 - num2);
            break;

            case 4:
            resultado = (num1 + num2);
            break;
        }

    printf("\n\nResultado: %f\n\n", resultado);  

    printf("Gostaria de fazer outro calculo?\n");    
    printf("1 - SIM\n");
    printf("2 - NÃO\n");
    scanf("%d", &retornar);       





    }







}