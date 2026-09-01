#include <stdio.h>  
#include <stdbool.h>

int boletim() 
{
    float nota1;
    float nota2;
    float nota3;
    float nota4;
    float nota5;

    char nome[50];
    float media;

    int retornamento = 1;

    while(retornamento == 1)
    {
    system("cls");
    printf("=================SISTEMA DE BOLETIM=================\n\n");

    printf("Digite seu nome: ");
    scanf("%s", nome);

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);


    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    printf("Digite a quarta nota: ");
    scanf("%f", &nota4);

    printf("Digite a quinta nota: ");
    scanf("%f", &nota5);

    media = (nota1 + nota2 + nota3 + nota4 + nota5) / 5;
    
    system("cls");
    printf("\n---- RESULTADO ----\n");
    printf("Nome: %s\n", nome);
    printf("Nota 1: %.2f\n", nota1);
    printf("Nota 2: %.2f\n", nota2);
    printf("Nota 3: %.2f\n", nota3);
    printf("Nota 4: %.2f\n", nota4);
    printf("Nota 5: %.2f\n", nota5);
    printf("Media: %.2f\n", media);
 


    if(media >= 7)
    {
        printf("\nAPROVADO!!\n\n");
    }
    if(media > 5 && media < 7)
    {           

        printf("\nRECUPERAÇÃO!!\n\n");
    }
    if(media < 5)
    {
        printf("\nREPROVADO!!\n\n");
    }

    printf("Deseja retornar??\n");
    printf("1 - Refazer boletim\n");
    printf("2 - Retornar ao menu\n");
    scanf("%d",&retornamento);
    }
    
}
