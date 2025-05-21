#include "Clientes.h"


typedef struct cliente {
    int id;
    char nome[50];
    char cpf[12];
} cliente;
struct cliente Clientes[10];

int qtd_cientes_cadastrados = 0;

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
    qtd_cientes_cadastrados++;

    printf("Deseja inserir outro cliente?\n");
    printf("1. Sim\n");
    printf("2. Não\n");
    scanf("%d", &opc);

    if (opc == 1) {
        insere_cliente();
    }
}

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


void listar_clientes(){

    if (qtd_cientes_cadastrados == 0) {
        printf("Não existem clientes cadastrados! Cadastre um primeiro!\n");
        return;
    }

    for(int i = 0; i < 10; i++){
        if(strlen(Clientes[i].nome) > 0 && strlen(Clientes[i].cpf) > 0){
            printf("%s - %s\n", Clientes[i].nome, Clientes[i].cpf);
        }
    }
}

void excluir_cliente(){

    if (qtd_cientes_cadastrados == 0) {
        printf("Não existem clientes cadastrados! Cadastre um primeiro!\n");
        return;
    }

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
        printf("Cliente excluído com sucesso!\n");
    }

    qtd_cientes_cadastrados--;

    printf("Deseja excluir outro cliente?\n");
    printf("1. Sim\n");
    printf("2. Não\n");
    scanf("%d", &opc);

    if (opc == 1) {
        excluir_cliente();
    }

}

void atualizar_cliente() {

    if (qtd_cientes_cadastrados == 0) {
        printf("Não existem clientes cadastrados! Cadastre um primeiro!\n");
        return;
    }

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
