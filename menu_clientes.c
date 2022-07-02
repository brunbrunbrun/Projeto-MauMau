#include "menu_header.h"
#include <stdio.h>

void clientes()
{
    int opcao_cliente;

    printf("1. Cadastrar novo Cliente\n2. Atualizar cadastro de Cliente\n");
    printf("3. Listar Quantidade de Clientes entre 18 e 25 anos\n");
    printf("4. Listar Clientes com mais de [1000] pontos\n9. Voltar\n");
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
    TClientes Cliente;

    //pega as informacoes do usuario, guardando nas variaveis locais,
    //para depois serem escritas no arquivo
    printf("Informe o CPF:\n");
    scanf(" %[^\n]s",Cliente.CPF);

    //antes de escrever, olhar se o cpf ja não existe

    printf("Informe o Nome:\n");
    scanf(" %[^\n]s",Cliente.Nome);

    printf("Informe o DD MM AAAA de nascimento:\n");
    scanf(" %d %d %d",&Cliente.Nascimento.Dia,&Cliente.Nascimento.Mes,&Cliente.Nascimento.Ano);

    printf("Informe a Idade:\n");
    scanf(" %d",&Cliente.Idade);

    printf("Informe o Endereco:\n");
    scanf(" %[^\n]s",Cliente.Endereco);

    printf("Informe a Cidade:\n");
    scanf(" %[^\n]s",Cliente.Cidade);

    printf("Informe o Estado(sigla):\n");
    scanf(" %[^\n]s",Cliente.Estado);

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
  int quant = 0;

  //for loop passando por todos os clientes cadastrados,
  // e sempre q Idade >=18 e <=25
  //vai quantidade++


  //mostra na tela quantos
  printf("Temos um total de %d clientes cadastrados entre 18 e 25 anos.\n",quant);


}

//funcao para listar cliente com pontos > 1000
void listar_cliente_pontos()
{
  int quant = 0;

  //for loop passando por todos os clientes cadastrados, e sempre q pontos > 1000
  //vai quantidade++


  //mostra na tela quantos
  printf("Temos um total de %d clientes com mais de 1000 pontos.\n",quant);

}
