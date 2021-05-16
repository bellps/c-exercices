#include <stdio.h>
#include <stdlib.h>
#include "contato.h"

struct contact{
    char name[51];
    char email[61];
    char phone[22];
};

void new_contact();
void pause();

List * list;

int main(){
    list = create_contact_list();
    int op;

    do {
        system("clear");
        printf("\n--- Cadastro de contatos ---\n");
        printf("Opções: \n");
        printf("1- Cadastrar novo contato\n");
        printf("2- Imprimir lista de contatos\n");
        printf("3- Sair\n");
        printf("Escolha sua opção: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                new_contact();
                break;
            case 2:
                system("clear");
                print_list(list);
                pause();
                break;
            case 3:
                printf("\nSaindo... \n");
                break;
            default:
                printf("Opção invalida.\n");
                pause();
                break;
        }

    } while(op != 3);

    return 0;
}

void new_contact(){
    printf("\n--- Novo contato ---\n");
    Contact * c = (Contact *)malloc(sizeof(struct contact));
    printf("Nome: ");
    setbuf(stdin, NULL);
    fgets(c->name, 51, stdin);
    printf("Telefone: ");
    setbuf(stdin, NULL);
    fgets(c->phone, 22, stdin);
    printf("Email: ");
    setbuf(stdin, NULL);
    fgets(c->email, 61, stdin);
    list = insert_contact(c, list);
    printf("\nNovo contato cadastrado.");
    pause();
}

void pause() {
    printf("\nPressione ENTER para continuar...");
    setbuf(stdin, NULL);
    getchar();
}
