#include "menu_header.h"
#include <stdio.h>

void cadastro_cliente();
void cadastro_cliente_atualizar();
void listar_cliente_idade();
void listar_cliente_pontos();

void clientes()
{
    int opcao_cliente;

    printf("1. Cadastrar novo Cliente\n2. Atualizar cadastro de Cliente\n");
    printf("3. Listar Quantidade de Clientes entre 18 e 25 anos\n4. Listar Clientes com mais de [1000] pontos\n9. Voltar\n");
    scanf( "%d",&opcao_cliente);

    switch(opcao_cliente)
    {
        case 1: cadastro_cliente();
        break;

        case 2: cadastro_cliente_atualizar();
        break;

        case 3: listar_cliente_idade();
        break;

        case 4: listar_cliente_pontos();
        break;

        case 9: printf("\nVoltando\n");
        break;

        default: printf("opcao invalida\n");
        break;
    }
}

//funcao para cadastro de cliente
void cadastro_cliente()
{
    char CPF[13];
    char Nome[50];
    int Dia,Mes,Ano,Idade;
    char Endereco[50];
    char Cidade[50];
    char Estado[2];
    int Pontos = 0;

    //pega as informacoes do usuario, guardando nas variaveis locais, para depois serem escritas no arquivo
    printf("Informe o CPF:\n");
    scanf(" %[^\n]s",CPF);

    //antes de escrever, olhar se o cpf ja não existe

    printf("Informe o Nome:\n");
    scanf(" %[^\n]s",Nome);

    printf("Informe o DD MM AAAA de nascimento:\n");
    scanf(" %d %d %d",&Dia,&Mes,&Ano);

    printf("Informe a Idade:\n");
    scanf(" %d",&Idade);

    printf("Informe o Endereço:\n");
    scanf(" %[^\n]s",Endereco);

    printf("Informe a Cidade:\n");
    scanf(" %[^\n]s",Cidade);

    printf("Informe o Estado(sigla):\n");
    scanf(" %[^\n]s",Estado);

}

//funcao para atualizar o cadastro de um cliente ja existente
void cadastro_cliente_atualizar()
{
  char CPF[13];

  //procurar para ver se o cliente ja esta cadastrado antes de atualizar
  printf("Digite o CPF do cliente que deseja atualizar:\n");
  scanf(" %[^\n]s",CPF);



}


//funcao para listar cliente entre idade==18 e idade==25
void listar_cliente_idade()
{
  int quantidade = 0;

  //for loop passando por todos os clientes cadastrados, e sempre q Idade >=18 e <=25
  //vai quantidade++


  //mostra na tela quantos
  printf("Temos um total de %d clientes cadastrados entre 18 e 25 anos.\n",quantidade);


}

//funcao para listar cliente com pontos > 1000
void listar_cliente_pontos()
{
  int quantidade = 0;

  //for loop passando por todos os clientes cadastrados, e sempre q pontos > 1000
  //vai quantidade++


  //mostra na tela quantos
  printf("Temos um total de %d clientes com mais de 1000 pontos.\n",quantidade);

}
