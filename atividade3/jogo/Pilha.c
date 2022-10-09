#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Pilha.h"

/* 
1 - red
2 - blue
3 - green
4 - yellow
 */

void sequencia(int vet[])
{
    int i = 0, j, igual;
    srand(time(NULL));
    while (i < 12)
    {
        vet[i] = rand() % 12; // sorteia um número
        igual = 0;
        for (j = 0; j < i; j++)
        { // percorre a parte do vetor já preenchida
            if (vet[j] == vet[i])
                igual = 1; // número repetido
        }
        if (igual == 0) // significa que o elemento não se repetiu
            i++;
    }
    
}

void red ()
{
    printf("\033[1;31m");
}

void blue()
{
    printf("\033[0;34m");
}

void green()
{
    printf("\033[0;32m");
}

void yellow()
{
    printf("\033[1;33m");
}

void reset()
{
    printf("\033[0m");
}

Pilha* criaPilha(){
    Pilha *p  = (Pilha *)malloc(sizeof(Pilha));
    p->topo = NULL;
    p->qtd = 0;
    return p;
}

Disco *criaElementoPilhaDisco(int cor)
{
    Disco *di = (Disco *)malloc(sizeof(Disco));
    di->proximo = NULL;
    di->cor = cor;
    return di;
}

void push(Pilha *p, Disco *lv)
{
    if(lv!=NULL){
        lv->proximo = p->topo;
        p->topo = lv;
        p->qtd++;
    }else{
        printf(" --Erro - Não um elemento de Pilha!");
    }
}

Disco* pop(Pilha *p){
    Disco *aux = NULL;
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



void mostraDisco(Disco di)
{

    /*
1 - red
2 - blue
3 - green
4 - yellow
 */
    switch (di.cor)
    {
    case 1:
        red();
        //printf("\n O");
        printf("\n %d ", di.cor);
        reset();
        break;
    case 2:
        blue();
        //printf("\n O");
        printf("\n %d ", di.cor);
        reset();
        break;

    case 3:
        green();
        //printf("\n O");
        printf("\n %d ", di.cor);
        reset();

        break;

    case 4:
        yellow();
        //printf("\n O");
        printf("\n %d ", di.cor);
        reset();
        break;
    }
}

void mostraTopo(Pilha *p){
    if(p->topo != NULL){
        printf("\n Mostra TOPO - Pilha");
        mostraDisco(*p->topo);
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
    Disco *aux = p->topo;
    if(aux == NULL)
        printf("\n  -- Pilha Vazia!!\n");
    else
        while(aux !=NULL){
            mostraDisco(*aux);
            aux = aux->proximo;
        }
}

void comecaJogoFacil(){
    Pilha *pilha1 = criaPilha();
    Pilha *pilha2 = criaPilha();
    Pilha *pilha3 = criaPilha();
    Pilha *pilha4 = criaPilha();
    Pilha *pilhaTemp1 = criaPilha();
    Pilha *pilhaTemp2 = criaPilha();
    int cores[12] = {1,1,1,2,2,2,3,3,3,4,4,4};
    int vet[12];
    sequencia(vet);
    Disco *discos[12];
    for(int i=0;i<12;i++){
        discos[i] = criaElementoPilhaDisco(cores[vet[i]]);
    }   
    for(int i=0;i<12;i++){
        mostraDisco(*discos[i]);
    }
}

void menu(){
    printf("\n Menu do jogo Torre de Hanoi:");
    int dificuldade;    
    printf("\n\nSelecione a dificuldade:");
    printf("\n -- 1 - Nivel Facil(dois temporarios):");
    printf("\n -- 2 - Nivel Medio(um temporario):");
    printf("\n -- 3 - Nivel Dificil(sem temporario):");
    printf("\n -- 4 - Sair do Jogo");
    printf("\nInforme sua Opcao:");
    scanf("%d", &dificuldade);
    fflush(stdin);
    system("cls");
    switch (dificuldade)
    {
    case 1:
        printf("\n Nivel Facil\n");
        comecaJogoFacil();
        break;
    case 2:
        printf("\n Nivel Medio \n");

        break;

    case 3:
        printf("\n Nivel Dificil \n");

        break;

    case 4:
        printf("\n Saindo do jogo \n");
      
        break;
    
    default:
        printf("\nOpção Inválida, saindo do jogo\n");
    }
}