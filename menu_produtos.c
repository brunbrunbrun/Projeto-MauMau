#include "menu_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//switch case para o menu, chamando a função apropriada para a opção no menu
void produtos()
{
    int opcao_produtos;

    printf("\t--------------------------------------\n");
    printf("\t1. Cadastrar novo Produto\n\t2. Atualizar informacoes de um Produto\n");
    printf("\t3. Estoque por setor\n\t4. Produtos com estoque baixo(<5)\n\t9. Voltar\n");
    printf("\t--------------------------------------\n\t");
    scanf(" %d",&opcao_produtos);

    switch(opcao_produtos)
    {
      case 1: cadastro_produto();
      break;

      case 2: cadastro_produto_atualizar();
      break;

      case 3: listar_estoque_setor();
      break;

      case 4: listar_estoque_baixo();
      break;

      case 9: printf("\nVoltando\n");
      break;

      default: printf("opcao invalida\n");
      break;

    }

}

//funcao para cadastrar novo produto
void cadastro_produto()
{
    //adiciona na struct os dados do produto, e depois anexa
    //essa struct no arquivo binario

    FILE *f = fopen("./Arquivos/produtos.dat","ab");
    TProduto prod;

    char setor1[20] = "Higiene e limpeza";
    char setor2[20] = "Bebidas";
    char setor3[20] = "Frios";
    char setor4[20] = "Padaria";
    char setor5[20] = "Acougue";

    printf("\t\t-----------------------------------------------------------\n");
    printf("\t\tInforme os seguintes dados para cadastro de um NOVO produto\n");

    printf("\t\tID do produto: ");
    scanf(" %d",&prod.ID_Produto);

    //apenas prossegue se o setor do produto for valido
    while( ( ((strcmp(prod.Setor,setor1))!=0) && ((strcmp(prod.Setor,setor2))!=0) && ((strcmp(prod.Setor,setor3))!=0) && ((strcmp(prod.Setor,setor4))!=0) && ((strcmp(prod.Setor,setor5))!=0) ) )
    {
    printf("\t\tSetor do produto: ");
    scanf(" %[^\n]s",prod.Setor);
    };

    printf("\t\tNome do produto: ");
    scanf(" %[^\n]s",prod.Nome);

    printf("\t\tPreco do produto: ");
    scanf(" %f",&prod.Preco);

    printf("\t\tValidade do produto em dd mm aaaa: ");
    scanf(" %d %d %d",&prod.Validade.Dia,&prod.Validade.Mes,&prod.Validade.Ano);

    printf("\t\tQuantia em estoque do produto: ");
    scanf(" %d",&prod.Estoque);

    printf("\t\t-----------------------------------------------------------\n");

    fwrite(&prod,sizeof(TProduto),1,f);
    fclose(f);
}

//funcao para atualizar o cadastro de um produto
void cadastro_produto_atualizar()
{

}

//funcao para listar estoque por setor
void listar_estoque_setor()
{

}

//funcao para listar produtos com estoque baixo, ou seja, menor que 5 itens em Estoque
void listar_estoque_baixo()
{

}
