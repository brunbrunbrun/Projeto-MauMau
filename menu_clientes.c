#include "menu_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


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

}



//-----------------------------------------------------------------------------
//---------funcao para atualizar o cadastro de um cliente ja existente---------
//-----------------------------------------------------------------------------
void cadastro_cliente_atualizar()
{

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
