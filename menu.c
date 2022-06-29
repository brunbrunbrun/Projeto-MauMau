#include <stdio.h>
#include <stdbool.h>


int main() 
{
  bool SAIR = false;
  
  //Recursão do menu principal até que o usuario escolha a opção de saida.
  while(SAIR==false)
  {
    int opcao = 0;
    printf("----------\n");
    printf("1. Vendas\n2. Clientes\n3. Produtos\n9. Sair\n");
    printf("----------\n");
    scanf(" %d", &opcao);
  }
  return 0;
}
