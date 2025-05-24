#include "Vendas.h"
#include "../Cliente/Clientes.h"
#include "../Produto/Produtos.h"

typedef struct produto_venda {
    int id_produto;
    int quantidade;
} produto_venda;
struct produto_venda Produto_venda;

typedef struct venda {
    int id;
    int id_cliente;
    produto_venda Produtos[10];
    float total;
} venda;
struct venda Vendas[100];

int id_venda = 0;

void efetuar_venda() {
    if (qtd_cientes_cadastrados == 0 ) {
        printf("Não existem clientes cadastrados! Cadastre um primeiro!\n");
        return;
    }
    if (qtd_produtos_cadastrados == 0) {
        printf("Não existem produtos cadastrados! Cadastre um primeiro!\n");
        return;
    }



    
};