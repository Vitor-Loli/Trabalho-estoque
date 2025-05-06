#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char Clientes[10][50];
char produtos[10][50];

void insere_cliente(){
    for(int i = 0; i < 10; i++){
        if(strlen(Clientes[i]) == 0){
            printf("Informe o nome do cliente: \n");
            scanf("%s", Clientes[i]);
            break;
        }
    }
}

void listar_clientes(){
    for(int i = 0; i < 10; i++){
        if(strlen(Clientes[i]) > 0){
            printf("%s\n", Clientes[i]);
        }
    }
}

void excluir_cliente(){
    int i = 0;
    char nome[50];
    printf("Qual cliente deseja excluir?\n");
    scanf("%s", &nome);

    while(strcmp(Clientes[i], nome) != 0){
        i++;
    }

    if(i == 0){
        printf("Cliente não encontrado, por favor informe outro\n");
    }else{
        strcpy(Clientes[i], "");
    }

}


int main()
{
   int opc;

   do{
     printf("\nMENU\n\n");
     printf("1. Inserir Clientes\n");
     printf("2. Listar Clientes\n");
     printf("3. Excluir Cliente\n");
     printf("1. Inserir Cliente\n");
     printf("1. Inserir Cliente\n");
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