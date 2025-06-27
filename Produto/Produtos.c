#include "Produtos.h"

int qtd_produtos_cadastrados = 0;
produto Produtos[10];

int id_produto = 0;

int buscar_produto(int id) {
    int i = 0;

    while (Produtos[i].id != id) {
        i++;
        if (i > 9) {
            break;
        }
    }

    return i;
}

int get_descricao(int id) {
    for (int i = 0; i < qtd_produtos_cadastrados; i++) {
        if (Produtos[i].id == id) {
            return i;
        }
    }
}

double get_preco(int id) {
    for (int i = 0; i < qtd_produtos_cadastrados; i++) {
        if (Produtos[i].id == id) {
            return Produtos[i].preco;
        }
    }
}

double get_quantidade(int id) {
    for (int i = 0; i < qtd_produtos_cadastrados; i++) {
        if (Produtos[i].id == id) {
            return Produtos[i].quantidade;
        }
    }
}

void remover_estoque(int id, float qtd) {
    for (int i = 0; i < qtd_produtos_cadastrados; i++) {
        if (Produtos[i].id == id) {
            Produtos[i].quantidade = Produtos[i].quantidade - qtd;
        }
    }
}

void insere_produto(){
    int opc;
    for(int i = 0; i < 10; i++){
        if(strlen(Produtos[i].descricao) == 0){
            Produtos[i].id = id_produto + 1;
            printf("Informe a descrição do produto: \n");
            scanf("%s", Produtos[i].descricao);
            printf("Informe o preço unitário do produto: Ex: 12.50\n");
            scanf("%lf", &Produtos[i].preco);
            printf("Informe a quantidade do produto:\n");
            scanf("%lf", &Produtos[i].quantidade);
            break;
        }
    }

    qtd_produtos_cadastrados++;
    id_produto++;

    printf("Deseja inserir outro produto?\n");
    printf("1. Sim\n");
    printf("2. Não\n");
    scanf("%d", &opc);

    if (opc == 1) {
        insere_produto();
    }
}

void listar_produtos(){

    if (qtd_produtos_cadastrados == 0) {
        printf("Não existem produtos cadastrados! Cadastre um primeiro!\n");
        return;
    }

    for(int i = 0; i < 10; i++){
        if(strlen(Produtos[i].descricao) > 0 ){
            printf("%d - %s - R$%.2lf - %.2lf\n", Produtos[i].id, Produtos[i].descricao, Produtos[i].preco, Produtos[i].quantidade);
        }
    }
}

void excluir_produto() {
    if (qtd_produtos_cadastrados == 0) {
        printf("Não existem produtos cadastrados! Cadastre um primeiro!\n");
        return;
    }

    int i = 0;
    int opc;
    int id;
    printf("Esses são os produtos cadastrados, qual deseja excluir?:\n");
    listar_produtos();
    printf("Informe o ID: \n");
    scanf("%d", &id);
    i = buscar_produto(id);

    if (i == 10) {
        printf("Produto não encontrado! Por favor informe outro:\n");
        excluir_produto();
    }else {
        strcpy(Produtos[i].descricao, "");
        Produtos[i].preco = 0;
        Produtos[i].quantidade = 0;
        printf("Produto excluído com sucesso!\n");
        qtd_produtos_cadastrados--;
    }

    printf("Deseja excluir outro cliente?\n");
    printf("1. Sim\n");
    printf("2. Não\n");
    scanf("%d", &opc);

    if (opc == 1) {
        excluir_produto();
    }

}

void atualizar_produto() {

    if (qtd_produtos_cadastrados == 0) {
        printf("Não existem produtos cadastrados! Cadastre um primeiro!\n");
        return;
    }

    int i;
    int id;
    printf("Esses são os produtos cadastrados no sistema, qual deseja alterar?\n");
    listar_produtos();
    printf("Informe o ID: \n");
    scanf("%d", &id);
    i = buscar_produto(id);

    if (i == 10) {
        printf("Produto não encontrado! Por favor informe outro: \n");
        atualizar_produto();
    }else {
        int opc;
        char descricaoAlterada[50];
        double precoAlterado;
        double quantidadeAlterada;

        printf("O que deseja alterar?\n");
        printf("1. Descrição\n");
        printf("2. Preço\n");
        printf("3. Quantidade\n");
        printf("4. Todos os dados\n");
        scanf("%d", &opc);

        if (opc == 1) {
            printf("Informe a nova descrição do produto: \n");
            scanf("%s", &descricaoAlterada);
            strcpy(Produtos[i].descricao, descricaoAlterada);
        } else if (opc == 2) {
            printf("Informe o novo preço do produto: Ex: 12.50\n");
            scanf("%lf", &precoAlterado);
            Produtos[i].preco = precoAlterado;
        } else if (opc == 3) {
            printf("Informe a nova quantidade do produto:\n");
            scanf("%lf", &quantidadeAlterada);
            Produtos[i].quantidade = quantidadeAlterada;
        } else if (opc == 4) {
            printf("Informe a nova descrição do produto: \n");
            scanf("%s", &descricaoAlterada);
            printf("Informe o novo preço do produto: Ex: 12.50\n");
            scanf("%lf", &precoAlterado);
            printf("Informe a nova quantidade do produto:\n");
            scanf("%lf", &quantidadeAlterada);
            strcpy(Produtos[i].descricao, descricaoAlterada);
            Produtos[i].preco = precoAlterado;
            Produtos[i].quantidade = quantidadeAlterada;
        }

        printf("Deseja atualizar outro produto?\n");
        printf("1. Sim\n");
        printf("2. Não\n");
        scanf("%d", &opc);

        if (opc == 1) {
            atualizar_produto();
        }
    }
}