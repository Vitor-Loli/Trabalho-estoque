

#ifndef CLIENTES_H
#define CLIENTES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insere_cliente();
int buscar_cliente(char nome[50], char cpf[12] , int opc);
void listar_clientes();
void excluir_cliente();
void atualizar_cliente();

#endif //CLIENTES_H
