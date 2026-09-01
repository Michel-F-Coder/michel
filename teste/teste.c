#include <stdio.h>

int opcaolimpar;
char nascimento;
int quantidade = 10;
int i; 
int totalalunos;
int idade;
char nome[50];
float altura;


//fclose - fechar arquivo
//fprintf - Salvar informações no arquivo
//fopen - Abrir arquivo
// "a" - Adicionar
// "w" - Sobrescrever
// "r" - Ler

void main()
{
    FILE *arquivo;

    arquivo = fopen("teste.txt","a");

    if(arquivo == NULL)
    {
        printf("\nErro ao abrir o arquivo\n");

        //return 1;
    }

    // CADASTRANDO ALUNO 

    for(i = 0 ; i < quantidade; i++)
    {
        printf("\n======================\n");
        printf("Aluno %d\n", i + 1);
        printf("========================\n");

        printf("Nome: ");
        scanf("%49s", nome);

        printf("Idade: ");
        scanf("%d", &idade);

        printf("Altura: ");
        scanf("%f", &altura);

         // SALVANDO O NOME DO ALUNO

        fprintf(arquivo, "Nome: %s / Idade: %d / Altura: %.2f\n", nome, idade, altura);

        printf("\nAluno salvo com sucesso!\n");

    }
    
    fclose(arquivo);




    // LENDO ALUNOS CADASTRADOS

    
    arquivo = fopen("teste.txt","r");

    while(fscanf(arquivo,"Nome: %49s / Idade: %d / Altura: %f",nome,&idade,&altura) == 3)   
    {

        totalalunos++;

        printf("\nAluno %d\n", totalalunos);

        printf("Nome: %s\n", nome);
        printf("Idade: %d anos\n", idade);
        printf("Altura: %.2f m\n", altura);
        printf("Data Nasc: %10s\n",nascimento);
    }

    // LIMPANDO ARQUIVO

    if(opcaolimpar == 1)
    {
        //abrir arquivo com "w" apaga o conteudo anterior
        arquivo = fopen("arquivos/cadastros.txt", "w");

        if (arquivo == NULL)
        {
            printf("\nERRO AO ABRIR O ARQUIVO\n");

            //return 1;
        }

    //nao precisamos escrever nada, apenas abrir com "w" ja limpa o arquivo.

    fclose(arquivo);

    }

}