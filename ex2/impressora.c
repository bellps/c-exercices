#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "impressora.h"

struct impressoraDoc {
    int numReg;
    char nomeImpressora[51];
};

struct lista {
    ImpressoraDoc * doc;
    Lista * prox;
};

struct fila {
    Lista * ini;
    Lista * fim;
};

Fila * criar_fila() {
    Fila * f = (Fila *)malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

void inserir(Fila * f, ImpressoraDoc * doc) {
    Lista * no = (Lista *)malloc(sizeof(Lista));
    no->doc = doc;
    no->prox = NULL;

    if(f->fim != NULL) {
        f->fim->prox = no;
    } else {
        f->ini = no;
    }

    f->fim = no;
}

int vazia(Fila * f) {
    return (f->fim == NULL);
}

void remover(Fila * f) {
    Lista * temp;

    if(vazia(f)) {
        printf("Fila vazia");
        return;
    }

    temp = f->ini;
    f->ini = temp->prox;

    if(f->ini == NULL) {
        f->fim = NULL;
    }

    free(temp);
    printf("Elemento removido!\n");
}

void imprimir(Fila * f) {
    Lista * p = f->ini;

    if(vazia(f)){
        printf("Fila vazia");
        return;
    }

    printf("NumReg \t Nome da Impressora\n");
    while(p != NULL) {
        printf("%d \t %s", p->doc->numReg, p->doc->nomeImpressora);
        p = p->prox;
    }
}
