#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exearv.h"

struct family {
    char name[51];
    Family * left;
    Family * right;
};

Family * create_empty() {
    return NULL;
}

Family * create(char * name, Family * left, Family * right) {
    Family * f = (Family *)malloc(sizeof(Family));
    strcpy(f->name, name);
    f->left = left;
    f->right = right;
    return f;
}

int empty(Family * f) {
    return (f == NULL);
}

void print_member(char * name, int spaces) {
    for (int i = 0; i < spaces; i++) {
        printf(" ");
    }
    printf(" %s \n", name);
}

void print_family(Family * f, int spaces) {
    if(empty(f)) {
        print_member(" -*- ", spaces);
        return;
    }

    print_family(f->right, spaces + 6);
    print_member(f->name, spaces);
    print_family(f->left, spaces + 6);
}

Family * free_family(Family * f) {
    if(!empty(f)) {
        free_family(f->right);
        free_family(f->left);
        free(f);
    }
    return NULL;
}

void find(Family * f, char * member, int kin) {
    if(empty(f)) {
        return;
    }

    kin++;
    if(strcmp(f->name, member) == 0) {
        printf("\nGrau de parentesco de %s: %d ", member, kin);
        get_kin(kin);
        return;
    }

    find(f->left, member, kin);
    find(f->right, member, kin);
}

void get_kin(int kin) {
    switch (kin) {
    case 1:
        printf("(geração atual)\n");
        break;
    case 2:
        printf("(pais)\n");
        break;
    case 3:
        printf("(avós)\n");
        break;
    case 4:
        printf("(bisavós)\n");
        break;
    default:
        break;
    }
}