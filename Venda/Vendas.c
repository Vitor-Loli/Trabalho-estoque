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
    produto_venda Produtos_venda[10];
    float total;
} venda;
struct venda Vendas[100];

int id_venda = 0;

void efetuar_venda() {
    int id_cliente_venda;
    int qtd_produtos_venda;

    if (qtd_cientes_cadastrados == 0 ) {
        printf("Não existem clientes cadastrados! Cadastre um primeiro!\n");
        return;
    }
    if (qtd_produtos_cadastrados == 0) {
        printf("Não existem produtos cadastrados! Cadastre um primeiro!\n");
        return;
    }

    for(int i = 0; i < 10; i++){
        if(Vendas[i].id == 0){
            Vendas[i].id = i + 1;
            printf("Informe o id do cliente: \n");
            listar_clientes();
            scanf("%d", &Vendas[i].id_cliente);
            printf("Quantos produtos o cliente comprou? No máximo 10:\n");
            scanf("%d", &qtd_produtos_venda);
            printf("Esses são os produtos cadastrados\n");
            listar_produtos();
                int c = 0;
                while (c < qtd_produtos_venda) {
                    printf("Informe o id do %dº produto: \n", c + 1);
                    scanf("%d", &Vendas[i].Produtos_venda[c].id_produto);
                    printf("Informe a quantidade comprada do produto");
                    scanf("%d", &Vendas[i].Produtos_venda[c].quantidade);
                }
            break;
        }
    }
    
};