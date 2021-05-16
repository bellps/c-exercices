#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "contato.h"

struct contact{
    char name[51];
    char email[61];
    char phone[22];
};

struct list{
    Contact * person;
    List * next;
};

List * create_contact_list(){
    return NULL;
}

List * insert_contact(Contact * c, List * l){
    List * no = (List *)malloc(sizeof(List));
    no->person = (Contact *)malloc(sizeof(Contact));
    strcpy(no->person->name, c->name);
    strcpy(no->person->phone, c->phone);
    strcpy(no->person->email, c->email);
    no->next = l;
    return no;
}

void print_list(List * l){
    List * p = l;
    int counter = 1;

    if(p == NULL){
        printf("Lista vazia :(");
        return;
    }

    while(p!=NULL){
        printf("\n------ Contato nº %d: ------\n", counter);
        printf("Nome: %s", p->person->name);
        printf("Email: %s", p->person->email);
        printf("Telefone: %s", p->person->phone);
        printf("------------------------------\n");
        counter++;
        p = p->next;
    }

}
