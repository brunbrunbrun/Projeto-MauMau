#include "menu_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


//----------------------------------------------------------------------------------
//---switch case para o menu, chamando a função apropriada para a opção no menu-----
//----------------------------------------------------------------------------------
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

      case 3: listar_produtos_setor();
      break;

      case 4: listar_estoque_baixo();
      break;

      case 9: printf("\nVoltando\n");
      break;

      default: printf("opcao invalida\n");
      break;

    }

}


//----------------------------------------------------------------
//---------------funcao para cadastrar novo produto---------------
//----------------------------------------------------------------
void cadastro_produto()
{
    //adiciona na struct os dados do produto, e depois anexa
    //essa struct no arquivo binario

    FILE *f = fopen("./Arquivos/Produtos.dat","ab");
    TProduto prod;

    char setor1[20] = "Higiene e limpeza";
    char setor2[20] = "Bebidas";
    char setor3[20] = "Frios";
    char setor4[20] = "Padaria";
    char setor5[20] = "Acougue";

    printf("\t\t-----------------------------------------------------------\n");
    printf("\t\tInforme os seguintes dados para cadastro de um produto\n");

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



//----------------------------------------------------------------------------
//---------------funcao para atualizar o cadastro de um produto---------------
//----------------------------------------------------------------------------
void cadastro_produto_atualizar()
{
    int index = 0;
    int id;
    bool achou = false;
    FILE *f = fopen("./Arquivos/Produtos.dat","rb+");

    TProduto prod;

    printf("\t\t-----------------------------------------------------------\n");
    printf("\t\tDigite o ID do produto que quer atualizar: ");
    scanf(" %d",&id);

    //procura por todos os produtos até achar um que tenha o mesmo id que o escolhido
    //ao achar, para o loop, e guarda em index onde no bloco estaria esse produto
    while(achou == false)
    {
        fread(&prod,sizeof(TProduto),1,f);

        if(prod.ID_Produto == id)
        {
            achou = true;
        }

        else
        {
            index++;
        }
    }

    //vai até o index escolhido, e mostra para o usuario o produto escolhido
    fseek(f,index * sizeof(TProduto),SEEK_SET);
    fread(&prod,sizeof(TProduto),1,f);
    printf("\t\tProduto selecionado:\n");
    printf("\t\tID: %d\n\t\tSetor: %s\n\t\tNome: %s\n",prod.ID_Produto,prod.Setor,prod.Nome);
    printf("\t\tPreco: %.2f\n\t\tValidade: %d/%d/%d\n\t\tEstoque: %d\n",prod.Preco,prod.Validade.Dia,prod.Validade.Mes,prod.Validade.Ano,prod.Estoque);
    printf("\t\t-----------\n");
    printf("\t\tInsira os novos dados:\n");

    //inserção de produto para ser colocado no lugar do escolhido para atualizar
    char setor1[20] = "Higiene e limpeza";
    char setor2[20] = "Bebidas";
    char setor3[20] = "Frios";
    char setor4[20] = "Padaria";
    char setor5[20] = "Acougue";

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

    //posiciona no bloco do produto escolhido
    fseek(f,index * sizeof(TProduto),SEEK_SET);
    fwrite(&prod,sizeof(TProduto),1,f);

    fclose(f);
}


//-------------------------------------------------------------------
//---------------funcao para listar produtos por setor---------------
//-------------------------------------------------------------------
void listar_produtos_setor()
{
    //Setores
    char setor1[20] = "Higiene e limpeza";
    char setor2[20] = "Bebidas";
    char setor3[20] = "Frios";
    char setor4[20] = "Padaria";
    char setor5[20] = "Acougue";

    FILE *f = fopen("./Arquivos/Produtos.dat","rb");

    TProduto prod;

    printf("\t\t %s\n",setor1);

    while(fread(&prod,sizeof(TProduto),1,f))
    {
        int setorcerto = strcmp(prod.Setor,setor1);
        if(setorcerto == 0)
        {
            printf("\t\t---------\n");
            printf("\t\tID: %d\tNome: %s\tPreco: %.2f\n",prod.ID_Produto,prod.Nome,prod.Preco);
            printf("\t\tValidade: %d/%d/%d\t\tEstoque: %d\n",prod.Validade.Dia,prod.Validade.Mes,prod.Validade.Ano,prod.Estoque);
            printf("\t\t---------\n");

        }
    }



}


//------------------------------------------------------------------------------
//---------------funcao para listar produtos com estoque baixo <5---------------
//------------------------------------------------------------------------------
void listar_estoque_baixo()
{

}
