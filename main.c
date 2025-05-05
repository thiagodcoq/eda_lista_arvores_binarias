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
    struct no* esquerda;
    struct no* direita;
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

/*
2) Escrever os algoritmos para percorrer uma árvore binária em pré-ordem, pós-ordem e
ordem simétrica
*/

void print_pre_order(No*raiz){
    if(raiz!=NULL){
        printf("Valor = %d\n",raiz->valor);
        print_pre_order(raiz->esquerda);
        print_pre_order(raiz->direita);
    }
}

void print_order(No*raiz){
    if(raiz!=NULL){
        print_order(raiz->esquerda);
        printf("Valor = %d\n",raiz->valor);
        print_order(raiz->direita);
    }
}

void print_post_order(No*raiz){
    if(raiz!=NULL){

        print_post_order(raiz->esquerda);
        print_post_order(raiz->direita);
        printf("Valor = %d\n",raiz->valor);
    }
}

/*
Escrever algoritmo para verificar se existe nó com uma dada chave na árvore (busca),
retornar o ponteiro para o nó que contenha a chave dada. 
*/

No* busca(No*raiz,int n){
    if(raiz!=NULL){
        if(raiz->valor==n){
            return raiz;
        }
        else{
            if (n<raiz->valor){
                return busca(raiz->esquerda,n);
            }
            else{
                return busca(raiz->direita,n);
            }
        }
    }
}


int main(void){
    No* arvore=NULL;
    arvore = insereArv(arvore,40);
    arvore = insereArv(arvore,50);
    arvore = insereArv(arvore,120);
    arvore = insereArv(arvore,100);
    No* buscado=NULL;
    buscado=busca(arvore,120);
    //print_order(buscado);
    //print_order(arvore);
    return 0;
}