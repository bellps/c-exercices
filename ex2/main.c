#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "impressora.h"

struct impressoraDoc {
    int numReg;
    char nomeImpressora[51];
};

void nova_impressao(int * reg);

void pause();

Fila * fila;

int main(){
    fila = criar_fila();
    // Achei interessante manter o numreg como um contador interno, pro usuário não precisar ficar digitando
    int reg = 1;
    int op;
    do {
        system("clear");
        printf("\n--- Fila de impressão de documentos ---\n");
        printf("Opcoes: \n");
        printf("1- Adicionar nova impressão à fila\n");
        printf("2- Mostrar fila\n");
        printf("3- Remover item da fila\n");
        printf("4- Sair\n");
        printf("Escolha sua opção: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                nova_impressao(&reg);
                break;
            case 2:
                system("clear");
                imprimir(fila);
                pause();
                break;
            case 3:
                remover(fila);
                pause();
            case 4:
                printf("\nSaindo... \n");
                break;
            default:
                printf("Opcao invalida\n");
                pause();
                break;
        }

    } while(op != 4);
    return 0;
}

void nova_impressao(int * reg) {
    printf("\n--- Nova impressão ---\n");
    ImpressoraDoc * doc = (ImpressoraDoc *)malloc(sizeof(struct impressoraDoc));
    printf("Nome da impressora: ");
    setbuf(stdin, NULL);
    fgets(doc->nomeImpressora, 51, stdin);
    doc->numReg = *reg;
    *reg = *reg + 1;
    inserir(fila, doc);
    printf("\nNova impressão adicionada a fila.");
    pause();
}

void pause() {
    printf("\nPressione ENTER para continuar...");
    setbuf(stdin, NULL);
    getchar();
}
