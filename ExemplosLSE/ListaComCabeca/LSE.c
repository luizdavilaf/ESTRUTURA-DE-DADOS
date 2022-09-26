//biblioteca de funções, implementações
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LSE.h"

LSE* criaListaLSE(){
    """Aloca memória para uma nova lista"""; 
    LSE *nova = (LSE*)malloc(sizeof(LSE));  
    nova->primeiro = NULL;
    nova->n_elementos = 0;
    return nova;
}

Node* criaNoDados(){
    """Aloca memória para um novo Elemento (Node)""";
    Node *novoNode = (Node*)malloc(sizeof(Node));
    printf("\nInforme um valor:");
    scanf("%d",&novoNode->valor);
    novoNode->proximo = NULL;
    return novoNode;
}

Node lerNode(){
}

void insereNoInicio(LSE *ls, Node *novo){
    if(ls->primeiro==NULL){
        novo->proximo = NULL;
    }else{
        novo->proximo = ls->primeiro;
    }
    ls->primeiro = novo;
    ls->n_elementos++;
}

void insereNoFim(LSE *ls, Node *novo){
}

void insereNaPosicao(LSE *ls, Node *novo, int pos){
}

Node* removeNoInicio(LSE *ls){
}

Node* removeNoFim(LSE *ls){
    """Remove e retorna o último elemento da lista""";
}

Node* removeNaPosicao(LSE *ls, int pos){
    """Remove e retorna o elemento da lista na posição indicada""";
}

int retornaQuantidade(LSE *ls){
    """Retorna a quantidade de Elementos da Lista """;
    return ls->n_elementos;
}

void mostraLista(LSE *ls){
    Node *aux = ls->primeiro;
    printf(" << ");
    while(aux != NULL){
        mostraNode(*aux);
        aux = aux->proximo;
    }
     printf(" >>\n ");
}

void mostraNode(Node novo){
    """Mostra os dados de um Elemento Node""";
    printf(" %d ",novo.valor);
}

void mostraPosicao(LSE *ls, int pos);

void apagaLista(LSE *ls){
}

void apagaNode(Node *novo){
    """Apaga um elemento de Lista""";
    printf("\n Node Apagado!");
    mostraNode(*novo);
    free(novo);
}