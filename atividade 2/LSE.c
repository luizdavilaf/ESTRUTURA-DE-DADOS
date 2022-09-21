// biblioteca de funções, implementações
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LSE.h"

LSE *criaListaLSE()
{
    ""
    "Aloca memória para uma nova lista"
    "";
    LSE *nova = (LSE *)malloc(sizeof(LSE));
    nova->primeiro = NULL;
    nova->n_elementos = 0;
    return nova;
}

Contato *cadastraContato(char nome[], char tel[], char tp)
{
    ""
    "Aloca memória para um novo Elemento (Contato)"
    "";
    Contato *novoContato = (Contato *)malloc(sizeof(Contato));
    strcpy(novoContato->nome, nome);
    strcpy(novoContato->telefone, tel);
    novoContato->tipo = tp;
    novoContato->proximo = NULL;
    return novoContato;
}

Contato *criaNovoContato()
{
    char nome[20], telefone[20], tp;
    printf("\nInforme seu nome:");
    scanf("%s", nome);
    printf("\nInforme seu Telefone:");
    scanf("%s", telefone);
    /* printf("\nInforme F - Familia O - Outros:");
    scanf("%c", &tp); */
    // return cadastraContato(nome, telefone, tp);
    return cadastraContato(nome, telefone, tp);
}

void insereNoInicio(LSE *ls, Contato *novo)
{
    ""
    "insere um novo elemento no inicio da lista"
    "";
    if (ls->primeiro == NULL)
        novo->proximo = NULL;
    else
        novo->proximo = ls->primeiro;
    ls->primeiro = novo;
    ls->n_elementos++;
}

void insereNoFim(LSE *ls, Contato *novo)
{
    ""
    "Insere no fim da lista"
    "";
    if (ls->primeiro == NULL)
        insereNoInicio(ls, novo);
    else
    {
        Contato *aux = ls->primeiro;
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        novo->proximo = NULL;
        aux->proximo = novo;
        ls->n_elementos++;
    }
}

void insereNaPosicao(LSE *ls, Contato *novo, int pos)
{
    ""
    "Insere na posição desejada da Lista"
    "";
    Contato *aux = ls->primeiro;
    if (ls->n_elementos <= 0)
    { // se a lista é vazia ou a posição é negativa
        insereNoInicio(ls, novo);
    }
    else if (pos >= ls->n_elementos)
    { // se a posição desejada é a ultima ou maior q a ultima
        insereNoInicio(ls, novo);
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            aux = aux->proximo;
        }
        novo->proximo = aux->proximo;
        aux->proximo = novo;
        ls->n_elementos++;
    }
}

Contato *removeNoInicio(LSE *ls)
{
    ""
    "Remove o primeiro elemento da Lista"
    "";
    Contato *aux = ls->primeiro;
    if (aux != NULL)
    {
        ls->n_elementos--;
        ls->primeiro = aux->proximo;
        aux->proximo = NULL;
    }
    return aux;
}

Contato *removeNoFim(LSE *ls)
{
    ""
    "Remove e retorna o último elemento da lista"
    "";
    Contato *aux = ls->primeiro;
    Contato *anterior = aux;
    if (aux == NULL) // se a lista é vazia
    {
        printf("lista vazia");
    }
    else if (aux->proximo == NULL)
    { // se o segundo é nulo
        anterior = aux;
        aux = NULL;
        ls->n_elementos--;
        return anterior;
    }
    else
    {
        while (aux->proximo != NULL)
        {
            anterior = aux;
            aux = aux->proximo;
        }
        anterior->proximo = NULL;
        ls->n_elementos--;
        return aux;
    }
    return aux;
}

Contato *removeNaPosicao(LSE *ls, int pos)
{
    ""
    "Remove e retorna o elemento da lista na posição indicada"
    "";
    if (pos >= ls->n_elementos)
    { // se a posição é maior que lista
        removeNoFim(ls);
    }
    else if (pos <= 0)
    {
        removeNoInicio(ls);
    }
    else
    {
        Contato *aux = ls->primeiro;
        Contato *anterior = aux; // posicao atual do i do for(anterior a posicao a ser removida)
        for (int i = 0; i < pos - 1; i++)
        {
            anterior = aux;
            aux = aux->proximo;
        }
        anterior->proximo = aux->proximo; // proximo do anterior vai ser o proximo do removido
        ls->n_elementos--;
        return aux;
    }
}

int retornaQuantidade(LSE *ls)
{
    ""
    "Retorna a quantidade de Elementos da Lista "
    "";
    return ls->n_elementos;
}

void mostraLista(LSE *ls)
{
    Contato *aux = ls->primeiro;
    if (aux == NULL)
        printf("\n Lista Vazia!!\n");
    else
        do
        {
            mostraContato(aux);
            aux = aux->proximo;
        } while (aux != NULL);
}

void mostraContato(Contato *novo)
{
    ""
    "Mostra os dados de um Elemento Contato"
    "";
    printf("\nNome:%s", novo->nome);
    printf("\t Telefone:%s", novo->telefone);
    printf("\t Tipo:%c", novo->tipo);
}

void mostraContatoPosicao(LSE *ls, int pos)
{
    Contato *aux = ls->primeiro;
    if (ls->n_elementos == 0)
    { // se a lista é vazia
        printf("lista vazia");
    }
    else if (pos <= 0)
    { // se a posição é negativa, mostra o primeiro
        mostraContato(aux);
    }
    else
    {
        if (pos >= ls->n_elementos)
        {                          // se a posição desejada é a ultima ou maior q a ultima
            pos = ls->n_elementos; // vai mostrar o ultimo
        }
        for (int i = 0; i < pos - 1; i++)
        {
            aux = aux->proximo;
        }
        mostraContato(aux);
    }
}

void apagaLista(LSE *ls)
{
}

void apagaContato(Contato *novo)
{
    ""
    "Apaga um elemento de Lista"
    "";
    printf("\n Contato Apagado!");
    mostraContato(novo);
    free(novo);
}

int buscaContatoPorNome(LSE *ls, char nome[])
{
    Contato *aux = ls->primeiro;
    if (aux == NULL)
    {
        return -1;
    }
    for (int i = 1; i <= ls->n_elementos; i++)
    {
        if (strcmp(aux->nome, nome) == 0)
        {
            return i;
        }
        aux = aux->proximo;
    }
    return -1;
}

LSE *divideLista(LSE *ls, int inicio, int fim)
{
    ""
    "Divide a lista, recebe uma lista (LSE *l, int inicio, int fim), retorna um sublista com os contatos contidos entre os índices início e fim"
    "";
    Contato *aux = ls->primeiro;
    LSE *nova = criaListaLSE();
    if (aux == NULL)
    {
        printf("\n Lista Vazia!!\n");
        return ls;
    }
    if (fim > (ls->n_elementos))
    { // caso seja maior, vai pegar o ultimo como final da sublista
        fim = ls->n_elementos;
    }
    for (int i = 0; i < fim - 1; i++)
    {
        if (i == inicio - 1)
        { // se for o primeiro da lista vai ser adicionado
            nova->primeiro = aux;
            nova->n_elementos++;
        }
        else if (i > (inicio - 1))
        {
            nova->n_elementos++;
        }
        aux = aux->proximo;
    }
    aux->proximo = NULL;
    nova->n_elementos++;
    return nova;
}

void insereOrdenado(LSE *ls, Contato *novo)
{
    ""
    "Insere na posição alfabética da Lista"
    "";
    Contato *aux = ls->primeiro;
    Contato *anterior = aux;

    if (aux == NULL)
    { // se a lista é vazia ou a posição é negativa
        insereNoInicio(ls, novo);
    }
    else if (strcmp(novo->nome, aux->nome) < 0)
    { // se é menor q o primeiro
        insereNoInicio(ls, novo);
    }else if((strcmp(novo->nome, aux->nome) > 0)&&(aux->proximo==NULL)){
        insereNoFim(ls,novo);
    }
    else
    {        
        for(int i=0; i<ls->n_elementos;i++){
            if(strcmp(novo->nome, aux->nome) < 0){
            novo->proximo = aux;
            anterior->proximo = novo;
            ls->n_elementos++;
            i=ls->n_elementos;                           
            }
            anterior = aux;
            aux = aux->proximo;
        }
    }
}

void menu2(LSE *ls)
{
    printf("\n Menu para controlar a Agenda de Contatos:");
    int op, posicao, id = 1;
    char nome[20];
    Contato *aux;
    LSE *familia = criaListaLSE();
    do
    {
        // system("clear");
        printf("\n\nInforme uma Opção:");
        printf("\n -- 1 - Inserir novo Contato:");
        printf("\n -- 2 - Remover Contato:");
        printf("\n -- 3 - Consultar um contato pelo Nome:");
        printf("\n -- 4 - Mostrar Lista Ordenada Nome:");
        printf("\n -- 5 - Criar o grupo familia:");
        printf("\n -- 0 - Sair do Programa:\n");
        printf("\nInforme sua Opçao:");
        scanf("%d", &op);
        fflush(stdin);

        system("clear");

        switch (op)
        {
        case 1:
            printf("\n Inserção em ordem alfabetica\n");
            insereOrdenado(ls, criaNovoContato());
            printf("\n Inserção Realizada com Sucesso");

            break;
        case 2:
            printf("\n Remove Contato com base Nome: \n");
            printf("\nInforme o nome:\n");
            scanf("%s", nome);
            aux = removeNaPosicao(ls, buscaContatoPorNome(ls, nome));
            printf("\n Remoção realizada com Sucesso");
            free(aux);
            break;

        case 3:
            printf("\n Consulta Contato com base Nome: \n");
            printf("\nInforme o nome:\n");
            scanf("%s", nome);
            posicao = buscaContatoPorNome(ls, nome);
            mostraContatoPosicao(ls, posicao);
            break;

        case 4:
            printf("\n Mostra Lista Ordenada: \n");
            mostraLista(ls);
            break;

        /* case 5:
            printf("\n Apaga o grupo da Família: \n");
            apagaLista(familia);
            printf("\n Cria novo o grupo da Família: \n");
            criaNovoGrupo(familia);
            printf("\n Mostra o grupo da Família: \n");
            mostraLista(familia);
            break; */
        default:
            printf("\nOpção Inválida!!\n");
        }
    } while (op > 0);
}

void menu(LSE *ls)
{
    printf("\nMenu para controlar a Lista de Contatos:");
    int op, posicao, id = 1, posicao_inicial, posicao_final;
    Contato *aux;
    do
    {
        // system("clear");
        printf("\n\nInforme uma Opção:");
        printf("\n -- 1 - para Inserir Contato no Início:");
        printf("\n -- 2 - para Inserir Contato no Fim:");
        printf("\n -- 3 - para Inserir Contato na Posição:");
        printf("\n -- 4 - para Remove Contato no Início:");
        printf("\n -- 5 - para Remove Contato no Fim:");
        printf("\n -- 6 - para Remove Contato na Posição:");
        printf("\n -- 7 - para Mostra Lista de Contatos:");
        printf("\n -- 8 - para Mostrar Contato na Posição:");
        printf("\n -- 9 - Apagar Lista:");
        printf("\n -- 10 - Dividir Lista:");
        printf("\n -- 0 - para Sair do Programa:\n");
        printf("\nInforme sua Opçao:");
        scanf("%d", &op);
        fflush(stdin);

        system("clear");

        switch (op)
        {
        case 1:
            printf("\n Inserção no Início. \n");
            insereNoInicio(ls, criaNovoContato());
            printf("\n Inserção Realizada com Sucesso");

            break;
        case 2:
            printf("\n Inserção no Fim. \n");
            insereNoFim(ls, criaNovoContato());
            printf("\n Inserção Realizada com Sucesso");

            break;
        case 3:
            printf("Insere na Posição, informa a posição:");
            scanf("%d", &posicao);
            fflush(stdin);
            insereNaPosicao(ls, criaNovoContato(), posicao);
            break;
        case 4:
            printf("\nRemove no Início. \n");
            aux = removeNoInicio(ls);
            if (aux != NULL)
            {
                printf("\n Remoção Realizada com Sucesso");
                mostraContato(aux);
            }
            else
            {
                printf("\nRemocao Não Realizada");
            }
            free(aux);
            break;
        case 5:
            printf("\nRemove no Fim. \n");
            aux = removeNoFim(ls);
            if (aux != NULL)
            {
                printf("\n Remoção Realizada com Sucesso");
                mostraContato(aux);
            }
            else
            {
                printf("\nRemocao Não Realizada");
            }
            free(aux);
            break;
        case 6:
            printf("Remove na Posição, informa a posição:");
            scanf("%d", &posicao);
            fflush(stdin);
            aux = removeNaPosicao(ls, posicao);
            if (aux != NULL)
            {
                printf("\n Remoção Realizada com Sucesso");
                mostraContato(aux);
            }
            else
            {
                printf("\nRemocao Não Realizada");
            }
            free(aux);
            break;
        case 7:
            printf("\nExibe Lista de Contatos \n");
            mostraLista(ls);
            break;
        case 8:
            printf("\nMostra Contato na Posição: \n");
            scanf("%d", &posicao);
            fflush(stdin);
            mostraContatoPosicao(ls, posicao);
            break;
        case 9:
            printf("\n Apagar a Lista !! \n");
            apagaLista(ls);
            break;
        case 10:
            printf("\n Dividir a Lista !! \n");
            printf("Informe a posição inicial:");
            scanf("%d", &posicao_inicial);
            fflush(stdin);
            printf("Informe a posição final:");
            scanf("%d", &posicao_final);
            fflush(stdin);
            mostraLista(divideLista(ls, posicao_inicial, posicao_final));
            break;
        case 0:
            op = -1;
            break;
        default:
            printf("\nOpção Inválida!!\n");
        }
    } while (op > 0);
}
