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
    int index_cliente = (tem_cpf(CPF));

    if(index_cliente < 0)
    {//Não existe, pede pra cadastrar
        printf("\t\tCPF nao cadastrado, prosseguindo para processo de cadastro\n");
        cadastro_cliente();
        //apos cadastro, procura novamente o index de onde esta o cpf no arquivo
        index_cliente = (tem_cpf(CPF));
    }

     //prossegue com a venda, sabendo que o cliente esta cadastrado, e onde.

     bool ainda = true;

     while(ainda == true)
     {
         //variaveis relacionadas aos produtos
         int ID_do_produto;
         TProduto prod;
         FILE *f_prod = fopen("./Arquivos/produtos.dat","rb+");
         bool achou = false;
         int index_produto = 0;
         bool existe;

         printf("\t\tDigite o ID do produto: ");
         scanf(" %d", &ID_do_produto);

         //achar o index de onde esta o produto
         while(achou == false)
         {
             fread(&prod,sizeof(TProduto),1,f_prod);

             if(prod.ID_Produto == ID_do_produto)
             {
                 achou = true;
                 existe = true;
             }
             else
             {
                 index_produto++;
             }

             if(feof(f_prod))
             {
                 existe = false;
                 break;
             }
         }
         //nao achou o produto procurando por id, possivelmente id foi digitado
         //errado ou algo assim
         if(existe == false)
         {
             printf("\t\tNao foi possivel localizar o produto utilizando o ID informado\n");

         }

         else
         {

             fseek(f_prod,index_produto * sizeof(TProduto),SEEK_SET);
             fread(&prod,sizeof(TProduto),1,f_prod);

             printf("\t\tNome: %s\t\tID: %d\n",prod.Nome,prod.ID_Produto);
             printf("\t\tPreco R$:%.2f\n",prod.Preco);
             printf("\t\tEstoque: %d\n",prod.Estoque);

             //caso esteja fora de estoque, a compra do produto atual é anulada,
             //e pulamos para o fim do loop onde pergunta se quer continuar
             if(prod.Estoque <= 0)
             {
                 printf("\t\tPRODUTO FORA DE ESTOQUE\n");
                 printf("\t\tCOMPRA ANULADA\n");
             }
             else
             {
                 //Estoque > 0 então continuamos com a venda


             }
         }

            //sair ou continuar no loop de listagem de produtos
         int sim_nao;
         printf("\t\tDeseja continuar a venda?\n");
         printf("\t\t1. Sim\n\t\t2. Nao (voltar)\n\t\t");
         scanf(" %d",&sim_nao);

         if(sim_nao == 2)
         {
             ainda = false;
         }

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
