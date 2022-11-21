// biblioteca de funções, implementações
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct contato
{
    char nome[20];
    char telefone[20];
    char tipo;
    struct contato *proximo;
} Contato;

typedef struct lse
{
    Contato *primeiro;
    int n_elementos;
} LSE;

/**
 * Aloca memória para uma nova lista
 */
LSE *criaListaLSE()
{

    LSE *nova = (LSE *)malloc(sizeof(LSE));
    nova->primeiro = NULL;
    nova->n_elementos = 0;
    return nova;
}

/**
 * Aloca memória para um novo Elemento (Contato)
 */
Contato *cadastraContato(char nome[], char tel[], char tp)
{
    Contato *novoContato = (Contato *)malloc(sizeof(Contato));
    strcpy(novoContato->nome, nome);
    strcpy(novoContato->telefone, tel);
    novoContato->tipo = tp;
    novoContato->proximo = NULL;
    return novoContato;
}

/**
 * campo para digitar os dados do novo contato
 * invoca a função de alocar memoria para o contato
 */
Contato *criaNovoContato()
{
    char nome[20], telefone[20], tp;
    printf("\nInforme seu nome:");
    scanf("%s", nome);
    printf("\nInforme seu Telefone:");
    scanf("%s", telefone);
    printf("\nInforme F - Familia O - Outros:");
    scanf(" %c", &tp);
    getchar();
    return cadastraContato(nome, telefone, tp);
}

void insereNoInicio(LSE *ls, Contato *novo)
{
    ""
    "insere um novo elemento no inicio da lista"
    "";
    if (ls->primeiro == NULL)
    {
        novo->proximo = NULL;
    }
    else
    {
        novo->proximo = ls->primeiro;
    }
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
        aux->proximo = novo;
        novo->proximo = NULL;
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
        return aux;
    }
    else if (aux->proximo == NULL)
    { // se o segundo é nulo
        ls->primeiro = NULL;
        ls->n_elementos--;
        return aux;
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
        aux->proximo = NULL;
        return aux;
    }
    return aux;
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
        while (aux != NULL)
        {
            mostraContato(aux);
            aux = aux->proximo;
        }
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
    if (aux == NULL)
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
        for (int i = 0; i < pos; i++) // VAI CONTAR A POSICAO ZERO COMO ELEMENTO
        {
            aux = aux->proximo;
        }
        mostraContato(aux);
    }
}

void apagaLista(LSE *ls)
{
    Contato *aux = ls->primeiro;
    while (aux != NULL)
    {
        mostraContato(aux);
        aux = removeNoFim(ls);
    }
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

void insereOrdenado(LSE *ls, Contato *novo)
{
    ""
    "Insere na posição alfabética da Lista"
    "";

    Contato *atual = ls->primeiro;

    if (atual == NULL)
    { // se a lista é vazia ou a posição é negativa
        return insereNoInicio(ls, novo);
    }
    else if (strcmp(novo->nome, atual->nome) <= 0)
    { // se é menor q o primeiro
        return insereNoInicio(ls, novo);
    }

    Contato *proximo = atual->proximo;
    while (proximo != NULL)
    {
        if (strcmp(novo->nome, proximo->nome) < 0)
        {
            goto insert;
        }
        atual = proximo;
        proximo = proximo->proximo;
    }
insert:
    atual->proximo = novo;
    novo->proximo = proximo;
    ls->n_elementos++;
}

void menu2(LSE *listaOriginal)
{
    printf("\n Menu para controlar a Agenda de Contatos:");
    int op, posicao, id = 1;
    int tam = 10;
    char nome[20];
    Contato *aux;
    LSE *listaSelectionSort = criaListaLSE();
    // Aluno pedro2 = *pedro; // passar apenas os dados de pedro
    // insereNoFim(ListaMatematica, &pedro2);
    Contato *contatos[10];
    contatos[0] = cadastraContato("roberto", "1231", 'o');
    contatos[1] = cadastraContato("alberto", "22333", 'f');
    contatos[2] = cadastraContato("mara", "33333", 'f');
    contatos[3] = cadastraContato("luiz", "44444", 'f');
    contatos[4] = cadastraContato("bruno", "1231", 'o');
    contatos[5] = cadastraContato("nicole", "1231", 'o');
    contatos[6] = cadastraContato("guilherme", "1231", 'o');
    contatos[7] = cadastraContato("luciano", "1231", 'o');
    contatos[8] = cadastraContato("veiga", "1231", 'o');
    contatos[9] = cadastraContato("neymar", "1231", 'o');

    for (int i = 0; i < tam; i++)
    {
        aux = contatos[i];
        insereNoInicio(listaOriginal, aux);
        Contato aux2 = *aux;
    }
    for (int i = 10; i > 0; i--)
    {
        aux = contatos[i];
        Contato aux2 = *aux;
        insereNoInicio(listaSelectionSort, &aux2);
    }
    printf("\n Lista original:");
    mostraLista(listaOriginal);
    printf("\n Lista selection:");
    mostraLista(listaSelectionSort);

    /*    do
       {
           // system("clear");
           printf("\n\nInforme uma Opção:");
           printf("\n -- 1 - Mostrar lista original");
           printf("\n -- 2 - Ordenar por Selecao(Selection Sort)");
           printf("\n -- 3 - Ordenar por Insercao(Insertion Sort):");
           printf("\n -- 4 - Ordenar por Selecao e troca(Bubble Sort):");
           printf("\n -- 5 - Ordenar por Insercao de incrementos descrescentes (ShellSort):");
           printf("\n -- 6 - Ordenar por Particionamento(QuickSort)");
           printf("\n -- 7 - Ordenar de todas as formas e comparar os tempos");
           printf("\n -- 0 - Sair do Programa:\n");
           printf("\nInforme sua Opçao:");
           scanf("%d", &op);
           fflush(stdin);

           system("cls");

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

           case 5:

               break;
           case 6:
               printf("\n Apaga Lista \n");
               apagaLista(ls);
               break;
           default:
               printf("\nOpção Inválida!!\n");
           }
       } while (op > 0); */
}

int main()
{

    // cria a Agenda de Contatos
    LSE *listaOriginal = criaListaLSE();

    // menu(agenda);
    menu2(listaOriginal);
}