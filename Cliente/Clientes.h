

#ifndef CLIENTES_H
#define CLIENTES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct cliente {
    int id;
    char nome[50];
    char cpf[12];
} cliente;
struct cliente Clientes[10];

int qtd_cientes_cadastrados = 0;

void insere_cliente();
int buscar_cliente(int id);
void listar_clientes();
void excluir_cliente();
void atualizar_cliente();

#endif //CLIENTES_H
