#include "menu_header.h"
#include <stdio.h>

char CPF_CLIENTE[13];

void Nova_Venda();
void Listar_Cliente();

void vendas()
{
    int opcao_venda;
    
    
    printf("1. Nova Venda\n2. Listar Venda do Cliente\n9. Voltar\n");
    scanf(" %d",&opcao_venda);
    
    switch(opcao_venda)
    {
        case 1: Nova_Venda();
        break;
        
        case 2: Listar_Cliente();
        break;
        
        case 9: printf("Voltando\n");
        break;

        default: printf("opcao invalida\n");
        break;
    }
}

void Nova_Venda()
{
    printf("CPF DO CLIENTE: ");
    scanf(" %[^\n]s",CPF_CLIENTE);
    

}

void Listar_Cliente()
{
    printf("%s",CPF_CLIENTE);
}