#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"



Pilha* criaPilha(){
    Pilha *p  = (Pilha *)malloc(sizeof(Pilha));
    p->topo = NULL;
    p->qtd = 0;
    return p;
}

Livro* criaElementoPilhaLivro(int ano, char at [] , char tit [] ){
    Livro *lv = (Livro *)malloc(sizeof(Livro));
    lv->proximo = NULL;
    lv->ano = ano;
    strcpy(lv->autor,at);
    strcpy(lv->titulo,tit);
    return lv;
}


void push(Pilha *p, Livro *lv){
    if(lv!=NULL){
        lv->proximo = p->topo;
        p->topo = lv;
        p->qtd++;
    }else{
        printf(" --Erro - Não um elemento de Pilha!");
    }

}

Livro* pop(Pilha *p){
    Livro *aux = NULL;
    if(p->topo == NULL){
        printf("\n -- Nao pode realizar POP - Pilha Vazia\n");
    }else{
        aux = p->topo;
        p->topo = p->topo->proximo;
        p->qtd--;
        aux->proximo = NULL;
    }
    return aux;
}

void mostraLivro(Livro lv){
    printf("\n\t Titulo: %s \n\t Autor: %s \n\t Ano: %d \n",lv.titulo,lv.autor,lv.ano);
}

void mostraTopo(Pilha *p){
    if(p->topo != NULL){
        printf("\n Mostra TOPO - Pilha");
        mostraLivro(*p->topo);
    }else{
        printf("\n TOPO NULO - Pilha Vazia \n");
    }
}


void apagaPilha(Pilha *p){
    while(p->topo !=NULL){
        free(pop(p));
    }
    mostraTopo(p);
}


void mostraPilha(Pilha *p){
    Livro *aux = p->topo;
    if(aux == NULL)
        printf("\n  -- Pilha Vazia!!\n");
    else
        while(aux !=NULL){
            mostraLivro(*aux);
            aux = aux->proximo;
        }
}
        
Pilha* invertePilha(Pilha *p){
    Pilha *aux = criaPilha();
    Livro *laux = pop(p);
    while(laux!=NULL){
        push(aux,laux);
        laux = pop(p);
    }
    return aux;
}

void invertePilha2(Pilha **p){

    Pilha *aux = criaPilha();
    Livro *laux = pop(*p);
    while(laux!=NULL){
        push(aux,laux);
        laux = pop(*p);
    }
    *p = aux;
}


void invertePilha3(Pilha *p){
/*
    Pilha *aux = criaPilha();
    Livro *laux = pop(*p);
    while(laux!=NULL){
        push(aux,laux);
        laux = pop(*p);
    }
    *p = aux;
*/
}