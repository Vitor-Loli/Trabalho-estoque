#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct cliente {
    char nome[50];
    char cpf[12];
} cliente;
struct cliente Clientes[10];

typedef struct produto {
    char descricao[50];
    double preco;
    double quantidade;
} produto;
struct produto Produtos[10];

int buscar_cliente(char nome[50], char cpf[12] , int opc) {
    int i = 0;

    if (opc == 1) {
        while (strcmp(Clientes[i].nome, nome) != 0 ) {
            i++;
            if (i > 9) {
                break;
            }
        }
    }else if (opc == 2) {
        while (strcmp(Clientes[i].cpf, cpf) != 0 ) {
            i++;
            if (i > 9) {
                break;
            }
        }
    }

    return i;
}

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
        i = buscar_cliente(nome, cpf, opc);
    }else if (opc == 2) {
        printf("Informe o cpf do cliente: EX: 12345678911\n");
        scanf("%s", &cpf);
        i = buscar_cliente(nome, cpf, opc);
    } else {
        excluir_cliente();
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

void atualizar_cliente() {
    char nome[50];
    char cpf[12];
    int i;
    printf("Esses são os clientes cadastrados no sistema, qual deseja alterar? Informe o nome\n");
    listar_clientes();
    scanf("%s", &nome);
    i = buscar_cliente(nome, cpf, 1);

    if (i == 10) {
        printf("Cliente não encontrado, informe outro");
        atualizar_cliente();
    }else {
        int opc;
        char nomeAlterado[50];
        char cpfAlterado[12];

        printf("O que deseja alterar?\n");
        printf("1. Nome\n");
        printf("2. CPF\n");
        printf("3. Nome e CPF\n");
        scanf("%d", &opc);

        if (opc == 1) {
            printf("Informe o novo nome do cliente: \n");
            scanf("%s", &nomeAlterado);
            strcpy(Clientes[i].nome, nomeAlterado);
        }else if (opc == 2) {
            printf("Informe o novo cpf do cliente: EX: 12345678911\n");
            scanf("%s", &cpfAlterado);
            strcpy(Clientes[i].cpf, cpfAlterado);
        }else if (opc == 3) {
            printf("Informe o novo nome do cliente: \n");
            scanf("%s", &nomeAlterado);
            printf("Informe o novo cpf do cliente: EX: 12345678911\n");
            scanf("%s", &cpfAlterado);
            strcpy(Clientes[i].nome, nomeAlterado);
            strcpy(Clientes[i].cpf, cpfAlterado);
        }

        printf("Deseja atualizar outro cliente?\n");
        printf("1. Sim\n");
        printf("2. Não\n");
        scanf("%d", &opc);

        if (opc == 1) {
            atualizar_cliente();
        }
    }
}

void insere_produto(){
    int opc;
    for(int i = 0; i < 10; i++){
        if(strlen(Produtos[i].descricao) == 0){
            printf("Informe a descrição do produto: \n");
            scanf("%s", Produtos[i].descricao);
            printf("Informe o preço unitário do produto: Ex: 12.50\n");
            scanf("%lf", &Produtos[i].preco);
            printf("Informe a quantidade do produto:\n");
            scanf("%lf", &Produtos[i].quantidade);
            break;
        }
    }

    printf("Deseja inserir outro produto?\n");
    printf("1. Sim\n");
    printf("2. Não\n");
    scanf("%d", &opc);

    if (opc == 1) {
        insere_produto();
    }
}

void listar_produtos(){
    for(int i = 0; i < 10; i++){
        if(strlen(Produtos[i].descricao) > 0 ){
            printf("%s - R$%.2lf - %.2lf\n", Produtos[i].descricao, Produtos[i].preco, Produtos[i].quantidade);
        }
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
     printf("4. Atualizar Cliente\n");
     printf("Produtos\n");
     printf("5. Inserir Produto\n");
     printf("6. Listar Produto\n");
     printf("7. Excluir Produto\n");
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
        case 8:
            printf("Até logo!");
        break;

        default:
            printf("Valor incorreto! Por favor informe outro");
     }

   }while(opc != 8);
}