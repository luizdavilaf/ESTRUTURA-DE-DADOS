#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Pilha.h"

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
    p->numeroPilha = numeroPilha;
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
    if (p->tamanhoMax == p->qtd)
    {
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
        // printf("\t O");
        printf("   %d ", di.cor);
        reset();
        break;
    case 2:
        blue();
        // printf("\t O");
        printf("   %d ", di.cor);
        reset();
        break;

    case 3:
        green();
        // printf("\t O");
        printf("   %d ", di.cor);
        reset();

        break;

    case 4:
        yellow();
        // printf("\t O");
        printf("   %d ", di.cor);
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
    if (aux == NULL)
    {
        if (p->tamanhoMax != 1)
        {
            printf("\nPilha %d\n Vazia\n", p->numeroPilha);
        }
        else
        {
            printf("\nPilha %d\ntemporaria\n Vazia\n", p->numeroPilha);
        }
    }
    else
    {
        while (aux != NULL)
        {
            printf("\n");
            mostraDisco(*aux);
            aux = aux->proximo;
        }
        if (p->tamanhoMax != 1)
        {
            printf("\nPilha %d\n\n", p->numeroPilha);
        }
        else
        {
            printf("\nPilha %d\ntemporaria", p->numeroPilha);
        }
    }
}

void mostraPilhasHorizontalFacil(Pilha *pilhas[], int tamanho)
{
    Disco *discos_aux[6];
    for (int i = 0; i < tamanho; i++)
    {
        discos_aux[i] = pilhas[i]->topo;
    }

    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < tamanho; i++)
        {
            if (discos_aux[i] != NULL)
            {
                printf("\t\t");
                mostraDisco(*discos_aux[i]);
                discos_aux[i] = discos_aux[i]->proximo;
            }
            else
            {
                printf("\t\t ");
            }
        }
        printf("\n");
    }
    int t = 1;
    for (int i = 0; i < tamanho; i++)
    {
        if (i < 4)
        {
            printf("\t\tPilha %d", pilhas[i]->numeroPilha);
        }
        else
        {
            printf("\t\tPilhaT%d", t);
            t++;
        }
    }
}

int getCorDaPilha(Pilha *p)
{ // 0 vazia ou diferente - 1 igual
    Disco *prox = p->topo->proximo;
    Disco *atual = p->topo;
    if (prox == NULL)
    {
        // printf("\n  -- Pilha Vazia!!\n");
        return 1;
    }
    else
    {
        while (prox != NULL)
        {
            if ((prox->cor != atual->cor) && (prox != NULL))
            {
                return 1;
            }
            atual = prox;
            prox = prox->proximo;
        }
        return 0;
    }
}

int checkGameStatus(Pilha *pilhas[])
{
    int controle = 0;
    for (int i = 0; i < 4; i++)
    {
        if (pilhas[i]->qtd != 3)
        {
            return 1;
        }
        else
        {
            controle = getCorDaPilha(pilhas[i]);
            if (controle == 1)
            {
                return 1;
            }
        }
    }
    return 0; // se todas as 4 pilhas tiverem as cores iguais gameover
}

void mostraJogo(Jogo *jogo)
{
    printf("\nNome: %s", jogo->nome);
    printf("\tTempo: %d segundos", jogo->tempo);
    printf("\tMovimentos:%d", jogo->movimentos);    
    printf("\tVenceu o jogo? %s", jogo->estado);
    printf("\tDificuldade: %s\n", jogo->dificuldade);
}

Jogo *comecaJogoFacil(Jogo *jogo, int tamanho)
{
    printf("\nInforme seu nome:");
    scanf("%s", jogo->nome);
    Pilha *pilhas[6];
    for (int i = 0; i < tamanho; i++)
    {
        if (i < 4)
        {
            pilhas[i] = criaPilha(4, i);
        }
        else
        {
            pilhas[i] = criaPilha(1, i);
        }
    }
    int cores[12] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4}; // discos para distribuir 1-red,2-blue,3-green,4-yellow
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
    int operacao, origem, destino, erro = 0;
    Disco *aux;
    time_t begin = time(NULL);
    while (gameState == 1)
    {
        printf("\n\nSelecione o movimento que deseja fazer:");
        printf("\n -- 1 - Mostra pilhas na horizontal");
        printf("\n -- 2 - Mover discos");
        printf("\n -- 3 - Voltar ao menu inicial");
        printf("\n -- 4 - Mostra pilhas na vertical");
        printf("\nInforme sua Opcao:");
        scanf("%d", &operacao);
        fflush(stdin);
        //system("cls");
        switch (operacao)
        {
        case 1:
            mostraPilhasHorizontalFacil(pilhas, tamanho);
            break;
        case 2:
            jogo->movimentos++;
            printf("\nMover discos \n");
            while(origem<0 || origem>tamanho-1){
                if (tamanho == 6)
                {
                    printf("\nSelecione a pilha que deseja retirar o disco: 0,1,2,3,4 para t1 ,5 para t2 \n ");
                }
                else if (tamanho == 5)
                {
                    printf("\nSelecione a pilha que deseja retirar o disco: 0,1,2,3,4 para t1 \n ");
                }
                else if (tamanho == 4)
                {
                    printf("\nSelecione a pilha que deseja retirar o disco: 0,1,2,3,4\n ");
                }
                scanf("%d", &origem);
                
            }
            while (destino < 0 || destino > tamanho - 1)
            {
                
                if (tamanho == 6)
                {
                    printf("\nSelecione a pilha que deseja enviar o disco: 0,1,2,3,4 para t1 e 5 para t2  \n ");
                }
                else if (tamanho == 5)
                {
                    printf("\nSelecione a pilha que deseja enviar o disco: 0,1,2,3 e 4 para t1   \n ");
                }
                else if (tamanho == 4)
                {
                    printf("\nSelecione a pilha que deseja enviar o disco: 0,1,2,3 ou 4   \n ");
                }
                scanf("%d", &destino);
            }
            printf("origem: %d", origem);
            printf("destino: %d",destino);
            aux = pop(pilhas[origem]);
            erro = push(pilhas[destino], aux);
            if (erro == 1)
            {
                push(pilhas[origem], aux);
                }
                erro = 0;
                fflush(stdin);
                system("cls");
                gameState = checkGameStatus(pilhas);
                origem=-1;
                destino=-1;
                break;
            case 3:
                printf("\n Sair da rodada e voltar ao menu \n");
                gameState = 2;
                break;
            case 4:
                printf("\n vertical \n");
                printf("\n Mostrar pilhas\n");
                for (int i = 0; i < tamanho; i++)
                {
                    mostraPilha(pilhas[i]);
                }
                break;
            case 5:
                printf("\n Sair do Jogo \n");
                break;
            default:
                printf("\nOpção Inválida!\n");
            }
    }
    time_t end = time(NULL);
    jogo->tempo = (end - begin);
    if(gameState==0){
        strcpy(jogo->estado, "sim");
        printf("\n============================= VOCE VENCEU !!! ============================= \n");
        mostraPilhasHorizontalFacil(pilhas, tamanho);
        printf("\n=========================================================================== \n");
    }    
    return jogo;
}

Jogo *criaNovoJogo(char dificuldade[7]){
    Jogo *jogo;
    jogo = (Jogo *)malloc(sizeof(Jogo));
    strcpy(jogo->nome, "");
    jogo->movimentos=0;
    jogo->tempo=0;
    strcpy(jogo->dificuldade, dificuldade);
    strcpy(jogo->estado, "nao");    
    return jogo;
}

    void
    menu()
{
    int operacao = 0;
    Jogo *jogos[100];
    int contador_de_jogos = 0;
    printf("\n Menu do jogo Torre de Hanoi:");
    while (operacao != 1)
    {
        int dificuldade;
        printf("\n\nSelecione a dificuldade:");
        printf("\n -- 1 - Nivel Facil(dois temporarios):");
        printf("\n -- 2 - Nivel Medio(um temporario):");
        printf("\n -- 3 - Nivel Dificil(sem temporario):");
        printf("\n -- 4 - Livro de Recordes");
        printf("\n -- 5 - Sair do Jogo");
        printf("\nInforme sua Opcao:");
        scanf("%d", &dificuldade);
        fflush(stdin);
        system("cls");
        switch (dificuldade)
        {
        case 1:
            printf("\n Nivel Facil\n");
            jogos[contador_de_jogos] = criaNovoJogo("Facil");            
            jogos[contador_de_jogos] = comecaJogoFacil(jogos[contador_de_jogos], 6);
            contador_de_jogos++;
            break;
        case 2:
            printf("\n Nivel Medio \n");
            jogos[contador_de_jogos] = criaNovoJogo("Medio");           
            jogos[contador_de_jogos] = comecaJogoFacil(jogos[contador_de_jogos], 5);
            contador_de_jogos++;
            break;

        case 3:
            printf("\n Nivel Dificil \n");
            jogos[contador_de_jogos] = criaNovoJogo("Dificil");           
            jogos[contador_de_jogos] = comecaJogoFacil(jogos[contador_de_jogos], 4);
            contador_de_jogos++;
            break;

        case 4:
            printf("\n Livro de Recordes \n");
            for (int i = 0; i < contador_de_jogos; i++)
            {
                mostraJogo(jogos[i]);
            }
            break;

        case 5:
            printf("\n Sair do jogo \n");
            operacao = 1;
            break;

        default:
            printf("\nOpcao Invalida!\n");
        }
    }
    exit(0);
}