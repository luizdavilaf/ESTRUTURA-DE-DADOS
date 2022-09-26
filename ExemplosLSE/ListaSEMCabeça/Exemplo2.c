#include <stdio.h>
#include <stdlib.h>
#include "LSEG2.h"


void menuLista(Node *lista){
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
    int op, valor, pos;
    printf("\nInforme uma Opção:");
    scanf("%d",&op);
    switch(op){
        case 1:
            lista = insereInicio(lista,criaNoDados());
        break;
        case 2:
            lista = insereFim(lista,criaNoDados());
        break;
        case 3:
            printf("\nInforme a posicao do novo Elemento: ");
            scanf("%d",&pos);
            lista = inserePosicao(lista,criaNoDados(),pos);
        break;
        case 4:
            printf("\nApaga o primeiro Elemento:");
            lista = removeInicio(lista);
            
        break;
        /*
        case 5:
            printf("\nInforme o novo Elemento e a posição para inserir o novo Node na Lista:");
            scanf("%d",&valor);
          //  insereInicio(lista,valor);
        break;
        case 6:
            printf("\nInforme o novo Elemento e a posição para inserir o novo Node na Lista:");
            scanf("%d",&valor);
            insereInicio(lista,valor);
        break;
        */
        case 7:
            printf("\nImprime a Lista:");
            mostraLista(lista);
        break;
        case 8:
            printf("\nInforme o novo Elemento e a posição para inserir o novo Node na Lista:");
            scanf("%d",&valor);
          //  insereInicio(lista,valor);
        break;
        case 9:
            printf("\nInforme o novo Elemento e a posição para inserir o novo Node na Lista:");
            scanf("%d",&valor);
         //   insereInicio(lista,valor);
        break;
        case 10:
            printf("\nInforme o novo Elemento e a posição para inserir o novo Node na Lista:");
            scanf("%d",&valor);
         //   insereInicio(lista,valor);
        break;
        default:
            printf("\nFim do Programa!!");
    }
    if(op!=0)
        menuLista(lista);
}



int main(){

    Node *lista1 =NULL;

    menuLista(lista1);

    printf("\n Fim do Sistema - Bye!");
}