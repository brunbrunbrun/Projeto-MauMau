#include "menu_header.h"
#include <stdio.h>

void produtos()
{
    int opcao_produtos;

    printf("1. Cadastrar novo Produto\n2. Atualizar informacoes de um Produto\n3. Estoque por setor\n4. Produtos com estoque baixo(<5)\n9. Voltar\n");
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
