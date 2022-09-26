#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LSEG3.h"


//Lista de Funções
void insereInicio(Node **lista, Dados info){
    """Insere um inteiro no inicio da lista, alocar novo elemento Node""";
    Node *novo = (Node *)malloc (sizeof(Node));
    if(novo==NULL){
        printf("\nFalha de alocação de Memoria!");
        exit(0);
    }
    novo->info = info;
    novo->prox = *lista;  
    *lista = novo;
    mostraLista(lista);  
   // return novo;
}

void insereFim(Node **lista, Dados info){
     """Insere um inteiro no Fim da lista, alocar novo elemento Node""";
    
}

void insereFim2(Node **lista, Node *novo){
     """Insere um inteiro no Fim da lista, Sem alocar um novo elemento Node""";
    
}

void inserePosicao(Node **lista, Dados info, int pos){
    """Insere um novo elemento na posição pos""";
}

Node* removeInicio(Node **lista){
    Node *removido = *lista;
    if(removido==NULL){
        //lista vazia
    }else if (removido->prox==NULL){
        *lista = NULL;
    }else{
        *lista = removido->prox;
        removido->prox=NULL;
    }
    return removido;    
}

Node* removeFim(Node **lista){
    
    
}

Node* removePosicao(Node **lista, int pos){
    
}

void mostraLista(Node **lista){
    Node *aux = *lista;
    int c=1;
    if(aux == NULL){
        printf("\n >> Lista Vazia! <<\n");
    }else{
         printf("\nLista Atualizada: \n>> ");
        do{
            mostraDados(aux->info,c++);
            aux=aux->prox;
        }while(aux != NULL);
         printf(" << \n");
    }
}

void mostraDados(Dados info, int i){
    printf(" %d ",info.valor);
}

Dados criaNoDados(){
    Dados novo;
    printf("\nInforme o Valor: ");
    scanf("%d",&novo.valor);
    return novo;
}

Dados retornaDados(Node *lista, int pos){
    
}

int localizaElemento(Node *lista, int num){
   
}

Node* criaSubLista(Node **lista, int inicio, int fim){
    Node *aux, *sublista = NULL;
    int c = inicio;
    while(c<fim-1){
        aux = removePosicao(lista, inicio);
        insereFim2(sublista, aux);
        c++;
    }
return sublista;



    /* Node *aux, *sublista = NULL;
    aux = *lista;
    //for()
    int c=0;
    while(aux!=NULL && c<inicio-1){
        aux = aux->prox;
        c++;        
    }
    sublista = aux->prox;
    Node *aux2 = sublista;
    while(aux2!=NULL && c<fim-1){
        aux2 = aux2->prox;
        c++;
    }
    aux->prox = aux2->prox;
    aux2->prox= NULL;
    return sublista; */

}

Node* criaNovaListaInvertida(Node **lista){
    
}

