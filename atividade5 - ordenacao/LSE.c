#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>   // for clock_t, clock(), CLOCKS_PER_SEC
#include <unistd.h> // for sleep()
#include <sys/time.h>

struct timeval stop, start;

typedef struct contato
{
    char nome[20];
    char telefone[30];
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

void inicializaContato(Contato *contato, char nome[], char telefone[], char tipo)
{
    strcpy(contato->nome, nome);
    strcpy(contato->telefone, telefone);
    contato->tipo = tipo;
    contato->proximo = NULL;
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

Contato *pegaMenorContato(LSE *lista)
{
    Contato *menor_contato = lista->primeiro;
    Contato *atual = lista->primeiro;
    Contato *proximo = lista->primeiro;

    while (atual != NULL)
    {

        if (strcmp(atual->nome, menor_contato->nome) < 0) // se o atual vem antes, vai ser o menor
        {
            menor_contato = atual;
        }

        atual = atual->proximo;
    }
    return menor_contato;
}

LSE *OrdenacaoSelecao(LSE *lista)
{
    Contato *menor_contato;
    Contato *primeiro = lista->primeiro;
    Contato *proximo = lista->primeiro;
    // Contato *aux = lista->primeiro->proximo;

    while (primeiro != NULL)
    {
        menor_contato = primeiro;
        while (proximo != NULL)
        {
            if (strcmp(proximo->nome, menor_contato->nome) < 0) // se o primeiro vem antes, vai ser o menor
            {
                menor_contato = proximo;
            }
            proximo = proximo->proximo;
        }
        proximo = primeiro->proximo;
        char nome[20];
        char telefone[30];
        char tipo;
        strcpy(nome, primeiro->nome);
        strcpy(telefone, primeiro->telefone);
        tipo = primeiro->tipo;

        strcpy(primeiro->nome, menor_contato->nome);
        strcpy(primeiro->telefone, menor_contato->telefone);
        primeiro->tipo = menor_contato->tipo;

        strcpy(menor_contato->nome, nome);
        strcpy(menor_contato->telefone, telefone);
        menor_contato->tipo = tipo;

        primeiro = primeiro->proximo;
    }
    return lista;
}

LSE *OrdenacaoInsercao(LSE *lista_origem)
{
    LSE *lista_destino = criaListaLSE();
    Contato *aux_origem = lista_origem->primeiro;

    while (aux_origem != NULL)
    {
        removeNoInicio(lista_origem);
        insereOrdenado(lista_destino, aux_origem);
        aux_origem = aux_origem->proximo;
    }
    return lista_destino;
}

LSE *OrdenacaoBolha(LSE *lista)
{
    Contato *anterior = lista->primeiro;
    Contato *atual = anterior->proximo;
    // Contato *aux = lista->primeiro->proximo;

    while (anterior != NULL)
    {
        atual = anterior->proximo;
        while (atual != NULL)
        {
            if (strcmp(anterior->nome, atual->nome) > 0) // se o anterior vem antes, vai ser o menor
            {
                char nome[20];
                char telefone[30];
                char tipo;
                strcpy(nome, anterior->nome);
                strcpy(telefone, anterior->telefone);
                tipo = anterior->tipo;

                strcpy(anterior->nome, atual->nome);
                strcpy(anterior->telefone, atual->telefone);
                anterior->tipo = atual->tipo;

                strcpy(atual->nome, nome);
                strcpy(atual->telefone, telefone);
                atual->tipo = tipo;
            }
            atual = atual->proximo;
        }
        atual = anterior->proximo;

        anterior = anterior->proximo;
    }
    return lista;
}

void menu2(LSE *listaOriginal)
{

    int op, posicao, id = 1;
    int tam = 50;
    char nome[20];
    Contato *aux;
    LSE *listaSelectionSort = criaListaLSE();

    printf("\n Inserindo Contatos:");
    Contato contatos[50];

    inicializaContato(&contatos[0], "Roberto", "1231", 'o');
    inicializaContato(&contatos[1], "Alberto", "22333", 'f');
    inicializaContato(&contatos[2], "Mara", "33333", 'f');
    inicializaContato(&contatos[3], "Luiz", "44444", 'f');
    inicializaContato(&contatos[4], "Bruno", "1231", 'o');
    inicializaContato(&contatos[5], "Nicole", "1231", 'o');
    inicializaContato(&contatos[6], "Guilherme", "1231", 'o');
    inicializaContato(&contatos[7], "Luciano", "1231", 'o');
    inicializaContato(&contatos[8], "Veiga", "1231", 'o');
    inicializaContato(&contatos[9], "Neymar", "1231", 'o');
    inicializaContato(&contatos[10], "Bridgette", "(656)9629438", 'f');
    inicializaContato(&contatos[11], "Alverta", "(482)3743898", 'f');
    inicializaContato(&contatos[12], "Barbee", "(508)9327299", 'f');
    inicializaContato(&contatos[13], "Atlante", "(965)4922181", 'f');
    inicializaContato(&contatos[14], "Belita", "(146)1863796", 'f');
    inicializaContato(&contatos[15], "Liana", "(267)5781499", 'f');
    inicializaContato(&contatos[16], "Wylie", "(434)4522818", 'm');
    inicializaContato(&contatos[17], "Lucinda", "(266)7909881", 'f');
    inicializaContato(&contatos[18], "Gilberto", "(779)1327261", 'm');
    inicializaContato(&contatos[19], "Berton", "(129)2757780", 'm');
    inicializaContato(&contatos[20], "Town", "(159)5918331", 'm');
    inicializaContato(&contatos[21], "Zechariah", "(221)2485759", 'm');
    inicializaContato(&contatos[22], "Nicolea", "(914)5286390", 'f');
    inicializaContato(&contatos[23], "Maribeth", "(145)6020985", 'f');
    inicializaContato(&contatos[24], "Savina", "(167)7505362", 'f');
    inicializaContato(&contatos[25], "Vivianne", "(258)3220696", 'f');
    inicializaContato(&contatos[26], "Menard", "(765)6957037", 'm');
    inicializaContato(&contatos[27], "Emmett", "(929)4641114", 'm');
    inicializaContato(&contatos[28], "Grantley", "(696)6854161", 'm');
    inicializaContato(&contatos[29], "Pete", "(581)9537135", 'm');
    inicializaContato(&contatos[30], "Clarinda", "(109)5730357", 'f');
    inicializaContato(&contatos[31], "Gibbie", "(868)5742642", 'm');
    inicializaContato(&contatos[32], "Neddy", "(307)6424194", 'm');
    inicializaContato(&contatos[33], "Raeann", "(216)9201572", 'f');
    inicializaContato(&contatos[34], "Sylvan", "(497)9356491", 'm');
    inicializaContato(&contatos[35], "Allsun", "(710)9442635", 'f');
    inicializaContato(&contatos[36], "Brad", "(755)2813236", 'm');
    inicializaContato(&contatos[37], "Shirlene", "(297)3211563", 'f');
    inicializaContato(&contatos[38], "Abbe", "(107)2966402", 'm');
    inicializaContato(&contatos[39], "Lancelot", "(257)8247865", 'm');
    inicializaContato(&contatos[40], "Tymothy", "(701)3215254", 'm');
    inicializaContato(&contatos[41], "Deeanne", "(167)4853138", 'f');
    inicializaContato(&contatos[42], "Enos", "(819)3084367", 'm');
    inicializaContato(&contatos[43], "Menard", "(886)7350054", 'm');
    inicializaContato(&contatos[44], "Wilek", "(966)2934212", 'm');
    inicializaContato(&contatos[45], "Dallon", "(823)5807873", 'm');
    inicializaContato(&contatos[46], "Matteo", "(686)9209185", 'm');
    inicializaContato(&contatos[47], "Fayth", "(173)5065759", 'f');
    inicializaContato(&contatos[48], "Ode", "(846)8659021", 'm');
    inicializaContato(&contatos[49], "Catherin", "(749)6960757", 'f');

    Contato contatos2[50];
    memcpy(contatos2, contatos, 50 * sizeof(Contato));
    Contato contatos3[50];
    memcpy(contatos3, contatos, 50 * sizeof(Contato));
    Contato contatos4[50];
    memcpy(contatos4, contatos, 50 * sizeof(Contato));
    Contato contatos5[50];
    memcpy(contatos5, contatos, 50 * sizeof(Contato));
    Contato contatos6[50];
    memcpy(contatos6, contatos, 50 * sizeof(Contato));

    LSE *listaInsertionSort = criaListaLSE();
    LSE *listaBubbleSort = criaListaLSE();
    LSE *shellSort = criaListaLSE();
    LSE *quickSort = criaListaLSE();

    for (int i = 0; i < tam; i++)
    {
        aux = &contatos[i];
        insereNoInicio(listaOriginal, aux);
        aux = &contatos2[i];
        insereNoInicio(listaSelectionSort, aux);
        aux = &contatos3[i];
        insereNoInicio(listaInsertionSort, aux);
        aux = &contatos4[i];
        insereNoInicio(listaBubbleSort, aux);
        aux = &contatos5[i];
        insereNoInicio(shellSort, aux);
        aux = &contatos6[i];
        insereNoInicio(quickSort, aux);
    }

    printf("\n Contatos inseridos...");

    printf("\n Lista original:");
    mostraLista(listaOriginal);

    printf("\n\n Ordenando Selection Sort:");
    
    double secs = 0;
    gettimeofday(&start, NULL);
    listaSelectionSort = OrdenacaoSelecao(listaSelectionSort);
    printf("\n finalizado Selection Sort:");
    gettimeofday(&stop, NULL);
    secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
    printf("\nO tempo de execucao pela Selection sort foi %f segundos\n", secs);

  
    //mostraLista(listaSelectionSort);

    printf("\n Ordenando Insertion Sort:");
    secs = 0;
    gettimeofday(&start, NULL);
    listaInsertionSort = OrdenacaoSelecao(listaInsertionSort);
    printf("\n finalizado Insertion Sort...");
    gettimeofday(&stop, NULL);
    secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
    printf("\nO tempo de execucao pela Insertion sort foi %f segundos\n", secs);
    //mostraLista(listaInsertionSort);

    printf("\n Ordenando bubble Sort:");
    secs = 0;
    gettimeofday(&start, NULL);
    listaBubbleSort = OrdenacaoSelecao(listaBubbleSort);
    printf("\n finalizado bubble Sort...");
    gettimeofday(&stop, NULL);
    secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
    printf("\nO tempo de execucao pela bubble sort foi %f segundos\n", secs );
    // mostraLista(listaBubbleSort);
}

int main()
{

    // cria a Agenda de Contatos
    LSE *listaOriginal = criaListaLSE();

    // menu(agenda);
    menu2(listaOriginal);
}