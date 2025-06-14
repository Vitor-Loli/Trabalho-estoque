#include "Clientes.h"


cliente Clientes[10];
int qtd_cientes_cadastrados = 0;

int id_cliente = 0;

void insere_cliente(){
    int opc;
    for(int i = 0; i < 10; i++){
        if(strlen(Clientes[i].nome) == 0 && strlen(Clientes[i].cpf) == 0){
            Clientes[i].id = id_cliente + 1;
            printf("Informe o nome do cliente: \n");
            scanf("%s", Clientes[i].nome);
            printf("Informe o cpf do cliente: EX: 12345678911\n");
            scanf("%s", Clientes[i].cpf);
            break;
        }
    }
    qtd_cientes_cadastrados++;
    id_cliente++;

    printf("Deseja inserir outro cliente?\n");
    printf("1. Sim\n");
    printf("2. Não\n");
    scanf("%d", &opc);

    if (opc == 1) {
        insere_cliente();
    }
}

int buscar_cliente(int id) {
    int i = 0;

        while (Clientes[i].id != id ) {
            i++;
            if (i > 9) {
                break;
            }
        }
    return i;
}

char get_nome(int id) {
    for (int i = 0; i < qtd_cientes_cadastrados; i++) {
        if (Clientes[i].id == id) {
            return Clientes[i].nome;
        }
    }
}

char get_cpf(int id) {
    for (int i = 0; i < qtd_cientes_cadastrados; i++) {
        if (Clientes[i].id == id) {
            return Clientes[i].cpf;
        }
    }
}


void listar_clientes(){

    if (qtd_cientes_cadastrados == 0) {
        printf("Não existem clientes cadastrados! Cadastre um primeiro!\n");
        return;
    }

    for(int i = 0; i < 10; i++){
        if(strlen(Clientes[i].nome) > 0 && strlen(Clientes[i].cpf) > 0){
            printf("%d - %s - %s\n", Clientes[i].id, Clientes[i].nome, Clientes[i].cpf);
        }
    }
}

void excluir_cliente(){

    if (qtd_cientes_cadastrados == 0) {
        printf("Não existem clientes cadastrados! Cadastre um primeiro!\n");
        return;
    }

    int i = 0;
    int opc;
    int id;
    printf("Esses são os clientes cadastrados, qual deseja excluir?\n");
    listar_clientes();
    printf("Informe o ID: \n");
    scanf("%d", &id);

    i = buscar_cliente(id);

    if (i == 10) {
        printf("Cliente não encontrado!\n");
    }else {
        Clientes[i].id = 0;
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

    int i = 0;
    int id;
    printf("Esses são os clientes cadastrados, qual deseja alterar?\n");
    listar_clientes();
    printf("Informe o ID: \n");
    scanf("%d", &id);
    i = buscar_cliente(id);

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
