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
    char data_venda[17];
} venda;
struct venda Vendas[100];

int id_venda = 0;

void get_data(int index) {
    static char buffer[17];
    time_t agora = time(NULL);
    struct tm *info = localtime(&agora);
    strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M", info);
    strcpy(Vendas[index].data_venda, buffer);
}

void efetuar_venda() {
    int id_cliente_venda;
    int id_produto_venda;
    int resposta;
    double qtd_estoque;
    int qtd_produtos_venda;
    double qtd_venda;

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
            Vendas[i].id = id_venda + 1;
            bool flag = true;
            do {
                printf("Informe o id do cliente: \n");
                listar_clientes();
                scanf("%d", &id_cliente_venda);
                resposta = buscar_cliente(id_cliente_venda);

                if (resposta == 10) {
                    printf("Cliente não encontrado! Por favor informe outro:\n");
                }else {
                    Vendas[i].id_cliente = id_cliente_venda;
                    flag = false;
                }

            }while (flag);

            do {
                flag = true;
                printf("Quantos produtos o cliente comprou? No máximo 10:\n");
                scanf("%d", &qtd_produtos_venda);

                if (qtd_produtos_venda > 0 && qtd_produtos_venda <= 10) {
                    flag = false;
                }

            }while (flag);

            printf("Esses são os produtos cadastrados\n");
            listar_produtos();
            int c = 0;

            while (c < qtd_produtos_venda) {
                do {
                    flag = true;
                    printf("Informe o id do %dº produto: \n", c + 1);
                    scanf("%d", &id_produto_venda);
                    resposta = buscar_produto(id_produto_venda);

                    if (resposta == 10) {
                        printf("Produto não encontrado! Por favor informe outro:\n");
                    }else {
                        Vendas[i].Produtos_venda[c].id_produto = id_produto_venda;
                        flag = false;
                    }

                } while (flag);

                do {
                    flag = true;
                    qtd_estoque = get_quantidade(id_produto_venda);
                    printf("Quantidade em estoque: %lf \n", qtd_estoque);
                    printf("Informe a quantidade comprada do produto\n");
                    scanf("%lf", &qtd_venda);

                    if (qtd_venda > qtd_estoque || qtd_venda <= 0) {
                        printf("Não há estoque ou o valor passado é invalido, por favor informe outro!\n");
                    }else {
                        Vendas[i].Produtos_venda[c].quantidade = qtd_venda;
                        remover_estoque(id_produto_venda, qtd_venda);
                        flag = false;
                    }

                }while (flag);

                c++;
            }
            get_data(i);
            break;
        }
    }

    id_venda++;
}

void listar_vendas(){
    for (int i = 0; i < 100; i++) {
        if(Vendas[i].id != 0){
            printf("%d - %d\n", Vendas[i].id, Vendas[i].id_cliente);
            printf("Produtos do cliente:\n");
            for (int c = 0; c < 10; c++) {
                if (Vendas[i].Produtos_venda[c].id_produto != 0) {
                    printf("    %d - %d\n", Vendas[i].Produtos_venda[c].id_produto,Vendas[i].Produtos_venda[c].quantidade);
                }
            }
        }
    }
}

void relatorio(){

    for (int i = 0; i < 100; i++) {
        if(Vendas[i].id != 0){
            printf("Relatório da venda: %d\n", Vendas[i].id);
            printf("Data da venda: %s\n", Vendas[i].data_venda);
            printf("Cliente: %s - %s\n", Clientes[get_nome((Vendas[i].id_cliente))].nome, Clientes[get_cpf(Vendas[i].id_cliente)].cpf );
            printf("Produtos comprados:\n");
            for (int c = 0; c < 10; c++) {
                double total = 0;
                double preco = 0;
                if (Vendas[i].Produtos_venda[c].id_produto != 0) {
                    preco = Vendas[i].Produtos_venda[c].quantidade * get_preco(Vendas[i].Produtos_venda[c].id_produto);
                    total = total + preco;
                    printf("  %s - %d - R$%.2lf - R$%.2lf\n", Produtos[get_descricao(Vendas[i].Produtos_venda[c].id_produto)].descricao , Vendas[i].Produtos_venda[c].quantidade, get_preco(Vendas[i].Produtos_venda[c].id_produto), preco);
                }
            }
            printf("  Total: RS%.2lf\n\n", total);
        }
    }
}