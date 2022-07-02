#include "menu_header.h"
#include <stdio.h>

void vendas()
{
    int opcao_venda;


    printf("1. Nova Venda\n2. Listar Compras do Cliente\n9. Voltar\n");
    scanf(" %d",&opcao_venda);

    switch(opcao_venda)
    {
        case 1: nova_venda();
        break;

        case 2: listar_compras_cliente();
        break;

        case 9: printf("\nVoltando\n");
        break;

        default: printf("opcao invalida\n");
        break;
    }
}

//funcao para efetuar uma nova venda
void nova_venda()
{
    char CPF_CLIENTE[13];

    printf("CPF DO CLIENTE: ");
    scanf(" %[^\n]s",CPF_CLIENTE);


}

//funcao para listar as compras feitas por um cliente
void listar_compras_cliente()
{

}
