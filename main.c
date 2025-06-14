#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente/Clientes.h"
#include "Produto/Produtos.h"
#include "Venda/Vendas.h"


int main()
{
   int opc;

   do{
       printf("\nMENU\n\n");
       printf("Clientes\n");
       printf("1. Inserir Clientes\n");
       printf("2. Listar Clientes\n");
       printf("3. Excluir Cliente\n");
       printf("4. Atualizar Cliente\n");
       printf("Produtos\n");
       printf("5. Inserir Produto\n");
       printf("6. Listar Produto\n");
       printf("7. Excluir Produto\n");
       printf("8. Alterar Produto\n");
       printf("Vendas\n");
       printf("9. Efetuar Venda\n");
       scanf("%d", &opc);

     switch(opc){
        case 1:
            insere_cliente();
        break;
        case 2:
            listar_clientes();
        break;
        case 3:
            excluir_cliente();
        break;
         case 4:
             atualizar_cliente();
             break;
         case 5:
             insere_produto();
             break;
         case 6:
             listar_produtos();
             break;
         case 7:
             excluir_produto();
             break;
         case 8:
             atualizar_produto();
             break;
         case 9:
             efetuar_venda();
             break;
        case 10:
            listar_vendas();
            break;
         case 11:
             relatorio();
             break;
         case 12:
             printf("Até logo!");
             break;

        default:
            printf("Valor incorreto! Por favor informe outro");
     }

   }while(opc != 12);
}
