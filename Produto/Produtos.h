

#ifndef PRODUTOS_H
#define PRODUTOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int qtd_produtos_cadastrados = 0;

typedef struct produto {
    int id;
    char descricao[50];
    double preco;
    double quantidade;
} produto;
struct produto Produtos[10];

void insere_produto();
int buscar_produti(int id);
void listar_produtos();
void excluir_produto();
void atualizar_produto();

#endif //PRODUTOS_H
