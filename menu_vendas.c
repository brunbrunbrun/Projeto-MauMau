#include "menu_header.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


//----------------------------------------------------------------------------------
//---switch case para o menu, chamando a função apropriada para a opção no menu-----
//----------------------------------------------------------------------------------
void vendas()
{
    int opcao_venda;

    printf("\t--------------------------------------\n");
    printf("\t1. Nova Venda\n\t2. Listar Compras do Cliente\n\t9. Voltar\n");
    printf("\t--------------------------------------\n\t");
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


//------------------------------------------------------------
//-------------funcao para efetuar uma nova venda-------------
//------------------------------------------------------------
void nova_venda()
{
    char CPF[13];





    printf("\t\t-------------------------\n");
    printf("\t\tno formato 123456789-01\n");
    printf("\t\tInforme o CPF do cliente: ");
    scanf(" %[^\n]s",CPF);

    //olha se existe, caso sim, retorna um int igual ou maior que 0
    int index = (tem_cpf(CPF));

    if(index < 0)
    {//Não existe, pede pra cadastrar
        printf("\t\tCPF nao cadastrado, prosseguindo para processo de cadastro\n");
        cadastro_cliente();
        //apos cadastro, procura novamente o index de onde esta o cpf no arquivo
        index = (tem_cpf(CPF));
    }
     //prossegue com a venda, sabendo que o cliente esta cadastrado, e onde.
    else
    {
        FILE *f = fopen("./Arquivos/produtos.dat","ab");
        TProduto prod;

        int quant;

        printf("Informe o ID do produto que deseja comprar: ");
        scanf(" %d", &prod.ID_Produto);

        if(){
            printf("Informe a quantidade do produto: ");
            scanf(" %d", &quant);
        }
        else
        {
            printf("ID inválido, tente novamente");
        }

      fwrite(&prod,sizeof(TProduto),1,f);
      fclose(f);

    }

}



//------------------------------------------------------------
//-----funcao para listar as compras feitas por um cliente----
//------------------------------------------------------------
void listar_compras_cliente()
{
    int opcao_busca;
    char CPF[13];
    char Nome_Completo[50];


    //escolher tipo de busca
    printf("\t\t\tDeseja fazer a busca por:\n");
    printf("\t\t\t1. CPF\n\t\t\t2. Nome Completo\n\t\t\t9. Voltar\n\t\t\t");
    scanf(" %d",&opcao_busca);

    //switch case para a opção escolhida, ambos retorna ao programa o cpf do cliente
    switch(opcao_busca)
    {
        case 1: printf("\t\t\tInsira o CPF: ");
                scanf(" %[^\n]s",CPF);
                if (CPF)
        break;

        case 2: printf("\t\t\tInsira o Nome Completo: ");
                scanf(" %[^\n]s",Nome_Completo);

                //fazer com que ele procure o cpf do cliente
                //fazer uma funcao só pra isso?

        break;

        case 9: printf("\t\t\tVoltando\n");
        break;

        default: printf("\t\t\tOpcao invalida, voltando\n");
        break;
    }

    



}
