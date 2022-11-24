// biblioteca de funções, implementações
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    contato->proximo =NULL;
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
    int tam = 50;
    char nome[20];
    Contato *aux;
    LSE *listaSelectionSort = criaListaLSE();
    LSE *insertionSort = criaListaLSE();
    LSE *bubbleSort = criaListaLSE();
    LSE *shellSort = criaListaLSE();
    LSE *quickSort = criaListaLSE();

    Contato contatos[50];
    inicializaContato(&contatos[0] ,"roberto", "1231", "o");
    inicializaContato(&contatos[1], "alberto", "22333", "f");
    inicializaContato(&contatos[2], "mara", "33333", "f");
    inicializaContato(&contatos[3], "luiz", "44444", "f");
    inicializaContato(&contatos[4], "bruno", "1231", "o");
    inicializaContato(&contatos[5], "nicole", "1231", "o");
    inicializaContato(&contatos[6], "guilherme", "1231", "o");
    inicializaContato(&contatos[7], "luciano", "1231", "o");
    inicializaContato(&contatos[8], "veiga", "1231", "o");
    inicializaContato(&contatos[9], "neymar", "1231", "o");
    inicializaContato(&contatos[10], "Bridgette", "(656)9629438", "F");
    inicializaContato(&contatos[11], "Alverta", "(482)3743898", "F");
    inicializaContato(&contatos[12], "Barbee", "(508)9327299", "F");
    inicializaContato(&contatos[13], "Atlante", "(965)4922181", "F");
    inicializaContato(&contatos[14], "Belita", "(146)1863796", "F");
    inicializaContato(&contatos[15], "Liana", "(267)5781499", "F");
    inicializaContato(&contatos[16], "Wylie", "(434)4522818", "M");
    inicializaContato(&contatos[17], "Lucinda", "(266)7909881", "F");
    inicializaContato(&contatos[18], "Gilberto", "(779)1327261", "M");
    inicializaContato(&contatos[19], "Berton", "(129)2757780", "M");
    inicializaContato(&contatos[20], "Town", "(159)5918331", "M");
    inicializaContato(&contatos[21], "Zechariah", "(221)2485759", "M");
    inicializaContato(&contatos[22], "Nicolea", "(914)5286390", "F");
    inicializaContato(&contatos[23], "Maribeth", "(145)6020985", "F");
    inicializaContato(&contatos[24], "Savina", "(167)7505362", "F");
    inicializaContato(&contatos[25], "Vivianne", "(258)3220696", "F");
    inicializaContato(&contatos[26], "Menard", "(765)6957037", "M");
    inicializaContato(&contatos[27], "Emmett", "(929)4641114", "M");
    inicializaContato(&contatos[28], "Grantley", "(696)6854161", "M");
    inicializaContato(&contatos[29], "Pete", "(581)9537135", "M");
    inicializaContato(&contatos[30], "Clarinda", "(109)5730357", "F");
    inicializaContato(&contatos[31], "Gibbie", "(868)5742642", "M");
    inicializaContato(&contatos[32], "Neddy", "(307)6424194", "M");
    inicializaContato(&contatos[33], "Raeann", "(216)9201572", "F");
    inicializaContato(&contatos[34], "Sylvan", "(497)9356491", "M");
    inicializaContato(&contatos[35], "Allsun", "(710)9442635", "F");
    inicializaContato(&contatos[36], "Brad", "(755)2813236", "M");
    inicializaContato(&contatos[37], "Shirlene", "(297)3211563", "F");
    inicializaContato(&contatos[38], "Abbe", "(107)2966402", "M");
    inicializaContato(&contatos[39], "Lancelot", "(257)8247865", "M");
    inicializaContato(&contatos[40], "Tymothy", "(701)3215254", "M");
    inicializaContato(&contatos[41], "Deeanne", "(167)4853138", "F");
    inicializaContato(&contatos[42], "Enos", "(819)3084367", "M");
    inicializaContato(&contatos[43], "Menard", "(886)7350054", "M");
    inicializaContato(&contatos[44], "Wilek", "(966)2934212", "M");
    inicializaContato(&contatos[45], "Dallon", "(823)5807873", "M");
    inicializaContato(&contatos[46], "Matteo", "(686)9209185", "M");
    inicializaContato(&contatos[47], "Fayth", "(173)5065759", "F");
    inicializaContato(&contatos[48], "Ode", "(846)8659021", "M");
    inicializaContato(&contatos[49], "Catherin", "(749)6960757", "F");

    /* Contato contatos2[50];
    memcpy(contatos2, contatos, 50 * sizeof(Contato)); */

    for (int i = 0; i < tam; i++)
    {
        aux = &contatos[i];
        insereNoInicio(listaOriginal, aux);
        //aux = &contatos2[i];
        insereNoInicio(listaSelectionSort, aux);
        
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