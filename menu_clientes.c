#include "menu_header.h"
#include <stdio.h>

void cadastro_cliente();

void clientes()
{
    int opcao_cliente;

    printf("1. Cadastrar novo Cliente\n2. Atualizar pontuação\n3. Atualizar cadastro de Cliente\n");
    printf("4. Listar Clientes entre 18 e 25 anos\n5. Listar Clientes com mais de [1000] pontos\n9. Voltar\n");
    scanf( "%d",&opcao_cliente);

    switch(opcao_cliente)
    {
        case 1: cadastro_cliente();
        break;

        case 9: printf("\nVoltando\n");
        break;

        default: printf("opcao invalida\n");
        break;
    }
}

void cadastro_cliente()
{
    char CPF[13];
    char Nome[50];
    int Dia,Mes,Ano;
    char Endereco[50];
    char Cidade[50];
    char Estado[2];
    int Pontos = 0;

    printf("Informe o CPF:\n");
    scanf(" %[^\n]s",CPF);

    printf("Informe o Nome:\n");
    scanf(" %[^\n]s",Nome);

    printf("Informe o DD MM AAAA de nascimento:\n");
    scanf(" %d %d %d",&Dia,&Mes,&Ano);

    printf("Informe o Endereço:\n");
    scanf(" %[^\n]s",Endereco);

    printf("Informe a Cidade:\n");
    scanf(" %[^\n]s",Cidade);

    printf("Informe o Estado(sigla):\n");
    scanf(" %[^\n]s",Estado);


}