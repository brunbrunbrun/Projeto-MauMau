#include "menu_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


//----------------------------------------------------------------------------------
//---switch case para o menu, chamando a função apropriada para a opção no menu-----
//----------------------------------------------------------------------------------
void clientes()
{
    int opcao_cliente;

    printf("\t--------------------------------------\n");
    printf("\t1. Cadastrar novo Cliente\n\t2. Atualizar cadastro de Cliente\n");
    printf("\t3. Listar Quantidade de Clientes entre 18 e 25 anos\n");
    printf("\t4. Listar Clientes com mais de [1000] pontos\n\t9. Voltar\n");
    printf("\t--------------------------------------\n\t");
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



//-------------------------------------------------------------
//---------------funcao para cadastro de cliente---------------
//-------------------------------------------------------------
void cadastro_cliente()
{
    //adiciona na struct os dados do cliente, e depois anexa
    //essa struct no arquivo binario

    FILE *f = fopen("./Arquivos/cliente.dat","ab");
    TCliente cliente;

    printf("\t\t------------------------------------------------------\n");
    printf("\t\tInforme os seguintes dados para cadastro de um cliente\n");

    printf("\t\tno formato 123456789-01\n");
    printf("\t\tCPF do cliente: ");
    scanf(" %[^\n]s",cliente.CPF);

    printf("\t\tNome do cliente: ");
    scanf(" %[^\n]s",cliente.Nome);

    printf("\t\tno formato dd mm aaaa\n");
    printf("\t\tData de nascimento do cliente: ");
    scanf(" %d %d %d",&cliente.Nascimento.Dia,&cliente.Nascimento.Mes,&cliente.Nascimento.Ano);

    printf("\t\tIdade do cliente: ");
    scanf(" %d",&cliente.Idade);

    printf("\t\tEndereco do cliente: ");
    scanf(" %[^\n]s",cliente.Endereco);

    printf("\t\tCidade do cliente: ");
    scanf(" %[^\n]s",cliente.Cidade);

    printf("\t\tSigla do estado do cliente: ");
    scanf(" %[^\n]s",cliente.Estado);

    cliente.Pontos = 0;

    printf("\t\t------------------------------------------------------\n");

    fwrite(&cliente,sizeof(TCliente),1,f);
    fclose(f);
}



//-----------------------------------------------------------------------------
//---------funcao para atualizar o cadastro de um cliente ja existente---------
//-----------------------------------------------------------------------------
void cadastro_cliente_atualizar()
{
    int index = 0;
    char CPF[13];
    bool achou = false;
    FILE *f = fopen("./Arquivos/cliente.dat","rb+");

    TCliente cliente;

    printf("\t\t-----------------------------------------------------------\n");
    printf("\t\tno formato 123456789-01\n");
    printf("\t\tDigite o CPF do cliente que deseja atualizar: ");
    scanf(" %[^\n]s",CPF);

    //procura por todos os clientes cadastrados até achar um que tenha o mesmo
    //CPF que o escolhido, ao achar, para o loop e guarda em index onde no bloco
    //estaria esse cliente
    while(achou == false)
    {
        fread(&cliente,sizeof(TCliente),1,f);

        int clientecerto = strcmp(cliente.CPF,CPF);
        if(clientecerto == 0)
        {
            achou = true;
        }

        else
        {
            index++;
        }
    }

    //vai até o index escolhido, e mostra para o usuario o cliente escolhido
    //para atualizar
    fseek(f,index * sizeof(TCliente),SEEK_SET);
    fread(&cliente,sizeof(TCliente),1,f);

    printf("\t\tCliente Selecionado:\n");
    printf("\t\tCPF: %s\tNome: %s\n",cliente.CPF,cliente.Nome);
    printf("\t\tNascimento: %d/%d/%d\tIdade: %d\n",cliente.Nascimento.Dia,cliente.Nascimento.Mes,cliente.Nascimento.Ano,cliente.Idade);
    printf("\t\tEndereco: %s\n\t\tCidade: %s\tEstado: %s\n",cliente.Endereco,cliente.Cidade,cliente.Estado);
    printf("\t\tPontos: %d\n",cliente.Pontos);
    printf("\t\t---------------\n");
    printf("\t\tInsira os novos dados:\n");

    //novos dados para serem atualizados
    printf("\t\tno formato 123456789-01\n");
    printf("\t\tCPF do cliente: ");
    scanf(" %[^\n]s",cliente.CPF);

    printf("\t\tNome do cliente: ");
    scanf(" %[^\n]s",cliente.Nome);

    printf("\t\tno formato dd mm aaaa\n");
    printf("\t\tData de nascimento do cliente: ");
    scanf(" %d %d %d",&cliente.Nascimento.Dia,&cliente.Nascimento.Mes,&cliente.Nascimento.Ano);

    printf("\t\tIdade do cliente: ");
    scanf(" %d",&cliente.Idade);

    printf("\t\tEndereco do cliente: ");
    scanf(" %[^\n]s",cliente.Endereco);

    printf("\t\tCidade do cliente: ");
    scanf(" %[^\n]s",cliente.Cidade);

    printf("\t\tSigla do estado do cliente: ");
    scanf(" %[^\n]s",cliente.Estado);

    printf("\t\tPontos do cliente: ");
    scanf(" %d",&cliente.Pontos);

    //posiciona no bloco do cliente escolhido
    fseek(f,index * sizeof(TCliente),SEEK_SET);
    fwrite(&cliente,sizeof(TCliente),1,f);

    fclose(f);
}



//------------------------------------------------------------------------------
//------------funcao para listar cliente entre idade==18 e idade==25------------
//------------------------------------------------------------------------------
void listar_cliente_idade()
{

}



//--------------------------------------------------------------------------
//---------------funcao para listar cliente com pontos > 1000---------------
//--------------------------------------------------------------------------
void listar_cliente_pontos()
{

}
