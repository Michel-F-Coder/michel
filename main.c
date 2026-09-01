#include <stdio.h>  
#include <stdlib.h>
#include <windows.h>

#include "boletim.c"
#include "calculadora.c"
#include "banco.c"
#include "estacionamento.c"



int main() 
{
    int opcao = 1;


    while(opcao != 0)
    {
       
        printf("======= SISTEMA DE ATIVIDADES ========\n");
        printf("Escolha uma das opções a baixo:\n");
        printf("1 - BOLETIM ESCOLAR\n");
        printf("2 - CALCULADORA\n");
        printf("3 - BANCO\n");
        printf("4 - estacionamento\n");
        printf("0 - SAIR\n");
        scanf("%d", &opcao);

            switch (opcao)
            {
            case 0:
            printf("Fechando sistema...\n");
            exit(0);
            break;

            case 1:
            boletim();
            break;

            case 2:
            calculadora();
            break;

            case 3:
            banco();
            break;   

            case 4:
            estacionamento();
            break;  

            default:
            printf("Opção inválida!\n");
            
            }
            
    }

}

