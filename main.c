#include <stdio.h>
#include <stdlib.h>

/*
1 - Escrever algoritmo para criar uma árvore binária e inserir nó na árvore (sempre completa
ou cheia).
a. A partir de números gerados aleatoriamente.
b. A partir de um vetor previamente inicializado (neste caso para testes não precisa ser
completa ou cheia).
*/

typedef struct no{
    int valor;
    struct no* esquerda,direita;
}No;

No* criaNo(int n){
    No*novo=(No*)malloc(sizeof(No));
    if (novo==NULL){
        printf("Erro ao alocar memória\n");
        exit(1);
    }
    else{
        novo->valor=n;
        novo->esquerda=NULL;
        novo->direita=NULL;
        return novo;
    }

}

No* insereArv(No*raiz,int n){
    if(raiz==NULL){
        raiz = criaNo(n);
        return raiz;
    }
    else{
        if (n<raiz->valor){
            raiz->esquerda=insereArv(raiz->esquerda,n);
        }
        else if(n>raiz->valor){
            raiz->direita=insereArv(raiz->direita,n);
        }
        else{
            printf("Não foi possivel inserir\n");
        }
        return raiz;
    }
    
}



int main(void){

    return 0;
}