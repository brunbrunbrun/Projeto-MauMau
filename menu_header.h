#ifndef MENU_HEADER_H_
#define MENU_HEADER_H_

//funções dos menus
void produtos();
void vendas();
void clientes();

//funções em menu_clientes.c
void cadastro_cliente();
void cadastro_cliente_atualizar();
void listar_cliente_idade();
void listar_cliente_pontos();

//funções em menu_produtos.c
void cadastro_produto();
void cadastro_produto_atualizar();
void listar_estoque_setor();
void listar_estoque_baixo();

//funções em menu_vendas.c
void nova_venda();
void listar_compras_cliente();

//definições das estruturas para os arquivos
typedef struct TData
{
    int Dia;
    int Mes;
    int Ano;
} TData;


typedef struct TProduto
{
    int ID_Produto;
    char Setor[20];
    char Nome[50];
    float Preco;
    TData Validade;
    int Estoque;
} Tproduto;


typedef struct TClientes
{
    char CPF[13];
    char Nome[50];
    TData Nascimento;
    int Idade;
    char Endereco[50];
    char Cidade[50];
    char Estado[2];
    int Pontos;
} TClientes;


typedef struct TVendas
{
    int ID_Venda;
    char CPF[13];
    TData Data_Compra;
    float Valor_Total;
    int Quantidade_Produtos;
} TVendas;


typedef struct TItensCompra
{
    int ID_Venda;
    char CPF[13];
    int ID_Produto;
    int Quantidade;
    float Preco_Unitario_Produto;
    float Preco_Total_Produto;
} TItensCompra;


#endif
