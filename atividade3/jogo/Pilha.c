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

void red()
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

Pilha *criaPilha(int tamanhoMax, int numeroPilha)
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->tamanhoMax = tamanhoMax;
    p->topo = NULL;
    p->qtd = 0;
    p->numeroPilha=numeroPilha;
    return p;
}

Disco *criaElementoPilhaDisco(int cor)
{
    Disco *di = (Disco *)malloc(sizeof(Disco));
    di->proximo = NULL;
    di->cor = cor;
    return di;
}

int push(Pilha *p, Disco *disco)
{
    /* printf("\ntamanho: %d",(p->tamanhoMax));
    printf("\nqtd: %d", (p->qtd)); */
    if(p->tamanhoMax==p->qtd){
        printf(" Pilha cheia, nao foi possivel adicionar o disco aqui!"); 
        return 1;       
    }
    else if ((disco != NULL) && (p->tamanhoMax != p->qtd))
    {
        disco->proximo = p->topo;
        p->topo = disco;
        p->qtd++;
        return 0;
    }
    else
    {
        printf(" --Erro - Não um elemento de Pilha!");
        return 1;
    }
}

Disco *pop(Pilha *p)
{
    Disco *aux = NULL;
    if (p->topo == NULL)
    {
        printf("\n -- Nao pode realizar POP - Pilha Vazia\n");
    }
    else
    {
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
        // printf("\n O");
        printf("\n %d ", di.cor);
        reset();
        break;
    case 2:
        blue();
        // printf("\n O");
        printf("\n %d ", di.cor);
        reset();
        break;

    case 3:
        green();
        // printf("\n O");
        printf("\n %d ", di.cor);
        reset();

        break;

    case 4:
        yellow();
        // printf("\n O");
        printf("\n %d ", di.cor);
        reset();
        break;
    }
}

void mostraTopo(Pilha *p)
{
    if (p->topo != NULL)
    {
        printf("\n Mostra TOPO - Pilha");
        mostraDisco(*p->topo);
    }
    else
    {
        printf("\n TOPO NULO - Pilha Vazia \n");
    }
}

void apagaPilha(Pilha *p)
{
    while (p->topo != NULL)
    {
        free(pop(p));
    }
    mostraTopo(p);
}

void mostraPilha(Pilha *p)
{
    Disco *aux = p->topo;
    if (aux == NULL){
        if (p->tamanhoMax != 1)
        {
            printf("\nPilha %d\n Vazia\n", p->numeroPilha);
        }
        else
        {
            printf("\nPilha %d\ntemporaria\n Vazia\n", p->numeroPilha);
        }
    }else{
        while (aux != NULL)
        {
            mostraDisco(*aux);
            aux = aux->proximo;
        }
        if(p->tamanhoMax!=1){
            printf("\nPilha %d\n\n", p->numeroPilha);
        }else{
            printf("\nPilha %d\ntemporaria\n", p->numeroPilha);
        }
    }
       
}

int getCorDaPilha(Pilha *p){ //0 vazia ou diferente - 1 igual
    Disco *prox = p->topo->proximo;
    Disco *atual = p->topo;
    if (prox == NULL)
    {
        //printf("\n  -- Pilha Vazia!!\n");
        return 1;
    }
    else
    {
        while (prox != NULL)
        {            
            if ((prox->cor != atual->cor) && (prox!=NULL)){
                return 1;
            }
            atual = prox;
            prox = prox->proximo;
        }
        return 0;        
    }
}

int checkGameStatus(Pilha *pilhas[]){
    int controle = 0;
    for(int i=0; i<4;i++){
        if (pilhas[i]->qtd!=3){
            return 1;
        }else{
            controle = getCorDaPilha(pilhas[i]);
            if(controle==1){
                return 1;
            }
        }
    }
    return 0;//se todas as 4 pilhas tiverem as cores iguais gameover
}

void comecaJogoFacil()
{
    /* Pilha *pilha1 = criaPilha(4,1);
    Pilha *pilha2 = criaPilha(4,2);
    Pilha *pilha3 = criaPilha(4,3);
    Pilha *pilha4 = criaPilha(4,4);
    Pilha *pilhaTemp1 = criaPilha(1,5);
    Pilha *pilhaTemp2 = criaPilha(1,6); */
    Pilha *pilhas[6];
    for(int i = 0; i< 6;i++){
        if(i<4){
            pilhas[i] = criaPilha(4, i);
        }else{
            pilhas[i] = criaPilha(1, i);
        }        
    }
    int cores[12] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4}; //discos para distribuir 1-red,2-blue,3-green,4-yellow
    int vet[12];
    sequencia(vet);
    Disco *discos[12];
    for (int i = 0; i < 12; i++)
    {
        discos[i] = criaElementoPilhaDisco(cores[vet[i]]);
        if (i < 3)
        {
            push(pilhas[0], discos[i]);
        }
        else if (i < 6)
        {
            push(pilhas[1], discos[i]);
        }
        else if (i < 9)
        {
            push(pilhas[2], discos[i]);
        }
        else if (i < 12)
        {
            push(pilhas[3], discos[i]);
        }
    }
    int gameState = 1;
    int operacao, origem, destino, erro=0;
    Disco *aux;
    while(gameState==1){        
        printf("\n\nSelecione o movimento que deseja fazer:");
        printf("\n -- 1 - Mostra pilhas");
        printf("\n -- 2 - Mover discos");
        printf("\n -- 3 - Sair do Jogo");
        printf("\nInforme sua Opcao:");
        scanf("%d", &operacao);
        fflush(stdin);
        system("cls");
        switch (operacao)
        {
            case 1:
                printf("\n Mostrar pilhas\n");
                for(int i =0; i<6;i++){
                    mostraPilha(pilhas[i]);
                }                
                break;
            case 2:
                printf("\n Mover discos \n");
                printf("\n Selecione a pilha que deseja retirar o disco: 0,1,2,3,4,5 \n ");
                scanf("%d", &origem);
                printf("\n Selecione a pilha que deseja enviar o disco: 0,1,2,3,4,5 \n ");
                scanf("%d", &destino);
                aux = pop(pilhas[origem]);
                erro = push(pilhas[destino],aux);
                if(erro==1){
                    push(pilhas[origem], aux);
                }
                erro=0;
                fflush(stdin);
                system("cls");
                gameState = checkGameStatus(pilhas);                
                break;

            case 3:
                printf("\n Sair do Jogo \n");

                break;

            

            default:
                printf("\nOpção Inválida!\n");
        }
    }
    /* for (int i = 0; i < 6; i++)
    {
        mostraPilha(pilhas[i]);
    } */
    printf("\n Voce venceu!!! \n");
    
}

void menu()
{
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