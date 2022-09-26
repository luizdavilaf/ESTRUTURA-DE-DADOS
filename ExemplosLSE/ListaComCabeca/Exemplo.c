#include <stdio.h>
#include <stdlib.h>
#include "LSE.h"


void menuLista(LSE *lista){
    printf("\n\n Menu para controle da Lista");
    printf("\nOpções:");
    printf("\n\t 1 - Insere no Início um elemento:");
    printf("\n\t 2 - Insere no Fim um elemento:");
    printf("\n\t 3 - Insere na Posição um elemento:");
    printf("\n\t 4 - Remove no Início um elemento:");
    printf("\n\t 5 - Remove no Fim um elemento:");
    printf("\n\t 6 - Remove na Posição um elemento:");
    printf("\n\t 7 - Mostra Lista:");
    printf("\n\t 8 - Cria Nova Lista Invertida e Mostra:");
    printf("\n\t 9 - Cria SubLista:");
    printf("\n\t 10 - Encontra na Lista:");
    printf("\n\t 0 - Fim do programa:");
    int op, valor, pos, inicio, fim;
    printf("\nInforme uma Opção:");
    scanf("%d",&op);
    Node *aux;
    switch(op){
        case 1:
            insereNoInicio(lista,criaNoDados());
        break;
        /*
        case 2:
            insereNoFim(lista,criaNoDados());
        break;
        case 3:
            printf("\nInforme a posicao do novo Elemento: ");
            scanf("%d",&pos);
            insereNaPosicao(lista,criaNoDados(),pos);
        break;
        case 4:
            printf("\nApaga o primeiro Elemento:");
            aux = removeNoInicio(lista);
            aux!=NULL?printf("\n O valor %d será deletado:",aux->valor):printf("\nSem remoção!");
            free(aux);            
        break;
        case 5:
            printf("\nApaga o Último Elemento:");
            aux = removeNoFim(&lista);
            printf("\n O valor %d será deletado:",aux!=NULL?aux->valor:0);
            free(aux);
        break;
        case 6:
            printf("\nInforme o novo Elemento e a posição para inserir o novo Node na Lista:");
            scanf("%d",&valor);
            aux = removeNaPosicao(&lista,valor);
        break;
        */
        case 7:
            printf("\nImprime a Lista:\n");
            mostraLista(lista);
        break;
        /*
        case 8:
            printf("\nInforme um valor para Busca:");
            scanf("%d",&valor);
            pos = localizaElemento(lista,valor);
            pos>=0?printf("\n O elemento está na posição %d ",pos): printf("\n O elemento não foi encontrado");
        break;
        case 9:
            printf("\nInforme as Posições inicio e fim para criar a subLista:");
            scanf("%d %d",&inicio,&fim);
            aux = criaSubLista(&lista,inicio,fim);
            printf("\n Sub Lista Criada:");
            mostraLista(aux);
            free(aux);
        break;
        case 10:
            printf("\nCria Lista Invertida:");
            aux = criaNovaListaInvertida(&lista);
            mostraLista(aux);
        break;
        */
        default:
            printf("\nFim do Programa!!");
    }
    if(op!=0)
        menuLista(lista);
}


int main(){

    LSE *lista1 = criaListaLSE();

    menuLista(lista1);

    printf("\n Fim do Sistema - Bye!");
}