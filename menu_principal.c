#include <stdio.h>
#include <stdbool.h>
#include "menu_header.h"


int main()
{
  bool SAIR = false;

  //Recursão do menu principal até que o usuario escolha a opção de saida.
  while(SAIR==false)
  {
    int opcao = 0;
    printf("----------------\n");
    printf("1. Vendas\n2. Clientes\n3. Produtos\n9. Sair\n");
    printf("----------------\n");
    scanf(" %d", &opcao);

    switch(opcao)
    {
      //acessa o menu de vendas
      case 1 : vendas();
      break;

      //acessa o menu de cliente
      case 2 : clientes();
      break;

      //acessa o menu de produtos
      case 3 : produtos();
      break;

      //fim do programa
      case 9 : printf("Fim do programa\n");
      SAIR = true;
      break;

      //caso o usuario digitar uma opção invalida
      default : printf("Opcao invalida\n");
      break;
    }
  }
  return 0;
}
