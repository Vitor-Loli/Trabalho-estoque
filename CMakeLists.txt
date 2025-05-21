cmake_minimum_required(VERSION 3.31)
project(Trabalho_estoque C)

set(CMAKE_C_STANDARD 11)

add_executable(Trabalho_estoque main.c Cliente/Clientes.h Cliente/Clientes.c Produto/Produtos.c Produto/Produtos.h)
