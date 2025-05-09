#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct cliente {
    char nome[50];
    char cpf[12];
} cliente;
struct cliente Clientes[10];


char Produtos[10][50];

void insere_cliente(){
    int opc;
    for(int i = 0; i < 10; i++){
        if(strlen(Clientes[i].nome) == 0 && strlen(Clientes[i].cpf) == 0){
            printf("Informe o nome do cliente: \n");
            scanf("%s", Clientes[i].nome);
            printf("Informe o cpf do cliente: EX: 12345678911\n");
            scanf("%s", Clientes[i].cpf);
            break;
        }
    }

    printf("Deseja inserir outro cliente?\n");
    printf("1. Sim\n");
    printf("2. Não\n");
    scanf("%d", &opc);

    if (opc == 1) {
        insere_cliente();
    }
}

void listar_clientes(){
    for(int i = 0; i < 10; i++){
        if(strlen(Clientes[i].nome) > 0 && strlen(Clientes[i].cpf) > 0){
            printf("%s - %s\n", Clientes[i].nome, Clientes[i].cpf);
        }
    }
}

void excluir_cliente(){
    char nome[50];
    char cpf[12];
    int i = 0;
    int opc;
    printf("Como deseja buscar o cliente que irá excluir?\n");
    printf("1. Nome\n");
    printf("2. CPF\n");
    scanf("%d", &opc);

    if (opc == 1) {
        printf("Informe o nome do cliente: \n");
        scanf("%s", &nome);
        while (strcmp(Clientes[i].nome, nome) != 0 ) {
            i++;
            if (i > 9) {
                break;
            }
        }
    }else if (opc == 2) {
        printf("Informe o cpf do cliente: EX: 12345678911\n");
        scanf("%s", &cpf);
        while (strcmp(Clientes[i].cpf, cpf) != 0 ) {
            i++;
            if (i > 9) {
                break;
            }
        }
    }

    if (i == 10) {
        printf("Cliente não encontrado!\n");
    }else {
        strcpy(Clientes[i].nome, "");
        strcpy(Clientes[i].cpf, "");
        printf("Cliente excluido com sucesso!\n");
    }

    printf("Deseja excluir outro cliente?\n");
    printf("1. Sim\n");
    printf("2. Não\n");
    scanf("%d", &opc);

    if (opc == 1) {
        excluir_cliente();
    }

}


int main()
{
   int opc;

   do{
     printf("\nMENU\n\n");
     printf("Clientes\n");
     printf("1. Inserir Clientes\n");
     printf("2. Listar Clientes\n");
     printf("3. Excluir Cliente\n");
     printf("Produtos\n");
     printf("4. Inserir Produto\n");
     printf("5. Listar Produto\n");
     printf("6. Excluir Produto\n");
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
        case 8:
            printf("Até logo!");
        break;

        default:
            printf("Valor incorreto! Por favor informe outro");
     }

   }while(opc != 8);
}