#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LSEG2.h"


//Lista de Funções
Node* insereInicio(Node *lista, Dados info){
    """Insere um inteiro no inicio da lista, alocar novo elemento Node""";
    Node *novo = (Node *)malloc (sizeof(Node));
    if(novo==NULL){
        printf("\nFalha de alocação de Memoria!");
        exit(0);
    }
    novo->info = info;
    novo->prox = lista;  
    mostraLista(novo);  
    return novo;
}

Node* insereFim(Node *lista, Dados info){
     """Insere um inteiro no Fim da lista, alocar novo elemento Node""";
    Node *novo = (Node *)malloc (sizeof(Node));
    if(novo==NULL){
        printf("\nFalha de alocação de Memoria!");
        exit(0);
    }
   novo->info = info;;
    novo->prox = NULL; 
    Node *aux = lista;
    if(aux == NULL){
        lista = insereInicio(lista,info);
    }else{
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    mostraLista(lista);
    return lista;
}

Node * inserePosicao(Node *lista, Dados info, int pos){
    if(lista == NULL || pos == 0)
        lista = insereInicio(lista,info);
    else{
        Node *novo = (Node *)malloc (sizeof(Node));
        novo->info = info;
        if(novo==NULL){
            printf("\nFalha de alocação de Memoria!");
            exit(0);
        }
        Node *aux = lista;
        int c = 0;
        while(c<pos-1 && aux->prox !=NULL){
            c++;
            aux= aux->prox;
        }
        if(aux->prox == NULL)
            lista = insereFim(lista,info);
        else{
           // printf("Aux = %d",aux->num);
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
    mostraLista(lista);
    return lista;
}

Node* removeInicio(Node *lista){
    Node *aux = lista;
    if(aux==NULL){
        printf("\n Lista Vazia!");
        return NULL;
    }
    lista = lista->prox;
    free(aux);
    mostraLista(lista);
    return lista;
}

void mostraLista(Node *lista){
    Node *aux = lista;
    int c=1;
    if(aux == NULL){
        printf("\n >> Lista Vazia! <<\n");
    }else{
         printf("\n >> ");
        do{
            mostraDados(aux->info);
            aux=aux->prox;
        }while(aux != NULL);
         printf(" << \n");
    }
}

void mostraDados(Dados info){
    printf(" %d ",info.valor);
}

Dados criaNoDados(){
    Dados novo;
    printf("\nInforme um valor: ");
    scanf("%d",&novo.valor);
    return novo;
}


