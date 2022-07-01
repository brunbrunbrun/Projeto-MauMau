
Sistema_Mercado: menu_principal.o menu_clientes.o menu_produtos.o menu_vendas.o
	gcc menu_principal.o menu_clientes.o menu_produtos.o menu_vendas.o -o Sistema_Mercado

menu_principal.o: menu_principal.c menu_header.h
	gcc menu_principal.c -c

menu_clientes.o: menu_clientes.c
	gcc menu_clientes.c -c

menu_produtos.o: menu_produtos.c
	gcc menu_produtos.c -c

menu_vendas.o: menu_vendas.c
	gcc menu_vendas.c -c

clean:
	rm *.o
