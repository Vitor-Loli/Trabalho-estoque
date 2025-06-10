

#ifndef PRODUTOS_H
#define PRODUTOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto {
    int id;
    char descricao[50];
    double preco;
    double quantidade;
} produto;
extern int qtd_produtos_cadastrados;
extern produto Produtos[10];

void insere_produto();
int buscar_produto(int id);
float get_quantidade(int id);
float get_preco(int id);
void remover_estoque(int id, float qtd);
void listar_produtos();
void excluir_produto();
void atualizar_produto();

#endif //PRODUTOS_H
